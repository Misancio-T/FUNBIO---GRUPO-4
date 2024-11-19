#include <M5Atom.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEClient.h>

float accX, accY, accZ;     // Obtener aceleración en x, y, z

// UUIDs para el servicio y la característica
static BLEUUID serviceUUID("4fafc201-1fb5-459e-8fcc-c5c9c331914b");
static BLEUUID charUUID("beb5483e-36e1-4688-b7f5-ea07361b26a8");

bool conectado = false;
BLEAddress *pServerAddress;
BLEClient *pClient = nullptr;
BLERemoteCharacteristic *pRemoteCharacteristic = nullptr;

void setup() {
  M5.begin(true, false, true);  // Iniciar M5Atom con IMU habilitado, no Serial y con LED display
  M5.IMU.Init();                // Inicializar el sensor IMU (MPU6886)
  Serial.begin(115200);

  Serial.println("Iniciando el M5 Atom Matrix como maestro BLE...");
  BLEDevice::init("");

  // Escaneo de dispositivos y búsqueda del esclavo
  BLEScan* pBLEScan = BLEDevice::getScan();
  pBLEScan->setActiveScan(true);
  BLEScanResults* foundDevices = pBLEScan->start(5);  // Asignamos directamente como puntero

  for (int i = 0; i < foundDevices->getCount(); i++) {
    BLEAdvertisedDevice device = foundDevices->getDevice(i);
    if (device.haveServiceUUID() && device.isAdvertisingService(serviceUUID)) {
      Serial.println("Dispositivo esclavo encontrado!");
      pServerAddress = new BLEAddress(device.getAddress());
      conectado = conectarDispositivo();
      break;
    }
  }
  pBLEScan->clearResults();
}

bool conectarDispositivo() {
  pClient = BLEDevice::createClient();
  pClient->connect(*pServerAddress);
  Serial.println("Conectado al esclavo!");

  BLERemoteService *pRemoteService = pClient->getService(serviceUUID);
  if (pRemoteService == nullptr) {
    Serial.println("No se pudo encontrar el servicio.");
    return false;
  }
  pRemoteCharacteristic = pRemoteService->getCharacteristic(charUUID);
  if (pRemoteCharacteristic == nullptr) {
    Serial.println("No se pudo encontrar la característica.");
    return false;
  }
  return true;
}

void loop() {
  // Leer los valores de aceleración
  M5.IMU.getAccelData(&accX, &accY, &accZ);

  // Calcular el ángulo de inclinación en el eje Y (en grados)
  float angleY = atan2(accY, accZ) * 180 / PI;

  static String ultimoMensaje = ""; // Para evitar enviar mensajes repetidos

  if (conectado) {
    String mensaje; // Variable para almacenar el mensaje a enviar
    if (angleY > 130 && angleY < 150) {
      M5.dis.fillpix(0x00FF00);  // Verde
      mensaje = "pie inclinado";
    } else {
      M5.dis.fillpix(0xFF0000);  // Rojo
      mensaje = "pie plano";
    }

    // Enviar mensaje si cambió desde el último envío
    if (mensaje != ultimoMensaje) {
      Serial.println("Enviando mensaje al esclavo: " + mensaje);
      pRemoteCharacteristic->writeValue(mensaje.c_str());
      ultimoMensaje = mensaje;
    }

    delay(500); // Pequeña pausa para evitar saturar el BLE
  } else {
    Serial.println("Desconectado. Reintentando conexión...");
    conectado = conectarDispositivo();
    delay(5000);  // Reintento cada 5 segundos
  }
}

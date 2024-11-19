#include <M5Atom.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEClient.h>

// UUIDs para el servicio y la característica
static BLEUUID serviceUUID("4fafc201-1fb5-459e-8fcc-c5c9c331914b");
static BLEUUID charUUID("beb5483e-36e1-4688-b7f5-ea07361b26a8");

bool conectado = false;
BLEAddress *pServerAddress;

void setup() {
  M5.begin();
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
  BLEClient *pClient = BLEDevice::createClient();
  pClient->connect(*pServerAddress);
  Serial.println("Conectado al esclavo!");

  BLERemoteService *pRemoteService = pClient->getService(serviceUUID);
  if (pRemoteService == nullptr) {
    Serial.println("No se pudo encontrar el servicio.");
    return false;
  }
  BLERemoteCharacteristic *pRemoteCharacteristic = pRemoteService->getCharacteristic(charUUID);
  if (pRemoteCharacteristic == nullptr) {
    Serial.println("No se pudo encontrar la característica.");
    return false;
  }
  pRemoteCharacteristic->writeValue("Hola desde el M5 Atom Matrix");
  return true;
}

void loop() {
  if (conectado) {
    Serial.println("Enviando mensaje al esclavo...");
    delay(1000);
  } else {
    Serial.println("Desconectado. Reintentando conexión...");
    conectado = conectarDispositivo();
    delay(5000);  // Reintento cada 5 segundos
  }
}

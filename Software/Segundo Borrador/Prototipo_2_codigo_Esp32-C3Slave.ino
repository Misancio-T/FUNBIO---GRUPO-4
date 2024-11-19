#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

// Verifica si el soporte de BLE está activado
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth no está activado. Actívalo en la configuración del proyecto.
#endif

// UUIDs para el servicio y la característica
#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

BLECharacteristic *pCharacteristic;

void setup() {
  Serial.begin(115200);
  Serial.println("Iniciando el ESP32-C3 como esclavo BLE...");

  // Inicializar BLE
  BLEDevice::init("ESP32_C3_Slave");

  // Crear el servidor y servicio BLE
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Crear la característica
  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_READ |
                      BLECharacteristic::PROPERTY_WRITE
                    );

  // Valor inicial de la característica
  pCharacteristic->setValue("Esperando datos...");
  pService->start();

  // Comenzar la publicidad
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->start();

  Serial.println("ESP32-C3 esclavo listo y en espera de conexión");

  // Configurar el pin 5 como salida
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW); // Pin desactivado por defecto
}

void loop() {
  // Verifica si el maestro ha enviado datos
  std::string valorRecibido = pCharacteristic->getValue();
  if (!valorRecibido.empty()) { // Verifica si el valor no está vacío
    Serial.print("Datos recibidos: ");
    Serial.println(valorRecibido.c_str());

    // Activar o desactivar el pin 5 según el mensaje recibido
    if (valorRecibido == "pie inclinado") {
      digitalWrite(5, HIGH); // Activar el pin
      Serial.println("Pin 5 activado.");
    } else if (valorRecibido == "pie plano") {
      digitalWrite(5, LOW); // Desactivar el pin
      Serial.println("Pin 5 desactivado.");
    }

    // Limpia el valor después de procesarlo
    pCharacteristic->setValue("");
  }
  delay(500); // Pequeño retraso para evitar lecturas continuas innecesarias
}

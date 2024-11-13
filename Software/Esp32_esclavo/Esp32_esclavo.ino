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

  BLEDevice::init("ESP32_C3_Slave");

  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);

  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_READ |
                      BLECharacteristic::PROPERTY_WRITE
                    );

  pCharacteristic->setValue("Esperando datos...");
  pService->start();

  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->start();

  Serial.println("ESP32-C3 esclavo listo y en espera de conexión");
}

void loop() {
  // Verifica si el maestro ha enviado datos
  if (pCharacteristic->getValue() != "") {
    Serial.print("Datos recibidos: ");
    Serial.println(pCharacteristic->getValue().c_str());
    pCharacteristic->setValue("");  // Limpia el valor después de leerlo
  }
  delay(500);
}

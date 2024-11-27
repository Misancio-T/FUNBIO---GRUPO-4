#include <M5Atom.h>
#include <FastLED.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEClient.h>

#define NUM_LEDS 25
#define DATA_PIN 27

CRGB leds[NUM_LEDS];

// Variables del IMU y ángulos
float baseAngleY = 0;
float lowerLimit1, upperLimit1;
float lowerLimit2, upperLimit2;
float lowerLimit4, upperLimit4;
float deadZoneLower, deadZoneUpper;
int currentRangeState = -1;
bool inDeadZone = false;

// Variables para Bluetooth
static BLEUUID serviceUUID("4fafc201-1fb5-459e-8fcc-c5c9c331914b");
static BLEUUID charUUID("beb5483e-36e1-4688-b7f5-ea07361b26a8");
bool conectado = false;
BLEAddress *pServerAddress;
BLEClient *pClient = nullptr;
BLERemoteCharacteristic *pRemoteCharacteristic = nullptr;

void setup() {
    M5.begin(true, false, true);
    FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
    FastLED.clear();
    FastLED.setBrightness(255);

    Serial.begin(115200);

    // Inicialización del IMU
    if (M5.IMU.Init() != 0) {
        Serial.println("Error al inicializar el IMU");
    } else {
        Serial.println("IMU inicializado correctamente");
    }

    // Configuración de Bluetooth
    Serial.println("Iniciando BLE...");
    BLEDevice::init("");
    BLEScan* pBLEScan = BLEDevice::getScan();
    pBLEScan->setActiveScan(true);
    BLEScanResults* foundDevices = pBLEScan->start(5);

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

void setAllLeds(CRGB color) {
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = color;
    }
    FastLED.show();
}

void enviarMensaje(String mensaje) {
    if (conectado) {
        Serial.println("Enviando mensaje al esclavo: " + mensaje);
        pRemoteCharacteristic->writeValue(mensaje.c_str());
    } else {
        Serial.println("Desconectado. Reintentando conexión...");
        conectado = conectarDispositivo();
    }
}

void loop() {
    M5.update();

    if (M5.Btn.wasPressed()) {
        float accelX, accelY, accelZ;
        M5.IMU.getAccelData(&accelX, &accelY, &accelZ);
        baseAngleY = atan2(accelY, accelZ) * 180.0 / PI;

        lowerLimit1 = baseAngleY - 5.0;
        upperLimit1 = baseAngleY + 5.0;
        lowerLimit2 = lowerLimit1 - 30.0;
        upperLimit2 = lowerLimit1;
        lowerLimit4 = upperLimit1;
        upperLimit4 = upperLimit1 + 15.0;
        deadZoneLower = baseAngleY - 30.0;
        deadZoneUpper = baseAngleY + 15.0;

        Serial.println("Rangos actualizados:");
        Serial.printf("Rango 1: [%.2f, %.2f]\n", lowerLimit1, upperLimit1);
        Serial.printf("Rango 2: [%.2f, %.2f]\n", lowerLimit2, upperLimit2);
        Serial.printf("Rango 4: [%.2f, %.2f]\n", lowerLimit4, upperLimit4);
        Serial.printf("Zona Muerta: [%.2f, %.2f]\n", deadZoneLower, deadZoneUpper);
    }

    float accelX, accelY, accelZ;
    M5.IMU.getAccelData(&accelX, &accelY, &accelZ);
    float currentAngleY = atan2(accelY, accelZ) * 180.0 / PI;

    int newRangeState = -1;
    if (!inDeadZone && currentAngleY < deadZoneLower) {
        inDeadZone = true;
        enviarMensaje("Zm");
        setAllLeds(CRGB::Purple);
    } else if (inDeadZone && currentAngleY > deadZoneUpper) {
        inDeadZone = false;
    }

    if (!inDeadZone) {
        if (currentAngleY >= lowerLimit1 && currentAngleY < upperLimit1) {
            newRangeState = 1;
        } else if (currentAngleY >= lowerLimit2 && currentAngleY < upperLimit2) {
            newRangeState = 2;
        } else if (currentAngleY >= lowerLimit4 && currentAngleY <= upperLimit4) {
            newRangeState = 4;
        }
    }

    if (newRangeState != currentRangeState) {
        currentRangeState = newRangeState;
        if (currentRangeState == 1) {
            enviarMensaje("P0");
            setAllLeds(CRGB::Green);
        } else if (currentRangeState == 2) {
            enviarMensaje("P1");
            setAllLeds(CRGB::Yellow);
        } else if (currentRangeState == 4) {
            enviarMensaje("P2");
            setAllLeds(CRGB::Blue);
        }
    }

    delay(10);
}
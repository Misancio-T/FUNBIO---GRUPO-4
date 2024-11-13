#include <M5Atom.h>

float baseAngleY = 0;            // Almacena el ángulo inicial en el eje Y
unsigned long lastUpdateTime = 0; // Guarda el tiempo de la última actualización

void setup() {
  M5.begin(true, false, true);    // Inicia el Atom Matrix sin activar LEDs ni pantalla
  M5.dis.clear();                 // Asegura que los LEDs estén apagados al inicio
  Serial.begin(115200);           // Inicia la comunicación serial
  
  // Inicializa el IMU (Unidad de Medición Inercial) y verifica si se inicializó correctamente
  if (M5.IMU.Init() != 0) {
    Serial.println("Error al inicializar el IMU");
  } else {
    Serial.println("IMU inicializado correctamente");
  }
}

void loop() {
  M5.update(); // Actualiza el estado de los botones

  // Verifica si el botón fue mantenido presionado por al menos 3 segundos (3000 ms)
  // y si han pasado al menos 3 segundos desde la última actualización
  if (M5.Btn.pressedFor(3000) && (millis() - lastUpdateTime >= 3000)) {  
    float accelX, accelY, accelZ;
    // Obtiene la aceleración en X, Y y Z
    M5.IMU.getAccelData(&accelX, &accelY, &accelZ);

    // Calcula el ángulo en el eje Y en grados
    baseAngleY = atan2(accelY, accelZ) * 180.0 / PI;
    
    // Crea el rango de ±4 grados
    float lowerLimit = baseAngleY - 4.0;
    float upperLimit = baseAngleY + 4.0;

    // Imprime el rango en el monitor serial
    Serial.print("Rango actualizado a: ");
    Serial.print(lowerLimit);
    Serial.print(" a ");
    Serial.print(upperLimit);
    Serial.println(" grados");

    // Actualiza el tiempo de la última actualización
    lastUpdateTime = millis();
  }

  delay(10); // Pequeña demora para estabilidad del loop
}

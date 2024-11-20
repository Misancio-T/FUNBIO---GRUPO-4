# Integración Hardware - Software - Manufactura Digital

## Introducción y Contextualización del Prototipo

### Descripción breve del Proyecto
El objetivo principal de este prototipo es desarrollar un sistema de retroalimentación sensorial artificial que mejore la propiocepción en personas con disminución de la percepción corporal,  se centra en proporcionar a estos pacientes un sistema que pueda suplir la retroalimentación sensorial pérdida y ayudarles a recuperar, en la medida de lo posible, la capacidad de moverse de forma segura y confiada.

Este sistema utiliza un dispositivo que mide la posición y el movimiento durante las fases de la marcha, ya sea al caminar o al estar de pie, y envía señales a unas bandas vibratorias que el usuario lleva puestas. Estas bandas vibran en tiempo real para proporcionar una retroalimentación táctil inmediata, alertando al usuario sobre su posición y movimiento.

### Problemática abordada

Este prototipo se centra en proporcionar a estos pacientes un sistema que pueda suplir la retroalimentación sensorial pérdida y ayudarles a recuperar, en la medida de lo posible, la capacidad de moverse de forma segura y confiada, todo esto a través de un sistema de feedback sensorial artificial que restaure la percepción corporal mediante retroalimentación táctil, promoviendo una rehabilitación más rápida y efectiva y aumentando la seguridad y el bienestar del paciente en su día a día.

La necesidad que motiva este proyecto es mejorar la calidad de vida de personas con lesiones medulares completas de tipo A que han perdido la capacidad de recibir retroalimentación sensorial y de controlar su motricidad mediante un dispositivo en forma de una cajita pequeña que va ajustada a una parte estratégica del pie. Esto nos ayudará a poder restaurar la pérdida de sensibilidad de nuestro paciente al momento de realizar bipedestación o marcha.  Esta pérdida de sensibilidad y control afecta significativamente su capacidad de moverse, caminar y mantenerse de pie de manera autónoma, lo que los hace depender de dispositivos de asistencia.

### Objetivos de la fase de integración

Lo que se espera al lograr integrar los componentes que forman parte de nuestra propuesta es asegurarnos de que los componentes del dispositivo (sensores, procesadores, baterías, etc) trabajen juntos de manera sincronizada para medir y registrar la proximidad del pie con el piso con precisión. A la vez, esperamos lograr que se logre comprobar los datos que los sensores envían para medir hacer las mediciones respecto a las pisadas del paciente para poder corregir errores de lectura. Finalmente, deseamos evaluar que el dispositivo sea compatible con las condiciones reales de uso, comprobando que la integración de sus componentes le permita operar correctamente en entornos de prueba similares a su aplicación final.

## Componentes del Prototipo

### Lista de componentes principales

**Componentes en la parte del pie**

- **Batería 3.7V, 720 mAh Li-Po:** Actúa como la fuente de energía para esta sección del prototipo, suministrando alimentación al Atom Matrix.
- **LiPo Rider Plus:** Este módulo sirve como intermediario entre la batería y el Atom Matrix, facilitando la carga de la batería a través de un puerto USB tipo C.
- **Atom Matrix:** Es el "cerebro" del prototipo. Integra un acelerómetro MPU-6886 que captura datos en los ejes X, Y y Z en tiempo real, así como un ESP32 PICO, un microcontrolador compacto utilizado para enviar los datos por medio de Bluetooth. Además, cuenta con una pantalla de luces LED que puede utilizarse de distintas maneras, como un indicador visual adicional, proporcionando así feedback tanto para el paciente como para el terapeuta.

**Componentes en la parte del brazo**

- **Motores Vibradores Tipo Moneda:** Similar a los que se usan en teléfonos móviles, estos motores se emplea para proporcionar retroalimentación sensorial en el brazo del usuario.
- **Batería 3.7V, 720 mAh Li-Po:** Actúa como la fuente de energía en esta sección del prototipo, suministrando alimentación al ESP32 Super Mini.
- **Módulo TP4056:** Es una versión más sencilla que el LiPo Rider Plus y permite cargar la batería Li-Po y alimentar el ESP32 Super Mini.

### Interacción entre componentes

Los componentes principales que interactúan en este prototipo son el Atom Matrix, que incluye un ESP32 PICO, y el ESP32 Super Mini ubicado en el brazo. La comunicación entre ambos se realiza mediante programación Bluetooth, estableciendo un sistema maestro-esclavo para la transmisión y recepción de datos entre los dispositivos.

### Diagrama de integración

<p align="center">
<img src="https://github.com/Misancio-T/FUNBIO---GRUPO-4/blob/main/Entregables/Resources/Imagenes/FunBio_imagen_28.png?raw=true" alt="Esquema Electrónico" width="900">
</p>

## Proceso de Integración

### Plan Inicial de Integración

**- Paso 1:** Desarrollo del Sistema en el Pie

Configuración del ATOM PICO ESP32 para medir ángulos y convertirlos en grados de inclinación que al tener incluído el microcontrolador podemos visualizar los datos en tiempo real mediante un monitor serie con el objetivo de tener mediciones precisas y consistentes.

Para la programación del microcontrolador (pie) creamos un programa para leer datos del sensor y transmitirlos por Bluetooth al dispositivo esclavo.

Se prueban datos simulados desde el sensor a una laptop.

**- Paso 2: Desarrollo del Sistema en el Brazo (dispositivo esclavo)**

Programar el receptor Bluetooth para recibir datos enviados por el módulo del pie.  Posteriormente integrar y probar el motor de vibración para generar pulsos en función de los datos.  

Se probó simulando la recepción de ángulos y activar las luces led, momentáneas, correctamente.

**- Paso 3: Comunicación Bluetooth**

Configurar el emparejamiento del módulo transmisor del pie con el receptor del brazo para verificar la estabilidad y velocidad de la conexión Bluetooth

### Pruebas Intermedias

**1. Prueba unitaria del sensor:**

   Confirmar que el sensor mide correctamente los ángulos de inclinación.  

**2. Prueba de transmisión Bluetooth:**  
   
   Evaluar la precisión y latencia de los datos enviados desde el pie al brazo.  

**3. Prueba del motor de vibración:**  
   
   Ajustar la intensidad y duración de las vibraciones para que sean perceptibles sin ser incómodas.  

### Objetivos

1. Obtener mediciones angulares precisas del pie durante diferentes pisadas.

2. Lograr una transmisión de datos Bluetooth con baja latencia y sin interrupciones.

3. Generar una retroalimentación háptica en el brazo que sea intuitiva y fácil de interpretar.

4. Implementar un diseño ergonómico y funcional para ambos módulos.

### Desafíos y ajustes realizados

**1. Calibración del Sensor de Ángulo**

- Desafio

La lectura del sensor era inconsistente debido a interferencias de movimiento no deseado y ruido en los datos, también el cuestionamiento de medida entre el ángulo o la altura.

- Ajuste Realizado

Ajuste de los valores iniciales mediante un proceso de calibración manual para establecer un punto de referencia (offset) y decisión de medida a angulo de giro..

### Revisión de compatibilidad y sincronización

<p align="center">
<img src="https://github.com/Misancio-T/FUNBIO---GRUPO-4/blob/main/Entregables/Resources/Imagenes/FunBio_imagen_49.png?raw=true" alt="Revision de componentes" width="600">
</p>

## Pruebas y Verificación

### Descripción de pruebas funcionales

Los microcontroladores usados requieren más programación, para ello se usaron ejemplos presentes en Arduino y luego de comprobar su funcionamiento se procedió a probar el de componentes, en el caso de los motores vibradores para comprobar su funcionamiento se conecto el cable positivo al terminal de 3.3v de uno de los microcontroladores y el cable negativo a GND, con ello probamos que todos los componentes son funcionales y están listos para el ensamblaje en conjunto.

### Resultados de pruebas

Las primeras pruebas se esperaba lograr la activación del motor con un pin del microcontrolador pero estas pruebas resultaron fallidas debido a que se intentó usar un protoboard para realizar las conexiones del esp32 C3 con el motor vibrador y no se podía porque el esp32 no se podía conectar bien al protoboard, para ello fue necesario soldar los componentes al esp32 para comprobar su funcionamiento, otro contratiempo fue que los motores vibradores tienen un cable muy delgado que complica las conexiones además de el soldar el motor al resto de componentes, para ello fue necesario realizar un intercambio de cables en el motor por uno más gruesos para así trabajar de una mejor manera.

### Evaluación de desempeño

Nuestro prototipo consta de 2 partes, un dispositivo que irá instalado en el pie y otro que irá instalado en el brazo, debido a que usamos un atom matrix en el dispositivo del pie, ese prototipo cumple con el objetivo inicial debido a que ya detecta el movimiento y cumple su parte en la medición, el dispositivo en el brazo es más complejo por la conexión de distintos componentes, pero ya esta en la ultima fase, y teoricamente tambien cumplira los objetivos planteados.

## Conclusiones y Próximos Pasos

### Resumen de logros

**Desarrollo del sistema en el pie:**

- Configuración exitosa del ATOM ESP32 para medir y transmitir los datos angulares en tiempo real mediante Bluetooth permitiendo la presión y latencia de los datos enviados, esto se logró por el proceso de calibración manual para establecer un punto de referencia
- Integración y prueba, logrando mediciones concretas de inclinación en los ejes 
- Diseño funcional que incluye la pantalla LED del ATOM para retroalimentación visual al paciente y terapeuta
- Cumplimiento del objetivo inicial, mide el movimiento
- Prueba de la recepción de ángulos y activar las luces led momentáneamente exitosa

**Desarrollo del sistema del brazo:**

- Programación del receptor Bluetooth para recibir datos enviados desdes el dispositivo del pie 
- Integración del motor vibrador exitosamente, sirviendo como mecanismo de retroalimentación háptica, genera los pulso en función de los datos enviados, se encuentra en la última fase y se espera que cumpla los objetivos 
- Ajustes en la intensidad y duración de las vibraciones para asegurar una experiencia cómoda y efectiva para el paciente. 

**Integración de comunicación Bluetooth:**

- Establecimiento exitoso de un sistema maestro-esclavo entre los módulos del pie y del brazo, con transmisión de datos luida y de baja latencia.

**Prueba de componentes:**

- Verificación de las baterías, sensores, motores vibradores y módulos de Bluetooth
- Se logró solucionar los problemas de conexión mediante la soldadura de los componentes y sustitución de cables para mejorar la estabilidad. 

### Aspectos por mejorar: Discutir qué problemas aún existen o qué componentes requieren ajuste adicional

1. Calibración y estabilidad del sensor de ángulos

Aunque el sensor ya puede medir ángulos, para obtener mejor precisión de los datos es necesario optimizar su calibración para garantizar lecturas más precisas, sobre todo que responda a las condiciones dinámicas del movimiento del paciente. 

2. Sincronización entre los componentes

Aunque el sistema maestro-esclavo entre ambos componentes es exitoso, se podrían detectar ligeros retrasos en la transmisión de los datos.

3. Duración de la batería:

La autonomía actual de la baterías puede ser insuficiente para que se prolongue por toda las sesiones de rehabilitación

4. Pruebas en condiciones reales

Hasta la fecha no hemos podido probar nuestro componentes en situaciones reales para los casos de pacientes en los que nos enfocamos, por ahora solo se está haciendo simulaciones, esperamos realizar pruebas en condiciones más cercanas a nuestros pacientes para identificar problemas y posibles limitaciones con el objetivo de la mejora y avance de nuestro proyecto. 

Aunque nuestro prototipo ha alcanzado un nivel satisfactorio a nuestras posibilidades, estos aspectos se pueden mejorar. Se espera que con las mejoras más adelante se puedan realizar las mejoras necesarias para la calibración, precisión, y duración de la batería. Si se logra solucionar este dispositivo será más preciso y confiable, garantizando así el objetivo y funcionamiento de Uyarai 

### Siguientes fases del desarrollo: Describir los pasos próximos y cómo se enfocarán en mejoras o implementaciones futuras

Las siguientes fases del desarrollo de nuestro prototipo se enfocarán en resolver los problemas técnicos de los componentes, se espera optimizar el diseño para que sea más accesible a todos los pacientes. Se espera además extender la funcionalidades del dispositivo para mejorar la experiencia entre el paciente y terapeuta Además se espera avanzar a la etapa de aprobación y pruebas clínicas. Esto permitirá que el prototipo evolucione hacia una solución más confiable para mejorar de esta forma la calidad de la vida de las personas con lesiones medulares. 

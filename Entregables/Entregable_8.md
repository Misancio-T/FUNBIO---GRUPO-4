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

**Falta actualizar el diagrama electrico**

## Proceso de Integración

asdasdas

## Pruebas y Verificación

### Descripción de pruebas funcionales

Los microcontroladores usados requieren más programación, para ello se usaron ejemplos presentes en Arduino y luego de comprobar su funcionamiento se procedió a probar el de componentes, en el caso de los motores vibradores para comprobar su funcionamiento se conecto el cable positivo al terminal de 3.3v de uno de los microcontroladores y el cable negativo a GND, con ello probamos que todos los componentes son funcionales y están listos para el ensamblaje en conjunto.

### Resultados de pruebas

Las primeras pruebas se esperaba lograr la activación del motor con un pin del microcontrolador pero estas pruebas resultaron fallidas debido a que se intentó usar un protoboard para realizar las conexiones del esp32 C3 con el motor vibrador y no se podía porque el esp32 no se podía conectar bien al protoboard, para ello fue necesario soldar los componentes al esp32 para comprobar su funcionamiento, otro contratiempo fue que los motores vibradores tienen un cable muy delgado que complica las conexiones además de el soldar el motor al resto de componentes, para ello fue necesario realizar un intercambio de cables en el motor por uno más gruesos para así trabajar de una mejor manera.

### Evaluación de desempeño

Nuestro prototipo consta de 2 partes, un dispositivo que irá instalado en el pie y otro que irá instalado en el brazo, debido a que usamos un atom matrix en el dispositivo del pie, ese prototipo cumple con el objetivo inicial debido a que ya detecta el movimiento y cumple su parte en la medición, el dispositivo en el brazo es más complejo por la conexión de distintos componentes, pero ya esta en la ultima fase, y teoricamente tambien cumplira los objetivos planteados.

## Conclusiones y Próximos Pasos

asdasdasd
# Iteración y Reporte de Pruebas

## Iteración

### Hardware Electronico

#### Diseño esquemático del circuito (corregido)

<p align="center">
<img src="https://github.com/Misancio-T/FUNBIO---GRUPO-4/blob/main/Entregables/Resources/Imagenes/FunBio_imagen_56.png?raw=true" alt="Esquema Electrónico (corregido)" width="900">
</p>

#### Ejecucion del codigo arduino

**Codigo en Arduino para probar los componentes**

<p align="center">
<img src="https://github.com/Misancio-T/FUNBIO---GRUPO-4/blob/main/Entregables/Resources/Imagenes/FunBio_imagen_45.png?raw=true" alt="Codigo de Programacion" width="600">
</p>

#### Prototipado electrónico

<p align="center">
<img src="https://github.com/Misancio-T/FUNBIO---GRUPO-4/blob/main/Entregables/Resources/Imagenes/FunBio_imagen_39.png?raw=true" alt="Esquema Electrónico" width="900">
</p>

### Diagrama de flujo del codigo final

Para hacer una introduccion al sofware vamos a presentar nuestro **Diagrama de Flujo de Datos** de nuestro codigo

Dispositivo de Medicion

<p align="center">
<img src="https://github.com/Misancio-T/FUNBIO---GRUPO-4/blob/main/Entregables/Resources/Imagenes/FunBio_imagen_57.jpg?raw=true" alt="DFD" width="600">
</p>

Dispositivo sensorial

<p align="center">
<img src="https://github.com/Misancio-T/FUNBIO---GRUPO-4/blob/main/Entregables/Resources/Imagenes/FunBio_imagen_58.jpg?raw=true" alt="DFD" width="600">
</p>

### Impresión 3D

#### Modelos 3d Aprobados

- Dispositivo del Pie

<p align="center">
<img src="https://github.com/Misancio-T/FUNBIO---GRUPO-4/blob/main/Entregables/Resources/Imagenes/FunBio_imagen_42.png?raw=true" alt="Dispositivo del Pie" width="900">
</p>

- Dispositivo del Brazo

<p align="center">
<img src="https://github.com/Misancio-T/FUNBIO---GRUPO-4/blob/main/Entregables/Resources/Imagenes/FunBio_imagen_43.png?raw=true" alt="Dispositivo del Brazo" width="900">
</p>

#### Modelado digital del prototipo

- Dispositivo del Pie

<p align="center">
<img src="https://github.com/Misancio-T/FUNBIO---GRUPO-4/blob/main/Entregables/Resources/Imagenes/FunBio_imagen_40.png?raw=true" alt="Dispositivo del Pie" width="900">
</p>

- Dispositivo del Brazo

<p align="center">
<img src="https://github.com/Misancio-T/FUNBIO---GRUPO-4/blob/main/Entregables/Resources/Imagenes/FunBio_imagen_41.png?raw=true" alt="Dispositivo del Brazo" width="900">
</p>

## Reporte de pruebas, retos y limitación de los componentes

### Evaluar funcionalidad y usabilidad por componente

#### Para los componentes que se utilizaran para las bandas en los brazos:

- **Batería de litio:** la batería de litio proporciona la energía necesaria para el sistema, asegurando que la retroalimentación sensorial esté disponible de manera constante. La capacidad debería ser suficiente para mantener el sistema activo durante el tiempo necesario para sesión de rehabilitación sin interrupciones.
- **Lipo Rider Plus:** Este modulo de carga es ideal para facilitar la conexión entre la batería y el sistema EPS 32. Ofrece una interfaz a carga de un puerto USB, asegura una administración de energía eficiente y protege el sistema contra picos de voltaje. Su tamaño es compacto y su diseño modular aumentan la usabilidad, ya que permite que el dispositivo sea recargado fácilmente.
- **Motores vibradores:** Los motores son fundamentales para proporcionar la retroalimentación háptica que el usuario necesita para sentir las pisadas. Colocados estratégicamente en puntos claves de las bandas, pueden dar señales sensoriales claras en función de la presión detectada en los pies. Su respuesta rápida a través de bluetooth al sentir las pisadas además de su bajo consumo de energía los hacen adecuados para este tipo de retroalimentación.
- **ESP32:** este microcontrolador es esencial para procesar los datos del sistema y controlar de manera eficiente el momento de los motores vibradores en tiempo real. Su conectividad WIFI y Bluetooth permite que la comunicación inalámbrica entre nuestro dispositivo y las bandas en los brazos sean efectivas. La flexibilidad y el bajo consumo del ESP32 son ventajas claves, soportan la batería y facilitan el envío y recepción de señales de manera eficiente.

#### Para el dispositivo situado en el pie

- **Atom MPU 6886 ESP32:** Este microcontrolador integrado con un sensor de movimiento (MPU 6886) es fundamental para medir la orientación, aceleración y posibles cambios de posición del pie. Su capacidad para procesar los datos permite una rápida interpretación de los estos para que el sistema proporcione retroalimentación en tiempo real. Además la conectividad WIFI y Bluetooth facilita la comunicación inalámbrica con los dispositivos en las bandas. Su tamaño es compacto, ideal para integrarse en nuestro prototipo, manteniendo la estética en el producto y priorizando la comodidad del usuario.
- **Lipo Rider:** Este módulo de carga permite gestionar correctamente la energía entre la batería y el atom ESP32. Ofrece una interconexión de carga USB, esta facilita el recargo sin necesidad de desmontar el dispositivo del pie. Protege contra sobrecargas aumentando así la vida útil de la batería y garantizando que el dispositivo esté listo para cada sesión.
- **Bateria Lipo de 3.7 V 720 mAh:** Esta batería proporciona la energía necesaria para el sistema del dispositivo del pie, ofreciendo estabilidad entre capacidad y tamaño para no afectar la capacidad de uso del dispositivo, por esto es importante controlar el uso, ya que una independencia prolongada es clave para la funcionalidad del dispositivo en la rehabilitación diaria.

### Identificar problemas y realizar mejora antes de la implementación del prototipo

#### Identificación de problemas y recomendaciones de mejora antes de proceder con la implementación del prototipo:

- **Problema 1:** Establecer una conexión en modo esclavo entre el dispositivo Atom y el ESP32. Debemos garantizar un enlace estable y funcional.
- **Problema 2:** Es posible que en el modelo 3D de la sección correspondiente al pie necesite un pequeño cambio que facilite la conectividad del Lipo Rider Plus y el Atom Matrix.
- **Problema 3:** Otra posible área de mejora en el modelo 3D de la sección del pie es el anclaje del interruptor de encendido y apagado. Una revisión en el diseño del anclaje podría proporcionar un mejor ajuste y estabilidad, previniendo movimientos no deseados durante el uso y brindar un acceso más práctico al switch.
- **Problema 4:** Refinar el código actual. Necesitamos garantizar que la medición de los datos en tiempo real por parte del Atom Matrix sea confiable y estable, y de esta manera enviar la información del Atom al ESP32.

**Aspectos a mejorar:** Actualmente, la duración de la batería en modo de uso continuo es de aproximadamente dos horas, lo cual podría ser insuficiente para ciertos escenarios de uso. Para mejorar ello podríamos usar una batería de mayor amperaje para extender la autonomía o, alternativamente, implementar un modo de suspensión en el código que permita reducir el consumo energético cuando el dispositivo no esté en uso activo.

### Identificar retos y limitaciones

<p align="center">
<img src="https://github.com/Misancio-T/FUNBIO---GRUPO-4/blob/main/Entregables/Resources/Imagenes/FunBio_imagen_44.png?raw=true" alt="Identificar retos y limitaciones" width="700">
</p>

### Propuesta de soluciones

<p align="center">
<img src="https://github.com/Misancio-T/FUNBIO---GRUPO-4/blob/main/Entregables/Resources/Imagenes/FunBio_imagen_47.png?raw=true" alt="Identificar retos y limitaciones" width="700">
</p>

## Avances de esta semana

En esta semana ya se mandaron las piezas a imprimir y con los componentes la pieza se ve asi

<p align="center">
<img src="https://github.com/Misancio-T/FUNBIO---GRUPO-4/blob/main/Entregables/Resources/Imagenes/FunBio_imagen_48.jpg?raw=true" alt="Identificar retos y limitaciones" width="700">
</p>

Tambien se avanzo con la electronica en la otra pieza del Dispositivo, el video de la prueba se encuentra en el siguiente [link](https://youtu.be/BZDEhf-5Vok)

## Retroalimentación

**- ¿Te parece atractivo el diseño visual del dispositivo?**

Sí, se ve atractivo e innovador para aquellos pacientes con lesión medular con indicación para la marcha. 

**- ¿El tamaño, forma y color del dispositivo parecen adecuados?**

Sí, por todas las sugerencias que se han dado y como se ha estado procediendo con la parte electrónica, está bien la adaptación.

**- ¿Consideras que las partes de contacto con el usuario se ven cómodas?**

No está siendo invasivo para el usuario, puesto que es externo y va en una parte donde el usuario no tiene sensibilidad, por lo cual no incomodaría o afectaría el confort del paciente.

**- ¿La ubicación de los controles parece accesible y fácil de manejar?**

Sí, todo es vía bluetooth.

**- ¿Las funciones del dispositivo son claras?**

Sí,siempre y cuando haya las indicaciones y las preparaciones para el usuario, ello esclarecerá todo para el usuario; las partes técnicas serán brindadas por el terapeuta.

**- ¿Te parece intuitivo el uso del dispositivo según el diseño?**

No, debe de haber una preparación previa.

**- ¿Identificas alguna área en el diseño que podría ser problemática en uso real?**

No se ven áreas del diseño que podrían ser problemáticas; sin embargo, el peor de los casos, es que el usuario no entienda el funcionamiento del dispositivo luego de la explicación.

**- ¿Hay algo que cambiarías en el diseño antes de hacer una versión física?**

El tema del color, por ahora el blanco va bien para mantener la estética y la armonía de colores. Por ahora como prototipo todo está bien.
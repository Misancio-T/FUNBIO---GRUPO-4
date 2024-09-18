# Coherencia problemática- Propuesta solución

## Problemática

### Contexto

En entorno de nuestra problemática se basa en las lesiones medulares, estas son altamente frecuentes en situaciones de alto riesgo, como accidentes de tráfico, caídas desde alturas, accidentes deportivos y también pueden ocurrir por causas internas como enfermedades o infecciones. Estas lesiones afectan a gran cantidad personas a nivel mundial cada año, provocando discapacidades severas que afectan tanto la movilidad física como la calidad de vida en general. Este tipo de trauma es uno de los más devastadores en cuanto a su impacto en la autonomía y bienestar del paciente, ya que compromete funciones vitales como el control del movimiento voluntario, la sensibilidad, la respiración, la función vesical e intestinal, etc.

Las lesiones medulares representan una amplia relevancia en el campo de la ingeniería biomédica debido a su impacto en la directo en la vida de los pacientes dentro y fuera de centros de la salud, además, el desarrollo de nuevas soluciones son necesarias para ayudar a reparar las deficiencias médicas a través de tecnologías que ayudan a acelerar los tratamientos y optimizan los resultados a largo plazo de los pacientes, tales como  facilitar su rehabilitación y  ayudarles a recuperar el mayor grado de funcionalidad corporal, tanto física como  biológicamente.

### Definición del Problema

Pérdida de retroalimentación sensorial y control motor en personas con una lesión medular tipo A (lesión completa) en la parte inferior del cuerpo, particularmente durante la bipedestación y la marcha.

### Impacto

**Impacto en los usuarios**

El problema de la pérdida de retroalimentación sensorial y control motor en personas con una lesión medular completa de tipo A tiene un impacto significativo tanto en la vida de los pacientes como en los sistemas de salud. Uno de los efectos principales es la pérdida de movilidad ya que la persona pierde la capacidad de controlar los músculos en las piernas, lo que significa que no puede caminar ni mantenerse de pie sin asistencia, generando de esta forma una escasa independencia de la persona.

Por otro lado, los pacientes en etapa de tratamiento realizan la bipedestación  y la marcha como ejercicios clave en su recuperación, estas actividades son esenciales pero complicadas de realizar ya que dependen de la retroalimentación sensorial (información que el cerebro recibe del cuerpo sobre la posición de las extremidades) y del control motor, la pérdida de estas funciones implica que la persona no pueda percibir la posición de sus piernas, no puede hacer ajustes automáticos al equilibrio, ni realizar movimientos coordinados para caminar.

La pérdida de la movilidad está asociada con ansiedad, depresión y una disminución de la calidad de vida. La adaptación a una nueva realidad sin la capacidad de caminar o moverse de forma independiente puede ser devastadora, los estudios muestran que entre el 20% y el 40% de las personas con una lesión medular experimentan algún grado de depresión clínica debido a estos cambios drásticos en su vida. [1]

**Impacto en el sistema de salud**

El sistema de salud tiene una gran responsabilidad y carga al tratar a personas con este tipo de lesiones, sobre todo en nuestro país, donde la implementación de nuevas tecnologías es escasa y se suelen realizar los tratamientos convencionales que tiene como resultado una evolución lenta en la mejora de los pacientes.

Los pacientes con lesiones medulares requieren terapia física y ocupacional extensiva para maximizar su independencia, según el NSCISC,aproximadamente el 80% de los pacientes con lesiones medulares requieren asistencia para actividades de la vida diaria, ya sea con sillas de ruedas o dispositivos de asistencia como exoesqueletos robóticos y la ayuda de cuidadores o fisioterapeutas para tareas diarias. Sin Embargo, en Perú existe un notable déficit de profesionales frente a la creciente necesidad de rehabilitación, especialmente en zonas rurales y alejadas​. [2]

## Propuesta de solución

### Descripción de la Solución

**Nuestra propuesta de solución es un Dispositivo de Alerta de Pasos en base a una retroalimentación táctil.** Este estaría compuesto por tres partes: dos en los pies (plantillas con sensores) y una en el pecho (Receptor vibratorio). Los sensores detectan cuándo el pie hace contacto con el suelo o cuando el usuario ha dado un paso. Estos sensores envían una señal al dispositivo en el pecho, que vibrará para alertar al usuario que efectivamente ha puesto un pie, proporcionando una retroalimentación táctil al usuario, el cual no llega a tener sensación física en sus pies debido a una lesión medular o uso de prótesis.

### Características del Prototipo
**Emplea:** Sensores piezoeléctricos, estos se encontrarán en la plantilla que estará en cada pie, y se encargará de detectar el contacto de los pies con el suelo.

**Transmisión inalámbrica con ESP32:** La señal recibida por los sensores en los pies se enviarán de forma inalámbrica desde los sensores al receptor en el pecho usando la conectividad Wi-fi/Bluetooth de este chip.

**Receptor vibratorio en el pecho:** Un dispositivo vibratorio compacto, que puede llevarse como una banda, emitirá una vibración cuando se recibe la señal del sensor del pie, alertando al usuario de que ha dado un paso.

**Fuente de energía:** Pilas CR2025, son pequeñas, fáciles de reemplazar y más sencillas de implementar en nuestro dispositivo que busca la simplicidad.

### Beneficios

**Mejorar la percepción del movimiento:** El usuario aumentaría su conciencia sobre la posición de sus pies durante la marcha, lo cual es bastante necesario para una persona con lesión medular o amputaciones las cuales no pueden llegar a sentir sus pies.

**Facilidad de rehabilitación:** Ayudaría al usuario a desarrollar y ajustar su marcha durante la rehabilitación, al recibir esta retroalimentación táctil en tiempo real sobre cuando sus pies están tocando el suelo. Hay dispositivos que brindan esta retroalimentación táctil, sin embargo la señal se suele envíar a lugares muy cercanos y no incluyen a usuarios que pueden tener mayor sensibilidad en una zona alejada a la planta de los pies.

**Diseño no invasivo y discreto:** A comparación de otros exoesqueletos grandes, o que requieren gran cantidad de componentes y cables, este sería ligero, fácil de usar y no requeriría cables, todo ello facilitando su integración en el día a día del paciente.

**Asequibilidad:** Comparando con otros dispositivos más complejos de rehabilitación, nuestra propuesta es más económica y de fácil implementación, al usar componentes de fácil acceso en el mercado y que son viables técnicamente.

### Viabilidad Técnica

Hemos evaluado el desarrollo del prototipo y este es técnicamente viable utilizando componentes disponibles en el mercado, como:

- ESP32 para la conectividad inalámbrica y procesamiento de señales.
- Sensores piezoeléctricos ya ampliamente utilizados en diversos dispositivos para la detección de presión.
- Baterías pequeñas como la CR2025, que pueden proporcionar la energía necesaria para el funcionamiento continuo del dispositivo.
- Conocimientos básicos de electrónica y programación para integrar los sensores con el ESP32, configurar el sistema de transmisión y programar el mecanismo de vibración en el receptor del pecho.
- Impresión 3D o adaptación de materiales para crear las carcasas de los componentes, como las plantillas que se colocarán en los pies y el dispositivo vibratorio del pecho.

## Coherencia

### Contexto del Proyecto

La propuesta de solución va directamente relacionada con la temática de lesiones medulares, específicamente con pacientes que sufrieron la pérdida de sensibilidad y movilidad en las extremidades inferiores. Según el caso analizado, el paciente presenta una lesión medular entre D11 y D12 que afecta su capacidad de sentir sus piernas y caminar, lo que limita su independencia y avance de tratamiento.

La propuesta de solución es necesaria porque después de una lesión medular , los pacientes tienden a perder la capacidad sensorial que afecta su equilibrio, postura y capacidad de caminar. La implementación de un sistema feedback sensorial artificial puede ayudar en gran medida a cubrir la falta de señales sensoriales y mejorar la calidad de vida y tratamiento del paciente.

Estudios han demostrado que el feedback sensorial en rehabilitación neurológica es una manera eficaz de mejorar la percepción corporal y reducir la dependencia visual en pacientes con lesiones medulares. Este tipo de tecnología integra la ingeniería biomédica al utilizar dispositivos portátiles y tecnología de comunicación inalámbrica para proporcionar una retroalimentación sensitiva en tiempo real. [3]

### Objetivos del Proyecto

El objetivo general del proyecto es desarrollar un sistema de feedback sensorial artificial que mejore la propiocepción y la capacidad de movilidad de paciente con lesiones medulares. Esto se logrará mediante la implementación de un dispositivo que ayuda al paciente a complementar la percepción sensorial, contribuyendo así al avance del tratamiento, la rehabilitación y la calidad de vida de los pacientes. Se busca que los pacientes puedan recuperar parte de su independencia funcional en sus extremidades inferiores, mejorando su equilibrio y estabilidad además de tener un impacto positivo en su salud mental del paciente que puede verse deteriorada por las razones ya mencionadas.

**Objetivos específicos**

- Diseño de plantillas con sensores piezoeléctricos, los sensores piezoeléctricos son eficaces para detectar presiones y movimiento en dispositivos portátiles, así como también el contacto del pie con el suelo brinda información crítica sobre la postura y los movimientos del paciente.
- Desarrollar el diseño de bandas vibratorias para el feedback sensorial que proporciona estímulos vibratorios específicos en respuesta a las señales captadas por los sensores, simulando la retroalimentación sensorial que falta debido a la lesión medular.
- La comunicación inalámbrica entre los dispositivos, se refiere a implementar un sistema de comunicación eficiente y sin cables que permite una rapidez en la interacción de los diferentes componentes del dispositivo
- Optimizar materiales para entornos de bajos recursos, el diseño de soluciones asequibles y portátiles es crucial para provincia y áreas rurales donde el acceso a tecnologías avanzadas es limitado.
- Aprobar la eficacia en pruebas clínicas necesarias asegurando de esta forma que el sistema sea seguro y efectivo, cumpliendo los requisitos médicos obligatorios y regulatorios para el uso de paciente con lesiones medulares en orden de ayudar a la medicina a través de la ingeniería biomédica.

### Justificación del Prototipo

La propuesta de solución destaca frente a otras opciones debido a su capacidad de proporcionar retroalimentación sensorial en tiempo real. En comparación con la estimulación eléctrica funcional (FES) que utiliza impulsos eléctricos para activar nervios periféricos que controlan los músculos, enfocándose en la activación muscular, el feedback sensorial propuesto se centra en simular la sensación perdida, brindando una percepción sensorial en tiempo real que ayuda a reconectar con su cuerpo. Este producto no solo mejora la movilidad, sino que también reduce el riesgo de caídas y genera una mayor autonomía.

Además, resulta tener efectos más prometedores, con sensores piezoeléctricos se enfoca en restaurar la retroalimentación sensorial, el uso de plantillas es menos invasivo, ya que simplemente se colocan en el calzado y la banda vibratoria en las extremidades superiores . Por esta razón, fortalece la conexión cerebral-sensorial, facilitando una mejor integración de la percepción corporal y permitiendo al paciente compensar la pérdida de movilidad con mayor consciencia de su cuerpo en el espacio. El uso de feedback sensorial mediante vibraciones tiene un riesgo mucho menor de fatiga muscular ya que no implica contracción muscular directa, esto permite que el sistema pueda utilizarse durante periodos más largos sin causar agotamiento. [4]

A diferencia de otros dispositivos médicos más complejos, como los que utilizan estimulación eléctrica o prótesis sofisticadas, los componentes de nuestra propuesta son más económicos, convirtiéndose en una propuesta accesible para diferentes contextos socioeconómicos. Los sensores piezoeléctricos y las bandas vibratorias son tecnologías accesibles que pueden ser fabricadas con materiales de bajo costo, sin perder la eficiencia de su propósito.El mantenimiento y operación sencilla de los dispositivos, al no depende de estimulación eléctrica invasiva o complejos mecanismo de control reduce los costos de mantemiento.

La simulación de sensaciones perdidas en los pacientes permite captar la presión y los movimientos del pies, mientras que las bandas vibratorias pueden proporcionar retroalimentación táctil en tiempo real, simulando la sensación de contacto con el suelo y la respuesta sensorial pérdida.

Al mejorar la capacidad sensorial y propioceptiva de los pacientes, se les brinda una mayor autonomía en sus actividades diarias. Al sentirse más seguros al caminar y moverse, pueden desarrollar una mayor independencia, lo que impacta directamente en su calidad de vida. La simplicidad y accesibilidad del dispositivo lo hace aceptable para uso cotidiano, permitiendo que los pacientes lo utilicen en múltiples escenarios sin la necesidad de equipos especializados o supervisión médica constante.

Los estudios han demostrado que el feedback sensorial mejora la plasticidad neuronal, lo que ayuda a que el cerebro se readapte y fortalezca las conexiones neurales pérdidas, esto contribuye a una rehabilitación más efectiva. Con nuestro dispositivo el cuerpo podrá percibir su posición y movimiento en el espacio, el cerebro recibe información aparecida sobre la posición de las piernas a través de la retroalimentación vibratorias proporcionada por las bandas, mejorando directamente el equilibrio del paciente, reduciendo el riesgo de caídas en la rehabilitación y mejorando la capacidad de caminar independientemente.

Nuestra propuesta no está limitada a pacientes con las extremidades presentes, sino también en el caso de pacientes con amputaciones o trastornos congénitos, este tipo de feedback sensorial artificial puede ser integrado en procesos para proporcionar sensaciones táctiles en puntos clave de contacto. Los sensores pueden ser colocados en las superficies de contacto entre el muñón y la prótesis, mientras que las bandas pueden ser colocadas en  partes estratégicas del cuerpo para devolver la sensación de presión al paciente. Esta simulación de la sensación de la extremidad perdida es crucial para mejorar la integración de la prótesis ayudando a los  pacientes a tener control de sus movimientos y a sentirse más conectados con la prótesis.

### Alineación con el Problema

Nuestro prototipo aborda la pérdida de retroalimentación sensorial y control motor en personas con lesiones medulares, especialmente durante la bipedestación y la marcha. Al utilizar plantillas equipadas con sensores piezoeléctricos, se capta la presión y los movimientos de los pues cuando entran en contacto con la superficie, información crítica que los pacientes no pueden percibir naturalmente. Estos sensores recopilan datos sobre la fuerza y presión, aunque los pacientes no pueden sentir directamente esta información los datos son enviados a través de bandas vibratorias, estas vibraciones actúan como una forma de sensor artificial, proporcionando al cerebro información sobre la posición y postura, ayudando al equilibrio del paciente.

## Resumen

### Problema y propuesta de solución
El problema aborda la **pérdida de retroalimentación sensorial y control motor** de personas con **lesiones medulares completas de tipo A**, lo que afecta la capacidad de caminar y mantenerse de pie. Esta falta de sensibilidad genera una dependencia de dispositivos de asistencia que afecta negativamente la calidad de vida y de tratamiento del paciente que retrasa su rehabilitación.

La propuesta de solución es un **sistema feedback sensorial artificial** que utiliza **plantillas con sensores piezoeléctricos y bandas vibratorias.** La plantilla capta la presión del pie en puntos claves al caminar o estar de pie, que envían señales a las bandas vibratorias proporcionando retroalimentación táctil en tiempo real, ayudando a restaurar la percepción corporal perdida. Este dispositivo **mejora la propiocepción reduciendo el riesgo de caídas,** y **permite al paciente recuperar su autonomía** mejorando su equilibrio y estabilidad.

### Resultados esperados

El desarrollo del dispositivo feedback sensorial busca mejorar la **propiocepción y movilidad** de los pacientes con lesiones medulares, permitiendo que recuperen parte de su independencia. Se espera que los pacientes puedan caminar con más confianza y estabilidad, al mismo tiempo que puedan mejorar su estabilidad mental y calidad de vida.

Para testear el prototipo, se podría realizar **pruebas clínicas** con pacientes en etapas de rehabilitación. Se mediría la mejora de **equilibrio, capacidad de marcha,** y la **reducción de la dependencia visual.** El testeo incluiría la comparación del rendimiento del paciente con y sin el dispositivo, midiendo la precisión de la retroalimentación sensorial y su impacto en la **reducción de caídas.**

### Proximos Pasos

- Desarrollo y construcción de prototipo: diseñar y ensamblar las plantillas con sensores y las bandas vibratorias.
- **Validación técnica:** realizar pruebas preliminares para asegurar la funcionalidad y comunicación inalámbrica.
- **Pruebas clínicas:** evaluar el prototipo en el paciente, midiendo la efectividad del equilibrio y movilidad.
- **Optimización:** Utilizar componentes de fácil adquisición para hacerlo más accesible y adaptable a distintos usuarios.

## Bibliografía

- [1] Katlin R. Schultz, Linda R. Mona, Rebecca P. Cameron. Mental Health and Spinal Cord Injury: Clinical Considerations for Rehabilitation Providers. 2022. https://www.ncbi.nlm.nih.gov/pmc/articles/PMC9046713/
- [2] World Health Organization: WHO. (2024b, abril 16). Spinal cord injury. https://www.who.int/news-room/fact-sheets/detail/spinal-cord-injury
- [3] Volker Dietz, Karim Fouad, Restoration of sensorimotor functions after spinal cord injury, Brain, Volume 137, Issue 3, March 2014. https://academic.oup.com/brain/article/137/3/654/389117
- [4] La estimulación eléctrica funcional (FES) para las lesiones de la médula espinal. MSKTC. (s. f.). https://msktc.org/sci/factsheets/la-estimulacion-electrica-funcional-fes-para-las-lesiones-de-la-medula-espinal

## 1. Autor

**Nombre:** [Gilberto Cantu]  
**Matrícula:** [26078]  
**Módulo:** [clasificacion y campeon ]  
**Archivo de código:** [clasificacion_campeon.h]

## 2. Propósito

¿Qué hace tu módulo y para qué le sirve a quien usa el programa?

[Mi modulo se encarga de ordenar la tabla de posiciones del torneo de futbol y saber quien es el campeon. Para hacerlo, utilizo los puntos que obtuvo cada equipo durante los partidos y los acomodo de mayor a menor, tambien detecta cuando dos o mas equipos tienen los mismos puntos en el primer lugar. En ese caso, muestra los equipos empatados y permite que el usuario elija al campeon.

Este modulo le sirve al usuario para conocer la clasificacion final del torneo de una manera clara y ordenada, sin tener que revisar los resultados de todos los partidos y calcular los puntos manualmente.]

## 3. Entradas y salidas

¿Qué recibe tu módulo (parámetros y datos del teclado) y qué produce (lo que imprime o devuelve)?

[Entradas

Mi modulo recibe los siguientes datos:

Un arreglo de registros de tipo Equipo, donde se encuentran los nombres y las estadisticas de los equipos.

La cantidad de equipos que participan en el torneo, que en este caso son 6.

Una variable que indica si el torneo ya fue simulado.

La opcion que escribe el usuario cuando existe un empate en el primer lugar.

Para la eleccion del campeon utilizo la funcion leerEntero() de utilerias.h, ya que todas las entradas por teclado deben realizarse mediante las funciones de esa libreria.

Salidas

Mi modulo produce las siguientes salidas:

Una tabla de posiciones ordenada de mayor a menor por puntos.

La lista de equipos que tienen la mayor cantidad de puntos.

El nombre del campeon y sus puntos.

Mensajes de rechazo cuando se intenta consultar la tabla o el campeon antes de simular el torneo.

Un mensaje cuando el usuario selecciona una opcion que no existe al elegir al campeon.

Las funciones de mi modulo no necesitan devolver una tabla, ya que los resultados se muestran directamente en pantalla.]

## 4. Decisiones de diseño

Explica cada decisión y por qué la tomaste.

**¿Qué funciones tiene tu módulo y qué tarea hace cada una?**

[Inserta aquí tu respuesta]

**¿Qué estructuras de datos usa tu módulo (registros, arreglos, matrices o apuntadores), por qué las elegiste y cómo pasas los datos a cada función (por valor, por referencia, como arreglo o con un apuntador)?**

[Inserta aquí tu respuesta]

**¿Dónde demuestras los temas asignados a tu módulo?**

[Inserta aquí tu respuesta]

**¿Qué ciclos usaste y por qué esos?**

[Inserta aquí tu respuesta]

**¿Qué constantes usaste y por qué son constantes?**

[Inserta aquí tu respuesta]

**¿Qué funciones reutilizaste de `utilerias.h`, de `torneo.h` o de otro módulo?**

[Inserta aquí tu respuesta]

**¿Qué casos de rechazo maneja tu módulo y qué mensaje muestra en cada uno?** Si tu módulo es el 3, escribe "No aplica".

[Inserta aquí tu respuesta]

## 5. Receta

Tu receta en pseudocódigo, escrita antes de programar.

```
[Inserta aquí tu respuesta]
```

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

[Inserta aquí tu respuesta]

## 6. Pruebas

Incluye casos normales y casos límite.

| # | Qué probaste | Entrada | Resultado esperado | Resultado obtenido |
| --- | --- | --- | --- | --- |
| 1 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 2 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 3 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |

## 7. Bitácora de dudas y errores

| # | Duda o error | Cómo lo resolví |
| --- | --- | --- |
| 1 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 2 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 3 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |

## 8. Reflexión

**¿Qué aprendiste?**

[Inserta aquí tu respuesta]

**¿Qué cambiarías de tu proceso?**

[Inserta aquí tu respuesta]
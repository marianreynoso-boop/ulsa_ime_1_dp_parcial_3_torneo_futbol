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

[intercambiarEquipos(): recibe dos apuntadores a registros de tipo Equipo y cambia sus posiciones utilizando una variable auxiliar. Su objetivo es intercambiar todos los datos de los equipos sin perder informacion.

ordenarClasificacion(): utiliza el metodo de ordenamiento burbuja para acomodar los equipos de mayor a menor segun sus puntos. Compara dos equipos consecutivos y los intercambia cuando el equipo de la izquierda tiene menos puntos.

mostrarTabla(): revisa si el torneo ya fue simulado. Despues realiza una copia del arreglo original, ordena la copia y muestra la tabla de posiciones con las estadisticas de cada equipo.

mostrarCampeon(): busca la mayor cantidad de puntos del torneo. Si solamente un equipo tiene esa cantidad, lo muestra como campeon. Si existe un empate, muestra los equipos empatados y pide al usuario que elija uno.]

**¿Qué estructuras de datos usa tu módulo (registros, arreglos, matrices o apuntadores), por qué las elegiste y cómo pasas los datos a cada función (por valor, por referencia, como arreglo o con un apuntador)?**

[Mi modulo utiliza principalmente registros, arreglos y apuntadores.

Utilizo el registro Equipo porque guarda toda la informacion de un equipo en un solo lugar, como su nombre, partidos jugados, ganados, empatados, perdidos, goles a favor, goles en contra y puntos. Esto evita tener que manejar muchos arreglos separados.

Utilizo un arreglo de registros para almacenar y recorrer los 6 equipos del torneo. De esta manera puedo comparar sus puntos y acomodarlos en la tabla.

Tambien utilizo un arreglo auxiliar para guardar una copia de los equipos antes de ordenarlos. Lo hice asi porque las instrucciones indican que los reportes de equipos, ficha y matriz deben conservar el orden de registro. Al ordenar solamente la copia, no modifico el arreglo original.

En la funcion intercambiarEquipos() utilizo apuntadores de tipo Equipo*. Los apuntadores permiten acceder directamente a los registros originales y cambiar sus datos sin tener que regresar una copia.

En las funciones que muestran la tabla y el campeon, recibo el arreglo de equipos como parametro. Para la tabla utilizo una copia local, mientras que para encontrar al campeon solamente consulto los puntos de los equipos.]

**¿Dónde demuestras los temas asignados a tu módulo?**

[Los temas asignados a mi modulo son el ordenamiento, el intercambio de registros y los apuntadores.

El ordenamiento lo demuestro en la funcion ordenarClasificacion(), donde utilizo el metodo burbuja para acomodar los equipos de mayor a menor por puntos.

El intercambio de registros lo demuestro en la funcion intercambiarEquipos(), donde utilizo una variable auxiliar para cambiar de lugar dos equipos completos.

Los apuntadores los demuestro en la misma funcion, ya que recibe las direcciones de dos registros de tipo Equipo y permite modificar directamente sus datos.

Tambien utilizo arreglos de registros, ciclos, condicionales y funciones para completar el funcionamiento de mi modulo.]

**¿Qué ciclos usaste y por qué esos?**

[Utilice ciclos for para recorrer el arreglo de equipos y realizar las comparaciones necesarias para ordenar la tabla.

En el ordenamiento burbuja utilizo dos ciclos for anidados. El primero controla las pasadas del ordenamiento y el segundo compara los equipos que se encuentran uno al lado del otro.

Tambien utilizo ciclos for para copiar los equipos, mostrar la tabla y buscar a los equipos que tienen la mayor cantidad de puntos.

En la funcion mostrarCampeon() utilizo un ciclo do while para pedir la opcion del usuario cuando existe un empate. Lo elegi porque necesito que el usuario escriba una opcion al menos una vez y que se vuelva a preguntar si su respuesta no es valida.]

**¿Qué constantes usaste y por qué son constantes?**

[Utilizo la constante MAX_EQUIPOS, que representa la cantidad maxima de equipos que pueden participar en el torneo.

En este proyecto su valor es 6, porque las reglas indican que participan 6 equipos y se juegan 15 partidos.

La utilizo para declarar el arreglo auxiliar y para limitar la cantidad de equipos que se recorren. Es una constante porque el numero de equipos no cambia durante la ejecucion del programa.

Tambien utilizo la constante MAX_EQUIPOS en lugar de escribir el numero 6 directamente, para que el codigo sea mas claro y facil de modificar si en otro proyecto cambia la cantidad de participantes.]

**¿Qué funciones reutilizaste de `utilerias.h`, de `torneo.h` o de otro módulo?**

[Reutilizo la funcion leerEntero() de utilerias.h para pedir al usuario que elija al campeon cuando existe un empate.

Tambien utilizo el registro Equipo y la constante MAX_EQUIPOS que se encuentran en torneo.h, ya que son parte de las estructuras comunes del proyecto.]

**¿Qué casos de rechazo maneja tu módulo y qué mensaje muestra en cada uno?** Si tu módulo es el 3, escribe "No aplica".

[Si el usuario intenta mostrar la tabla antes de simular el torneo, muestra:

Primero debes simular el torneo.

Si el usuario intenta consultar al campeon antes de simular el torneo, muestra:

Primero debes simular el torneo.

Si existe un empate en el primer lugar y el usuario escribe una opcion menor que 1 o mayor que la cantidad de equipos empatados, muestra:

Opcion invalida. Intenta de nuevo.

Despues vuelve a pedir la opcion hasta que el usuario escriba una valida.]

## 5. Receta

Tu receta en pseudocódigo, escrita antes de programar.

```
[ FUNCION intercambiarEquipos(equipoA, equipoB)

    Crear una variable auxiliar

    Guardar el equipo A en la variable auxiliar

    Copiar el equipo B en el lugar del equipo A

    Copiar el equipo auxiliar en el lugar del equipo B

FIN FUNCION


FUNCION ordenarClasificacion(equipos, cantidad)

    PARA i desde 0 hasta cantidad - 2

        PARA j desde 0 hasta cantidad - 2 - i

            SI los puntos del equipo j
               son menores que los puntos del equipo j + 1

                Intercambiar los dos equipos

            FIN SI

        FIN PARA

    FIN PARA

FIN FUNCION


FUNCION mostrarTabla(equipos, cantidad, torneoSimulado)

    SI el torneo no ha sido simulado

        Mostrar mensaje de rechazo

        Regresar al menu

    FIN SI

    Copiar los equipos en un arreglo auxiliar

    Ordenar el arreglo auxiliar

    Mostrar encabezado de la tabla

    PARA cada equipo del arreglo auxiliar

        Mostrar posicion y estadisticas

    FIN PARA

FIN FUNCION


FUNCION mostrarCampeon(equipos, cantidad, torneoSimulado)

    SI el torneo no ha sido simulado

        Mostrar mensaje de rechazo

        Regresar al menu

    FIN SI

    Buscar la mayor cantidad de puntos

    Guardar los equipos que tengan esos puntos

    SI solamente existe un equipo

        Mostrar nombre del campeon

        Mostrar sus puntos

    SI NO

        Mostrar los equipos empatados

        Pedir al usuario que elija

        Validar la opcion

        REPETIR mientras la opcion sea invalida

            Volver a pedir la opcion

        FIN REPETIR

        Mostrar el campeon elegido

        Mostrar sus puntos

    FIN SI

FIN FUNCION]
```

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

[Si, revise la receta utilizando los resultados del escenario de prueba. Primero identifique los puntos de cada equipo y despues los acomode de mayor a menor.

Con los datos del ejemplo, Aguilas y Leones terminan con 10 puntos, por lo que existe un empate en el primer lugar. La receta permite detectar que ambos equipos tienen la misma cantidad de puntos y muestra las dos opciones para que el usuario elija al campeon.

Tambien considere que el arreglo original no debe modificarse al ordenar la tabla, por eso agregue el paso de copiar los equipos a un arreglo auxiliar.]

## 6. Pruebas

Incluye casos normales y casos límite.

| # | Qué probaste | Entrada | Resultado esperado | Resultado obtenido |
| --- | --- | --- | --- | --- |
| 1 | [Mostrar tabla antes de disimular] | [torneoSimulado = false] | [Mostrar mensaje de rechazo] | [Se muestra el mensaje de rechazo] |
| 2 | [Ordenar la tabla] | [Equipos con 10, 4, 9, 10, 3 y 7 puntos] | [Ordenar de mayor a menor] | [La tabla quedda ordenadamente] |
| 3 | [Detectar  empate en primer lugar] | [Aguilas y Leones con 10 puntos] | [Mostrar los dos equipos empatados] | [Se muestran aguilas y leones] |
| 4 | [Elegir campeon valido] | [Opcion 2] | [Mostrar al segundo equipo empatado como campeon] | [Se muestra leones como campeon] |
| 5 | [Elegir opcion invalida] | [Opcion 5 cuando hay 2 empatados] | [Mostar rechazo y volver a preguntar] | [Se vuelve a pedir la opcion] |
| 6 | [Consultar campeon sin empate] | [Un equipo con ms puntos que los demas] | [Mostrar directamente al campeon] | [Se muestra el equipo con mas puntos] |
| 7 | [Revisar orden original] | [Mostar equipos despues de ordenar la tabla] | [Conservar el orden de registro] | [Los equips conservan su orden original] |

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
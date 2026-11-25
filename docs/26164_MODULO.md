## 1. Autor

**Nombre:** [Maximiliano Muñoz Solís]  
**Matrícula:** [26164]  
**Módulo:** [Matriz de enfrentamientos]  
**Archivo de código:** [include/matriz.h]

## 2. Propósito

¿Qué hace tu módulo y para qué le sirve a quien usa el programa?

[Lo que hace es enseñar una matriz en forma de tabla en la que se muestran en una columna los 6 equipos registrados, una fila donde estan las abreviaturas de cada equipo, conforme se encuentra un nombre de un equipo con la abreviatura se imprime el resultado que hubo en ese partido, se pone primero la cantidad de los goles de la fila respectiva al nombre del equipo y despues el del equipo en contra, cuando el nombre y abreviatura del mismo equipo coincide, esa casilla queda anulada con guiones para indicar que no hay nada. En un espacio aparte se imprime, mejor ataque: equipo con mayor goles a favor, cantidad de goles a favor, en un renglón aparte, mejor defensa: equipo con menor goles en contra, cantidad de goles en contra, en caso de haber empate en cualquiera de estas dos categorias se imprimen los nombres de los equipos empatados.]

## 3. Entradas y salidas

¿Qué recibe tu módulo (parámetros y datos del teclado) y qué produce (lo que imprime o devuelve)?

[Entradas: nombres de equipos, cantidad de equipos, resultados de partidos
Salidas: matriz con los datos recibidos organizados, abreviatura de equipos, nombre de equipos, resultados de los equipos por enfrentamiento, equipo con más goles anotados, equipo con menos goles en contra]

## 4. Decisiones de diseño

Explica cada decisión y por qué la tomaste.

**¿Qué funciones tiene tu módulo y qué tarea hace cada una?**

[prepararMatriz: Se encarga de organizar la información en la matriz, primero la inicializa, después obtiene las primeras tres letras de cada equipo y las convierte en mayúsculas. Luego coloca los nombres y las abreviaturas en sus respectivas posiciones. Finalmente, busca los equipos correspondientes a cada partido y guarda los marcadores en las posiciones correctas.
mostrarMatriz: Se encarga de imprimir la matriz en forma de tabla. Utiliza alineación a la izquierda y espacios de ancho fijo para que los datos queden organizados.
consultarMatriz: Comprueba si el torneo ya fue simulado, si no se ha simulado, muestra un mensaje de error, si ya se simuló, llama a las funciones anteriores y después busca al equipo con más goles a favor y al equipo con menos goles en contra.]

**¿Qué estructuras de datos usa tu módulo (registros, arreglos, matrices o apuntadores), por qué las elegiste y cómo pasas los datos a cada función (por valor, por referencia, como arreglo o con un apuntador)?**

[Utilicé registros Equipo y Partido, arreglos y una matriz.
La matriz de cadenas de texto tiene un tamaño de MAX_EQUIPOS + 1 por MAX_EQUIPOS + 1. La elegí porque permite organizar los nombres de los equipos, sus abreviaturas y los resultados de cada enfrentamiento en forma de tabla.
Un arreglo de cadenas llamado abreviaturas, donde guardo las primeras tres letras de cada equipo.
Los arreglos de equipos y partidos se pasan como parámetros a las funciones. Los recibo como arreglos constantes porque solamente necesito consultar sus datos y no modificarlos. La matriz se pasa como arreglo bidimensional para poder llenarla y después mostrarla.
También utilizo variables normales para guardar índices y cantidades, y una variable bool para saber si el torneo ya fue simulado.]

**¿Dónde demuestras los temas asignados a tu módulo?**

[Demuestro los temas asignados al utilizar una matriz bidimensional para organizar los resultados de los enfrentamientos. También utilizo arreglos para guardar las abreviaturas y los datos de los equipos.
Además, utilizo ciclos anidados para recorrer la matriz, condicionales para encontrar los equipos correspondientes a cada partido y funciones para dividir el programa en diferentes tareas.]

**¿Qué ciclos usaste y por qué esos?**

[En prepararMatriz utilizo ciclos for anidados para inicializar todas las posiciones de la matriz. También los utilizo para recorrer los equipos, guardar las abreviaturas y colocar los nombres.Después utilizo ciclos para recorrer los partidos y buscar los índices de los equipos local y visitante, con el propósito de guardar sus marcadores en la matriz.
En mostrarMatriz utilizo dos ciclos for para recorrer las filas y columnas e imprimir toda la información.
En consultarMatriz utilizo otro ciclo for para comparar los goles a favor y en contra de los equipos y encontrar el mejor ataque y la mejor defensa.]

**¿Qué constantes usaste y por qué son constantes?**

[Utilicé las constantes MAX_EQUIPOS y TOTAL_PARTIDOS que están en torneo.h. y son constantes porque no cambian en todo el programa]

**¿Qué funciones reutilizaste de `utilerias.h`, de `torneo.h` o de otro módulo?**

[Reutilicé las estructuras Equipo y Partido, además de las constantes MAX_EQUIPOS y TOTAL_PARTIDOS, que están declaradas en torneo.h.]

**¿Qué casos de rechazo maneja tu módulo y qué mensaje muestra en cada uno?** Si tu módulo es el 3, escribe "No aplica".

[Solo refleja casos de rechazo cuando se quiere mostrar la matriz cuando no se han simulado los resultados, muestra: Primero debes simular el torneo.]

## 5. Receta

Tu receta en pseudocódigo, escrita antes de programar.

```
FUNCION prepararMatriz    
    m[MAX_EQUIPOS+1][MAX_EQUIPOS+1]
    PARA fila DESDE 0 HASTA MAX_EQUIPOS+1 HACER
        PARA columna DESDE 0 HASTA MAX_EQUIPOS HACER
        Asignar cadena vacia a toda la matriz
        FIN PARA
    FIN PARA

    PARA i DESDE 0 HASTA MAX_EQUIPOS HACER
        Obtener primeras 3 letras del nombre
        Convertir letras a mayuscula
        Guardar abreviaturas en el arreglo
    FIN PARA

    PARA columna DESDE 1 HASTA MAX_EQUIPOS+1 HACER
        Guardar abreviatura en la posicion corresponidente
    FIN PARA

    PARA fila DESDE 1 HASTA MAX_EQUIPOS+1 HACER
        Guardar el nombre del equipo en la posicion corresponidente
    FIN PARA

    PARA i DESDE 1 HASTA MAX_EQUIPOS HACER
        Asignar "---" a la posición m[i][i]
    FIN PARA

    PARA p DESDE 0 HASTA TOTAL_PARTIDOS - 1 HACER

        Inicializar el índice del equipo local en -1
        Inicializar el índice del equipo visitante en -1

        PARA i DESDE 0 HASTA MAX_EQUIPOS - 1 HACER
            SI el nombre del equipo coincide con el equipo local ENTONCES
                Guardar su índice
            FIN SI

            SI el nombre del equipo coincide con el equipo visitante ENTONCES
                Guardar su índice
            FIN SI
        FIN PARA
    
        SI se encontraron ambos equipos ENTONCES
            Guardar el marcador del local contra el visitante
            Guardar el marcador invertido del visitante contra el local
        FIN SI

    FIN PARA

FIN DE LA FUNCIÓN

FUNCIÓN mostrarMatriz

    Mostrar título "MATRIZ DE ENFRENTAMIENTOS"

    PARA fila DESDE 0 HASTA MAX_EQUIPOS HACER

        PARA columna DESDE 0 HASTA MAX_EQUIPOS HACER

            Mostrar m[fila][columna] con alineación a la izquierda
            y un espacio de ancho fijo

        FIN PARA

        Saltar a la siguiente línea

    FIN PARA

FIN FUNCIÓN

INICIO consultarMatriz

    SI simulacionHecha es FALSO ENTONCES
        Mostrar "Primero debes simular el torneo"
        TERMINAR función
    FIN SI

    Declarar matriz[MAX_EQUIPOS + 1][MAX_EQUIPOS + 1]

    Llamar a prepararMatriz(equipos, partidos, matriz)

    Llamar a mostrarMatriz(matriz)


    INICIALIZAR mayorGoles con los goles a favor del primer equipo

    INICIALIZAR menorGolesContra con los goles en contra del primer equipo

    INICIALIZAR indiceAtaque en 0
    INICIALIZAR indiceDefensa en 0

    PARA i DESDE 1 HASTA MAX_EQUIPOS - 1

        SI GF del equipo actual > mayorGoles ENTONCES
            ACTUALIZAR mayorGoles
            GUARDAR indiceAtaque
        FIN SI

        SI GC del equipo actual < menorGolesContra ENTONCES
            ACTUALIZAR menorGolesContra
            GUARDAR indiceDefensa
        FIN SI

    FIN PARA

    MOSTRAR nombre del equipo con mejor ataque
    MOSTRAR mayorGoles

    MOSTRAR nombre del equipo con mejor defensa
    MOSTRAR menorGolesContra

FIN

FIN consultarMatriz
```

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

[Primero organicé los nombres de los equipos y sus abreviaturas, después coloqué los resultados de cada enfrentamiento en las posiciones correspondientes de la matriz, revisé que los marcadores estuvieran en el orden correcto, que en la posición donde un equipo se enfrenta consigo mismo aparecieran guiones y que los resultados se mostraran invertidos al consultar el partido desde el otro equipo, también revisé la búsqueda de los índices del equipo local y visitante para asegurarme de guardar cada resultado en la posición correcta.]

## 6. Pruebas

Incluye casos normales y casos límite.

| # | Qué probaste | Entrada | Resultado esperado | Resultado obtenido |
| --- | --- | --- | --- | --- |
| 1 | [Mostrar la matriz completa] | [6 equipos y todos los resultados del torneo] | [Mostrar nombres, abreviaturas y marcadores correctamente organizados] | [La matriz se mostró correctamente] |
| 2 | [Consultar los mejores equipos] | [Resultados de los 15 partidos] | [Mostrar el equipo con más goles a favor y el de menos goles en contra] | [Se mostraron las estadísticas correspondientes] |
| 3 | [Consultar antes de simular] | [simulacionHecha = false] | [Mostrar el mensaje de rechazo] | [Apareció "Primero debes simular el torneo"] |

## 7. Bitácora de dudas y errores

| # | Duda o error | Cómo lo resolví |
| --- | --- | --- |
| 1 | [No sabía cómo convertir las abreviaturas a mayúsculas] | [Utilicé toupper() para convertir cada letra] |
| 2 | [No sabía cómo colocar los resultados en las posiciones correctas de la matriz] | [Recorrí los equipos para encontrar los índices del local y visitante y después utilicé esos índices para guardar los marcadores] |

## 8. Reflexión

**¿Qué aprendiste?**

[Aprendí a utilizar una matriz bidimensional para organizar información de una manera más visual y ordenada]

**¿Qué cambiarías de tu proceso?**

[Cambiaría la manera en que organicé mi proceso de programación. Primero planearía mejor la distribución de los datos en la matriz y probaría cada función por separado antes de unirlas]

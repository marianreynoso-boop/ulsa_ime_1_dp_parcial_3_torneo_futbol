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

[Entradas: nombres de equipos, cantidad de equipos, abreviatura de equipos, resultados de partidos
Salidas: matriz con los datos recibidos organizados, equipo con más goles anotados, equipo con menos goles en contra]

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

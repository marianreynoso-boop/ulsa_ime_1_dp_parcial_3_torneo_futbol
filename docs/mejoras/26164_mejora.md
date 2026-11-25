Propuesta de mejora elaborada por: [Maximiliano Muñoz Solís]

**Matrícula:** [26164]  
**Título de la propuesta:** [Bordes de separación en la matriz]

## 1. Impacto

¿Es una mejora o una corrección? ¿Qué problema resuelve o qué agrega, y a quién beneficia?

[Es una mejora que consiste en añadir separadores en la matriz para que quede como una tabla dibujada, esto beneficia al usuario para poder leer de manera más fácil la matriz y evitar poder perderse entre tantos resultados]

## 2. Qué implica en el diseño

¿Qué partes de la solución cambian (registros, arreglos, constantes, funciones, menú)? Justifica cada cambio.

[Solo se cambiaria la funcion de mostrarMatriz, esto al ser esta función la responsable de la impresión]

## 3. Receta

Receta en pseudocódigo de la solución con tu propuesta. Marca cada paso nuevo con `[NUEVO]` y cada paso que cambia con `[CAMBIA]`. Los pasos sin marca son los que ya existen.

```
FUNCIÓN mostrarMatriz

    Mostrar título "MATRIZ DE ENFRENTAMIENTOS"

    [NUEVO] Mostrar una línea horizontal para separar el título
            del contenido de la matriz.

    PARA fila DESDE 0 HASTA MAX_EQUIPOS HACER

        PARA columna DESDE 0 HASTA MAX_EQUIPOS HACER

            [CAMBIA] Mostrar m[fila][columna] con alineación
                     a la izquierda, un espacio de ancho fijo
                     y un separador vertical.

        FIN PARA

        Saltar a la siguiente línea.

        [NUEVO] Mostrar una línea horizontal para separar
                los encabezados y las filas de resultados.

    FIN PARA

FIN FUNCIÓN
```
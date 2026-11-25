Propuesta de mejora elaborada por: [Gilberto Cantú Posada]

**Matrícula:** [26078]  
**Título de la propuesta:** [Clasificación automática y selección del campeón del torneo]

## 1. Impacto

¿Es una mejora o una corrección? ¿Qué problema resuelve o qué agrega, y a quién beneficia?

[Es una mejora para el sistema del torneo de futbol, ya que permite organizar los resultados de los equipos de acuerdo con los puntos obtenidos y determinar quien es el campeon.
La propuesta resuelve el problema de tener que revisar manualmente los resultados para saber que equipo quedo en primer lugar. Ademas, cuando dos o mas equipos terminan con los mismos puntos, el programa muestra los equipos empatados y permite al usuario elegir al campeon.
Esta mejora beneficia a los usuarios del programa, porque facilita la consulta de resultados, hace mas clara la clasificacion y reduce errores al determinar al ganador.]

## 2. Qué implica en el diseño

¿Qué partes de la solución cambian (registros, arreglos, constantes, funciones, menú)? Justifica cada cambio.

[Para realizar esta mejora se utiliza la estructura Equipo, que ya contiene la informacion de cada equipo, como su nombre, partidos jugados, ganados, empatados, perdidos, goles a favor, goles en contra y puntos.
Se utiliza un arreglo de equipos para guardar la informacion y realizar el ordenamiento de la clasificacion. Para evitar modificar el orden original de registro, la funcion mostrarTabla() trabaja con una copia de los equipos.

Se agregan las siguientes funciones:
intercambiarEquipos(): intercambia la informacion de dos equipos utilizando apuntadores.
ordenarClasificacion(): ordena los equipos de mayor a menor cantidad de puntos mediante el metodo de burbuja.
mostrarTabla(): muestra la tabla de clasificacion con las estadisticas de cada equipo.
mostrarCampeon(): identifica al equipo con mas puntos y, si existe un empate, permite seleccionar al campeon.
Tambien se reutiliza la funcion leerEntero() de utilerias.h para recibir la opcion del usuario y validar que se encuentre dentro del rango permitido.

En el menu principal se agregan las llamadas a las funciones para mostrar la clasificacion y consultar al campeon, siempre verificando que el torneo ya haya sido simulado.]

## 3. Receta

Receta en pseudocódigo de la solución con tu propuesta. Marca cada paso nuevo con `[NUEVO]` y cada paso que cambia con `[CAMBIA]`. Los pasos sin marca son los que ya existen.

```
[Inserta aquí tu respuesta]
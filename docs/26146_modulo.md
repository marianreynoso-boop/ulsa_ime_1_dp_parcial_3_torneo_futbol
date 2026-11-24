# Documentación del módulo

<!--
Esta es una plantilla. NO la modifiques.
Cópiala a docs/<matrícula>/modulo.md (por ejemplo, docs/123456/modulo.md)
y llena tu copia. En equipos de cinco, el módulo 6 usa docs/modulo_6/modulo.md.
-->

## 1. Autor

**Nombre:** [Oliver Fernando López Pineda]  
**Matrícula:** [26146]  
**Módulo:** [Tabla de posiciones]  
**Archivo de código:** [estadisticas equipo.h]

## 2. Propósito

¿Qué hace tu módulo y para qué le sirve a quien usa el programa?

Mi módulo se encarga de calcular las estadísticas de los equipos como el PJ, PG, PE, PP, GF, GC y los puntos, a partir de los 15 partidos simulados. Esto sin imprimir reportes ni modificar el registro, solo deja listas las estadísticas de modo que los módulos de clasificación/campeón, consulta y matriz trabajen con los datos correctos sin tener que recalcularlos desde cero en cada consulta.

## 3. Entradas y salidas

¿Qué recibe tu módulo (parámetros y datos del teclado) y qué produce (lo que imprime o devuelve)?

Recibe por parámetros el arreglo de registros equipo y el arreglo de registros Partido. 
Modifica en memoria los campos estadísticos de cada Equipo en el arreglo recibido mediante paso por referencia.

## 4. Decisiones de diseño

Explica cada decisión y por qué la tomaste.

**¿Qué funciones tiene tu módulo y qué tarea hace cada una?**

MinusculasEstadisticas`: convierte una cadena a minúsculas para comparar nombres de equipos sin distinguir mayúsculas ni minúsculas.
reiniciarEstadisticas`: pone en `0` los contadores (`PJ`, `PG`, `PE`, `PP`, `GF`, `GC`, `PTS`) de cada equipo antes de calcular.
buscarIndiceEquipo`: localiza el índice del equipo en el arreglo a partir de su nombre (o devuelve `-1` si no lo encuentra).
acumularResultadoPartido`: actualiza `PJ`, `GF`, `GC`, `PG`/`PE`/`PP` y `PTS` del equipo local y visitante según el marcador del partido.
calcularEstadisticasEquipos`: coordina el proceso completo llamando primero a `reiniciarEstadisticas` y luego recorriendo los partidos para acumular sus resultados.



**¿Qué estructuras de datos usa tu módulo (registros, arreglos, matrices o apuntadores), por qué las elegiste y cómo pasas los datos a cada función (por valor, por referencia, como arreglo o con un apuntador)?**

Usa registros (`struct Equipo` y `struct Partido`) y arreglos (`Equipo[MAX_EQUIPOS]` y `Partido[TOTAL_PARTIDOS]`) para agrupar los datos del torneo sin recurrir a variables globales ni arreglos paralelos. Los arreglos de `Equipo` y los `Equipo` individuales que se modifican se pasan por referencia (`&`) para reflejar los cambios directamente en la estructura original; los arreglos/cadenas de solo lectura se pasan como `const` / `const&`, y los valores enteros como goles o cantidades se pasan por valor.

**¿Dónde demuestras los temas asignados a tu módulo?**

En la división del cálculo en funciones pequeñas de una sola responsabilidad y en el uso de paso por referencia (`&`) en `reiniciarEstadisticas`, `acumularResultadoPartido` y `calcularEstadisticasEquipos` para actualizar los campos de `Equipo`.

**¿Qué ciclos usaste y por qué esos?**

Usé ciclos `for` con límite conocido (`cantidadEquipos`, `TOTAL_PARTIDOS` y el tamaño de la cadena al pasar a minúsculas), porque tanto el número de equipos como el total de partidos del torneo son fijos y conocidos de antemano.

**¿Qué constantes usaste y por qué son constantes?**

Usé `MAX_EQUIPOS`, `TOTAL_PARTIDOS`, `PUNTOS_VICTORIA`, `PUNTOS_EMPATE` y `PUNTOS_DERROTA` definidas en `include/torneo.h`. Son constantes porque representan reglas y tamaños fijos del torneo que no deben alterarse en ejecución y evitan usar números mágicos en el código.



**¿Qué funciones reutilizaste de `utilerias.h`, de `torneo.h` o de otro módulo?**

Reutilicé las constantes y definiciones de los registros `Equipo` y `Partido` declaradas en `include/torneo.h`.

**¿Qué casos de rechazo maneja tu módulo y qué mensaje muestra en cada uno?** Si tu módulo es el 3, escribe "No aplica".

No aplica

## 5. Receta


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
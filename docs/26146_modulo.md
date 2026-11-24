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

FUNCION reiniciarEstadisticas(equipos, cantidadEquipos)
  PARA i desde 0 hasta cantidadEquipos - 1
    equipos[i].PJ <- 0
    equipos[i].PG <- 0
    equipos[i].PE <- 0
    equipos[i].PP <- 0
    equipos[i].GF <- 0
    equipos[i].GC <- 0
    equipos[i].PTS <- 0
  FIN PARA
FIN FUNCION

FUNCION acumularResultadoPartido(equipoLocal, equipoVisitante, golesLocal, golesVisitante)
  equipoLocal.PJ <- equipoLocal.PJ + 1
  equipoVisitante.PJ <- equipoVisitante.PJ + 1
  equipoLocal.GF <- equipoLocal.GF + golesLocal
  equipoLocal.GC <- equipoLocal.GC + golesVisitante
  equipoVisitante.GF <- equipoVisitante.GF + golesVisitante
  equipoVisitante.GC <- equipoVisitante.GC + golesLocal

  SI golesLocal > golesVisitante
    equipoLocal.PG <- equipoLocal.PG + 1
    equipoLocal.PTS <- equipoLocal.PTS + PUNTOS_VICTORIA
    equipoVisitante.PP <- equipoVisitante.PP + 1
    equipoVisitante.PTS <- equipoVisitante.PTS + PUNTOS_DERROTA
  SINO SI golesLocal < golesVisitante
    equipoVisitante.PG <- equipoVisitante.PG + 1
    equipoVisitante.PTS <- equipoVisitante.PTS + PUNTOS_VICTORIA
    equipoLocal.PP <- equipoLocal.PP + 1
    equipoLocal.PTS <- equipoLocal.PTS + PUNTOS_DERROTA
  SINO
    equipoLocal.PE <- equipoLocal.PE + 1
    equipoLocal.PTS <- equipoLocal.PTS + PUNTOS_EMPATE
    equipoVisitante.PE <- equipoVisitante.PE + 1
    equipoVisitante.PTS <- equipoVisitante.PTS + PUNTOS_EMPATE
  FIN SI
FIN FUNCION

FUNCION calcularEstadisticasEquipos(equipos, partidos)
  reiniciarEstadisticas(equipos, MAX_EQUIPOS)

  PARA p desde 0 hasta TOTAL_PARTIDOS - 1
    idxLocal <- buscarIndiceEquipo(equipos, MAX_EQUIPOS, partidos[p].local)
    idxVisitante <- buscarIndiceEquipo(equipos, MAX_EQUIPOS, partidos[p].visitante)

    SI idxLocal != -1 Y idxVisitante != -1
      acumularResultadoPartido(equipos[idxLocal], equipos[idxVisitante], partidos[p].golesLocal, partidos[p].golesVisitante)
    FIN SI
  FIN PARA
FIN FUNCION

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

si

## 6. Pruebas

Incluye casos normales y casos límite.

Partido ganado por el local
Local: 3 goles, Visitante: 1 gol
Local: PJ+1, PG+1, GF+3, GC+1, PTS+3; Visitante: PJ+1, PP+1, GF+1, GC+3, PTS+0
[Anota aquí lo que obtuviste al ejecutar]
2
Empate sin goles (caso límite 0-0)
Local: 0 goles, Visitante: 0 goles
Ambos: PJ+1, PE+1, GF+0, GC+0, PTS+1
[Anota aquí lo que obtuviste al ejecutar]
3
Marcador alto / goleada (caso límite 5-0)
Local: 5 goles, Visitante: 0 goles
Local: PG+1, GF+5, GC+0, PTS+3; Visitante: PP+1, GF+0, GC+5, PTS+0
[Anota aquí lo que obtuviste al ejecutar]
4
Recálculo / limpieza previa de estadísticas
Equipos con contadores previos distintos de 0 antes de calcular
Todos los contadores se reinician en 0 antes de sumar los partidos
[Anota aquí lo que obtuviste al ejecutar]

## 7. Bitácora de dudas y errores

Dudar si el Módulo 3 debía imprimir la tabla o usar apuntadores
Se revisó el diseño del módulo: el Módulo 3 solo calcula estadísticas mediante funciones y paso por referencia sin imprimir reportes

## 8. Reflexión

**¿Qué aprendiste?**

Aprendí a separar responsabilidades en funciones pequeñas y enfocadas en una sola tarea, a utilizar el paso por referencia para modificar registros de manera clara sin recurrir a variables globales, y a mantener la coherencia entre los módulos de un proyecto en C++.

**¿Qué cambiarías de tu proceso?**

El órden de hacer las cosas y organizar de mejor forma mi tiempo ya que con diversos proyectos pendientes el tiempo es dificil de administrar.
# Propuesta de mejora

<!--
Esta es una plantilla. NO la modifiques.
Cópiala a docs/mejoras/<matrícula>/mejora.md (por ejemplo, docs/mejoras/123456/mejora.md)
y llena tu copia.

La propuesta es solo diseño: no se programa.
Puede tocar cualquier parte de la solución del equipo y se resuelve con los temas del parcial.
Dentro de un equipo no puede haber dos propuestas iguales.
-->

Propuesta de mejora elaborada por: Oliver Fernando López Pineda

**Matrícula:** 26146
**Título de la propuesta:** Símbolos de los últimos 5 partidos
## 1. Impacto

¿Es una mejora o una corrección? ¿Qué problema resuelve o qué agrega, y a quién beneficia?

Es una mejora. Agrega la visualización de los 5 partidos con símbolos en la tabla de posiciones (similar a la columna "Últimos 5" de tablas de liga como la Liga MX). Beneficia a quien consulta la tabla de posiciones porque permite ver de forma rápida y visual la racha o tendencia reciente de cada equipo (victorias, empates o derrotas) junto con sus puntos y goles.
Esto se mostraria como:

Victoria: ✓
Derrota: x
Empate: -

Ejemplo: ✓ ✓ x ✓ -

## 2. Qué implica en el diseño

¿Qué partes de la solución cambian (registros, arreglos, constantes, funciones, menú)? Justifica cada cambio.

Registros (struct Equipo): se agrega un arreglo o historial de los últimos 5 resultados del equipo (y un contador de cuántos lleva registrados) para guardar su racha reciente sin perder el acumulado general 

Constantes: se define una constante como MAX_ULTIMOS_PARTIDOS = 5 para evitar números mágicos al limitar el historial a los últimos 5 encuentros.

Arreglos: cada registro Equipo mantiene su arreglo de tamaño fijo de 5 elementos, desplazando o sobrescribiendo el resultado más antiguo cuando se acumula uno nuevo.

Funciones: se actualiza la acumulación de resultados del equipo para registrar si el partido fue victoria, empate o derrota dentro de sus últimos 5 partidos, y se apoya o ajusta la visualización de la tabla de posiciones para mostrar esos símbolos.

## 3. Receta

Receta en pseudocódigo de la solución con tu propuesta. Marca cada paso nuevo con `[NUEVO]` y cada paso que cambia con `[CAMBIA]`. Los pasos sin marca son los que ya existen.

FUNCION registrarUltimoResultado(equipo, simbolo) [NUEVO]
  SI equipo.totalUltimos < MAX_ULTIMOS_PARTIDOS [NUEVO]
    equipo.ultimos5[equipo.totalUltimos] <- simbolo [NUEVO]
    equipo.totalUltimos <- equipo.totalUltimos + 1 [NUEVO]
  SINO [NUEVO]
    PARA i desde 0 hasta MAX_ULTIMOS_PARTIDOS - 2 [NUEVO]
      equipo.ultimos5[i] <- equipo.ultimos5[i + 1] [NUEVO]
    FIN PARA [NUEVO]
    equipo.ultimos5[MAX_ULTIMOS_PARTIDOS - 1] <- simbolo [NUEVO]
  FIN SI [NUEVO]
FIN FUNCION [NUEVO]

FUNCION reiniciarEstadisticas(equipos, cantidadEquipos)
  PARA i desde 0 hasta cantidadEquipos - 1
    equipos[i].PJ <- 0
    equipos[i].PG <- 0
    equipos[i].PE <- 0
    equipos[i].PP <- 0
    equipos[i].GF <- 0
    equipos[i].GC <- 0
    equipos[i].PTS <- 0
    equipos[i].totalUltimos <- 0 [NUEVO]
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
    registrarUltimoResultado(equipoLocal, '✓') [CAMBIA]
    equipoVisitante.PP <- equipoVisitante.PP + 1
    equipoVisitante.PTS <- equipoVisitante.PTS + PUNTOS_DERROTA
    registrarUltimoResultado(equipoVisitante, 'x') [CAMBIA]
  SINO SI golesLocal < golesVisitante
    equipoVisitante.PG <- equipoVisitante.PG + 1
    equipoVisitante.PTS <- equipoVisitante.PTS + PUNTOS_VICTORIA
    registrarUltimoResultado(equipoVisitante, '✓') [CAMBIA]
    equipoLocal.PP <- equipoLocal.PP + 1
    equipoLocal.PTS <- equipoLocal.PTS + PUNTOS_DERROTA
    registrarUltimoResultado(equipoLocal, 'x') [CAMBIA]
  SINO
    equipoLocal.PE <- equipoLocal.PE + 1
    equipoLocal.PTS <- equipoLocal.PTS + PUNTOS_EMPATE
    registrarUltimoResultado(equipoLocal, '-') [CAMBIA]
    equipoVisitante.PE <- equipoVisitante.PE + 1
    equipoVisitante.PTS <- equipoVisitante.PTS + PUNTOS_EMPATE
    registrarUltimoResultado(equipoVisitante, '-') [CAMBIA]
  FIN SI
FIN FUNCION

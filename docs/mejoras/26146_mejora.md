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

```
[Inserta aquí tu respuesta]
```
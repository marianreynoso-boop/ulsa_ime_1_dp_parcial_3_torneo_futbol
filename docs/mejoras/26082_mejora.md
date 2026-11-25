# Propuesta de mejora

<!--
Esta es una plantilla. NO la modifiques.
Cópiala a docs/mejoras/<matrícula>/mejora.md (por ejemplo, docs/mejoras/123456/mejora.md)
y llena tu copia.

La propuesta es solo diseño: no se programa.
Puede tocar cualquier parte de la solución del equipo y se resuelve con los temas del parcial.
Dentro de un equipo no puede haber dos propuestas iguales.
-->

Propuesta de mejora elaborada por: Marian Reynoso
**Matrícula:** 26082  
**Título de la propuesta:** Reinicio de simulación de torneo conservando los equipos registrados

## 1. Impacto

¿Es una mejora o una corrección? ¿Qué problema resuelve o qué agrega, y a quién beneficia?

Es una **mejora funcional** en la experiencia de uso del sistema.
Una vez que el usuario simula el torneo, la bandera `simulacionHecha` cambia a `true` y el sistema impide volver a simularlo. Si el usuario desea probar otro escenario (por ejemplo, correr primero el *Modo de Prueba* y luego el *Modo Aleatorio*, o generar nuevos resultados aleatorios), está obligado a cerrar el programa y volver a capturar manualmente todos los equipos desde cero.
## 2. Qué implica en el diseño

¿Qué partes de la solución cambian (registros, arreglos, constantes, funciones, menú)? Justifica cada cambio.

Registros (`struct Equipo` y `struct Partido`):** No cambian. Se mantienen exactamente los mismos campos actuales.
1. Constantes: Se agrega o ajusta la constante de opción de salida del menú (si el menú crece de 9 a 10 opciones) para dar espacio a la nueva funcionalidad, o bien se integra como una confirmación dentro de la Opción 3. Para mantener el menú claro y modular, se propone agregar una nueva opción en el menú principal.
2. Arreglos: No se crean arreglos nuevos. Se reutilizan `equipos[MAX_EQUIPOS]` (reiniciando solo sus campos numéricos de estadísticas) y `partidos[TOTAL_PARTIDOS]` (sobrescribiendo o limpiando sus registros).
3. Funciones: Se crea la función `reiniciarSimulacion(equipos, totalEquipos, partidos, totalPartidos, simulacionHecha)` en `simulacion.h`. Esta función valida que exista una simulación previa, solicita confirmación al usuario, reutiliza la función existente `reiniciarEstadisticas(equipos, totalEquipos)` de `estadisticas_equipo.h`, limpia el arreglo `partidos`, restablece `totalPartidos = 0` y cambia `simulacionHecha = false`.
4. Menú (`main.cpp`):Se agrega la nueva opción **"9. Reiniciar simulacion"** y se recorre **"Salir"** a la opción **10**, actualizando la condición del ciclo `while (opcion != 10)` y agregando el `case 9` correspondiente en el `switch`.
## 3. Receta

Receta en pseudocódigo de la solución con tu propuesta. Marca cada paso nuevo con `[NUEVO]` y cada paso que cambia con `[CAMBIA]`. Los pasos sin marca son los que ya existen.

```
INICIO
  Declarar arreglo equipos[MAX_EQUIPOS]
  Declarar arreglo partidos[TOTAL_PARTIDOS]
  Declarar totalEquipos = 0, totalPartidos = 0
  Declarar simulacionHecha = falso
  Declarar opcion = 0

   MIENTRAS opcion != 10 HACER
    Mostrar menú principal:
      1. Registrar equipos
      2. Mostrar equipos
      3. Simular torneo
      4. Mostrar resultados
      5. Mostrar tabla de posiciones
      6. Mostrar campeon
      7. Consultar equipo individual
      8. Mostrar matriz de enfrentamientos
      9. Reiniciar simulacion
      10. Salir

    Leer opcion

    SEGUN opcion HACER
      CASO 1..8:
        Ejecutar módulos existentes del sistema
            CASO 9:
        Llamar a reiniciarSimulacion(equipos, totalEquipos, partidos, totalPartidos, simulacionHecha)
             CASO 10:
        Mostrar mensaje de despedida
    FIN SEGUN
  FIN MIENTRAS
FIN

PROCEDIMIENTO reiniciarSimulacion(equipos, totalEquipos, partidos, totalPartidos, simulacionHecha)
  SI simulacionHecha ES falso ENTONCES
    Mostrar "No hay ninguna simulacion activa para reiniciar."
    RETORNAR
  FIN SI

  Mostrar "Esto borrara los resultados actuales pero conservara los equipos. ¿Continuar? (1 = Si, 0 = No)"
  Leer confirmacion

  SI confirmacion == 1 ENTONCES
    Llamar a reiniciarEstadisticas(equipos, totalEquipos)

    PARA i DESDE 0 HASTA TOTAL_PARTIDOS - 1 HACER
      partidos[i].local = ""
      partidos[i].visitante = ""
      partidos[i].golesLocal = 0
      partidos[i].golesVisitante = 0
    FIN PARA

    totalPartidos = 0
    simulacionHecha = falso
    Mostrar "Simulacion reiniciada. Ya puedes volver a simular el torneo en la Opcion 3."
  SINO
    Mostrar "Operacion cancelada."
  FIN SI
FIN PROCEDIMIENTO```

<!--
Esta es una plantilla. NO la modifiques.
Cópiala a docs/mejoras/<matrícula>/mejora.md (por ejemplo, docs/mejoras/123456/mejora.md)
y llena tu copia.

La propuesta es solo diseño: no se programa.
Puede tocar cualquier parte de la solución del equipo y se resuelve con los temas del parcial.
Dentro de un equipo no puede haber dos propuestas iguales.
-->

Propuesta de mejora elaborada por: [Lucia Tavares]

**Matrícula:** [26110]  
**Título de la propuesta:** [Validación de nombres duplicados y cadenas vacías al registrar equipos]

## 1. Impacto

¿Es una mejora o una corrección? ¿Qué problema resuelve o qué agrega, y a quién beneficia?

[Es una mejora de validación que resuelve dos problemas comunes al capturar datos: evita que el usuario registre dos equipos con el mismo nombre (lo que causaría confusión en las consultas y simulaciones) y evita que se guarden equipos sin nombre si se presiona "Enter" por accidente. Esto beneficia a quien usa el programa y mantiene limpia la información para los módulos de consulta y simulación de partidos.]

## 2. Qué implica en el diseño

¿Qué partes de la solución cambian (registros, arreglos, constantes, funciones, menú)? Justifica cada cambio.

[**Funciones (`registro.cpp`):** Modifico la función `registrarEquipo` para agregar dos validaciones antes de guardar los datos: primero reviso que `nuevoNombre` no esté vacío (`nuevoNombre.empty()`), y después uso un ciclo `for` para recorrer el arreglo `arregloEquipos` desde `0` hasta `totalEquipos - 1` y verificar que ningún equipo existente tenga ya ese mismo nombre.
* **Registros, arreglos, constantes y menú:** No necesito cambiar nada en la estructura `Equipo`, en los arreglos, en las constantes ni en el menú de `main.cpp`, ya que trabajo con los mismos parámetros (`arregloEquipos[]` y `totalEquipos`) que ya recibe mi función.]

## 3. Receta

Receta en pseudocódigo de la solución con tu propuesta. Marca cada paso nuevo con `[NUEVO]` y cada paso que cambia con `[CAMBIA]`. Los pasos sin marca son los que ya existen.

```
[Imprimir "Ingresa el nombre del nuevo equipo: "
Leer nuevoNombre (usando getline para aceptar espacios)

[NUEVO] If nuevoNombre está vacío entonces:
    [NUEVO] Imprimir "Error: El nombre del equipo no puede estar vacio."
    [NUEVO] return
[NUEVO] Fin if

[NUEVO] Para i desde 0 hasta totalEquipos - 1 hacer:
    [NUEVO] If arregloEquipos[i].nombre es igual a nuevoNombre entonces:
        [NUEVO] Imprimir "Error: Ya existe un equipo registrado con ese nombre."
        [NUEVO] return
    [NUEVO] Fin if
[NUEVO] Fin para

arregloEquipos[totalEquipos].nombre = nuevoNombre
arregloEquipos[totalEquipos].PTS = 0
arregloEquipos[totalEquipos].PJ = 0
arregloEquipos[totalEquipos].PG = 0
arregloEquipos[totalEquipos].PE = 0
arregloEquipos[totalEquipos].PP = 0
arregloEquipos[totalEquipos].GF = 0
arregloEquipos[totalEquipos].GC = 0
arregloEquipos[totalEquipos].DIF = 0

totalEquipos = totalEquipos + 1
Imprimir "¡Equipo '" + nuevoNombre + "' registrado con exito!"]
```

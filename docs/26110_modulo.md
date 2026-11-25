<!--
Esta es una plantilla. NO la modifiques.
Cópiala a docs/<matrícula>/modulo.md (por ejemplo, docs/123456/modulo.md)
y llena tu copia. En equipos de cinco, el módulo 6 usa docs/modulo_6/modulo.md.
-->

## 1. Autor

**Nombre:** [Lucia Tavares]  
**Matrícula:** [26110]  
**Módulo:** [Inserta aquí tu respuesta]  
**Archivo de código:** [registro.h y registro.cpp]

## 2. Propósito

¿Qué hace tu módulo y para qué le sirve a quien usa el programa?


Mi módulo se encarga de dar de alta y registrar nuevos equipos dentro del sistema del torneo. Le sirve al usuario para agregar participantes al campeonato, asegurando que cada equipo quede guardado con su nombre y con todas sus estadísticas inicializadas en cero para evitar datos basura en el sistema.].

## 3. Entradas y salidas

¿Qué recibe tu módulo (parámetros y datos del teclado) y qué produce (lo que imprime o devuelve)?

[Recibe como parámetros el arreglo de estructuras `Equipo arregloEquipos[]` y el contador actual de equipos por referencia `int &totalEquipos`. Desde el teclado recibe un `std::string nuevoNombre` que el usuario escribe al momento de registrar el equipo.

Salidas: La función no devuelve ningún valor (`void`), pero modifica directamente el arreglo guardando el nuevo equipo en la posición `totalEquipos` e incrementa ese contador en 1. En consola imprime el mensaje para pedir el nombre, la confirmación `¡Equipo '<nuevoNombre>' registrado con exito!` o un mensaje de error si el torneo ya está lleno.]

## 4. Decisiones de diseño

Explica cada decisión y por qué la tomaste.

**¿Qué funciones tiene tu módulo y qué tarea hace cada una?**

[1. registrarEquipo:
Verifica si todavía hay cupo disponible en el torneo, pide el nombre del nuevo equipo, lo guarda en la siguiente posición libre del arreglo con todas sus estadísticas en cero y aumenta en 1 el total de equipos.]

**¿Qué estructuras de datos usa tu módulo (registros, arreglos, matrices o apuntadores), por qué las elegiste y cómo pasas los datos a cada función (por valor, por referencia, como arreglo o con un apuntador)?**

[1. Uso el arreglo unidimensional de registros (`Equipo arregloEquipos[]`) para guardar de forma ordenada toda la información de cada equipo (nombre, puntos y goles).

2. Paso el arreglo sin la palabra `const` porque mi módulo sí modifica los datos del arreglo al agregar un equipo nuevo.

3. Paso la variable `totalEquipos` por referencia (`int &totalEquipos`) para que al sumarle 1 dentro de mi función, el cambio se refleje directamente en la variable original del `main.cpp`.]

**¿Dónde demuestras los temas asignados a tu módulo?**

[En los parámetros de la función `registrarEquipo` (al recibir el arreglo de estructuras para modificarlo y pasar el contador por referencia con `&`), y en el manejo de registros al inicializar en cero cada uno de los campos (`nombre`, `PTS`, `PJ`, `PG`, `PE`, `PP`, `GF`, `GC`, `DIF`) del nuevo equipo.]

**¿Qué ciclos usaste y por qué esos?**

[No usé ningún ciclo en mi módulo, porque el contador `totalEquipos` ya me indica exactamente cuál es la siguiente posición libre del arreglo y puedo guardar el equipo directamente ahí sin tener que recorrerlo.]

**¿Qué constantes usaste y por qué son constantes?**

[Usé la constante `MAX_EQUIPOS`, es constante porque representa el límite máximo de capacidad del arreglo del torneo y no debe cambiar durante la ejecución para no desbordar la memoria.]

**¿Qué funciones reutilizaste de `utilerias.h`, de `torneo.h` o de otro módulo?**

[Incluí `torneo.h` y `utilerias.h` en mi cabecera (`registro.h`), y reutilicé la estructura `Equipo` y la constante `MAX_EQUIPOS` definidas en `torneo.h`.]


**¿Qué casos de rechazo maneja tu módulo y qué mensaje muestra en cada uno?** Si tu módulo es el 3, escribe "No aplica".

[Maneja el caso cuando el torneo ya alcanzó su límite (`totalEquipos >= MAX_EQUIPOS`), detiene la función con un `return` y muestra el mensaje: `"Error: El torneo esta lleno. Maximo de equipos alcanzado."`]

## 5. Receta

Tu receta en pseudocódigo, escrita antes de programar.

```
[Imprimir "Ingresa el nombre del nuevo equipo: "
Leer nuevoNombre (usando getline para aceptar espacios)

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

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

[Sí, al hacer la prueba a mano noté que si no inicializaba en cero todos los campos estadísticos (`PTS`, `PJ`, `PG`, `PE`, `PP`, `GF`, `GC`, `DIF`) al momento de crear el equipo, podían quedar con valores basura. Corregí la receta asegurándome de asignar `0` a cada campo antes de aumentar `totalEquipos`.]

## 6. Pruebas

Incluye casos normales y casos límite.

| Incluye casos normales y casos límite.

| # | Qué probaste | Entrada | Resultado esperado | Resultado obtenido |
| --- | --- | --- | --- | --- |
| 1 | Registro normal con espacios | Real Madrid | Guarda el equipo, inicializa sus estadísticas en 0 y aumenta `totalEquipos` en 1. | Mostró `¡Equipo 'Real Madrid' registrado con exito!` y aumentó el contador. |
| 2 | Primer equipo (límite inferior) | Tigres (con `totalEquipos = 0`) | Se guarda en la posición `0` del arreglo y el contador sube a `1`. | Se guardó en el índice 0 sin problemas. |
| 3 | Torneo lleno (límite superior) | Opción 1 en el menú (con `totalEquipos == MAX_EQUIPOS`) | Mensaje de error indicando que el torneo está lleno y no registra nada. | Mostró `"Error: El torneo esta lleno. Maximo de equipos alcanzado."` y regresó al menú.  |

## 7. Bitácora de dudas y errores

|# | Duda o error | Cómo lo resolví |
| --- | --- | --- |
| 1 | Duda de parámetros: El contador de equipos no se actualizaba en el `main.cpp` después de registrar uno nuevo. | Agregué el símbolo `&` al parámetro (`int &totalEquipos`) en el `.h` y en el `.cpp` para pasarlo por referencia. |
| 2 | Nombres con espacios: Al usar `std::cin >> nuevoNombre`, si escribía `"Real Madrid"` solo guardaba la primera palabra. | Cambié la captura de datos a `std::getline(std::cin, nuevoNombre)` para poder leer toda la línea con espacios. |
| 3 | Protección de inclusiones múltiples al enlazar `registro.h` con `main.cpp`. | Agregué `#pragma once` al inicio de `registro.h` para evitar errores de redefinición al compilar. |

## 8. Reflexión

**¿Qué aprendiste?**

[Inserta aquí tu respuesta]

**¿Qué cambiarías de tu proceso?**

[**¿Qué aprendiste?**

Aprendí la diferencia entre pasar parámetros solo para lectura y pasarlos por referencia (`&`) cuando necesito modificar datos originales desde otro módulo. También aprendí a estructurar archivos `.h` y `.cpp` usando `#pragma once` e inicializando correctamente todos los campos de un `struct` para mantener limpios los datos del programa.

**¿Qué cambiarías de tu proceso?**

Probaría desde el inicio los casos límite de entrada de texto con espacios en la terminal antes de conectar mi función al menú principal, y me aseguraría de revisar bien qué librerías y cabeceras son estrictamente necesarias en el archivo `.h` para mantener el código más limpio.]

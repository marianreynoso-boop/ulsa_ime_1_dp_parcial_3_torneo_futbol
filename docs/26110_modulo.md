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


Mi módulo se encarga de dar de alta nuevos equipos dentro del sistema del torneo. Le sirve a quien usa el programa para poder registrar participantes nuevos en el campeonato, asegurándose de que cada equipo se guarde con su nombre y con todas sus estadísticas inicializadas en cero para que no haya datos basura que afecten los cálculos de los partidos[cite: 1, 2].

## 3. Entradas y salidas

¿Qué recibe tu módulo (parámetros y datos del teclado) y qué produce (lo que imprime o devuelve)?

[Recibe como parámetros el arreglo de estructuras `Equipo arregloEquipos[]` y el contador actual de equipos por referencia `int &totalEquipos`. Desde el teclado recibe un `std::string nuevoNombre` que el usuario escribe al momento de registrar el equipo.

Salidas: La función no devuelve ningún valor (`void`), pero modifica directamente el arreglo guardando el nuevo equipo en la posición `totalEquipos` e incrementa ese contador en 1. En consola imprime el mensaje para pedir el nombre, la confirmación de que se registró con éxito o un mensaje de error si el torneo ya está lleno.]

## 4. Decisiones de diseño

Explica cada decisión y por qué la tomaste.

**¿Qué funciones tiene tu módulo y qué tarea hace cada una?**

[registrarEquipo:
Verifica si todavía hay cupo disponible en el torneo, pide el nombre del nuevo equipo, lo guarda en la siguiente posición libre del arreglo con todas sus estadísticas en cero y aumenta en 1 el total de equipos.]

**¿Qué estructuras de datos usa tu módulo (registros, arreglos, matrices o apuntadores), por qué las elegiste y cómo pasas los datos a cada función (por valor, por referencia, como arreglo o con un apuntador)?**

[1. Uso el arreglo unidimensional de registros (`Equipo arregloEquipos[]`) para guardar de forma ordenada toda la información de cada equipo (nombre, puntos y goles).

2. Paso el arreglo sin la palabra `const` porque mi módulo sí modifica los datos del arreglo al agregar un equipo nuevo.

3. Paso la variable `totalEquipos` por referencia (`int &totalEquipos`) para que al sumarle 1 dentro de mi función, el cambio se refleje directamente en la variable original del `main.cpp`.]

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
[Inserta aquí tu respuesta]
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

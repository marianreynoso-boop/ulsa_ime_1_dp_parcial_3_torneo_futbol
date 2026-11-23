# Documentación del módulo

<!--
Esta es una plantilla. NO la modifiques.
Cópiala a docs/<matrícula>/modulo.md (por ejemplo, docs/123456/modulo.md)
y llena tu copia. En equipos de cinco, el módulo 6 usa docs/modulo_6/modulo.md.
-->

## 1. Autor

**Nombre:** Marian Reynoso Romo 
**Matrícula:** 26082
**Módulo:** 5
**Archivo de código:** consulta.h y consulta.cpp

## 2. Propósito

¿Qué hace tu módulo y para qué le sirve a quien usa el programa?

Mi módulo se encarga de la visualización y búsqueda de información dentro del torneo. Le permite al usuario ver la lista completa de todos los equipos registrados con sus estadísticas actuales, y también buscar un equipo en específico por su nombre para consultar sus datos particulares sin tener que leer toda la tabla.

## 3. Entradas y salidas

¿Qué recibe tu módulo (parámetros y datos del teclado) y qué produce (lo que imprime o devuelve)?

Recibe como parámetros el arreglo de equipos y el número de totalEquipos. Para la función de búsqueda, recibe un std::string nombreBuscado que se captura desde el teclado en el menú principal.

Salidas: La función de mostrar imprime texto directamente en la consola (la tabla de equipos). La función de búsqueda devuelve un apuntador constante (const Equipo*) que apunta a la dirección de memoria del equipo encontrado, o devuelve nullptr si no lo encuentra.

## 4. Decisiones de diseño

Explica cada decisión y por qué la tomaste.

**¿Qué funciones tiene tu módulo y qué tarea hace cada una?**

1. mostrarEquipos:
Recorre el arreglo de equipos e imprime las estadísticas de cada uno en forma de lista
2. buscarEquipos:
Compara el nombre ingresado con los nombres del arreglo y devuelve la ubicación en memoria del equipo

**¿Qué estructuras de datos usa tu módulo (registros, arreglos, matrices o apuntadores), por qué las elegiste y cómo pasas los datos a cada función (por valor, por referencia, como arreglo o con un apuntador)?**

1. Uso el arreglo unidimensional de registros (Equipo[]) pasándolo a las funciones para poder leer la información.

2. El paso por arreglo constante (const Equipo arregloEquipos[]) porque mi módulo es de solo lectura y esto protege la información para no modificarla por accidente.

3. apuntadores (const Equipo*) como tipo de retorno en la búsqueda, para devolver la ubicación exacta del equipo en lugar de crear una copia pesada de toda la estructura.

**¿Dónde demuestras los temas asignados a tu módulo?**

En los parámetros de ambas funciones. Y el uso de apuntadores en el retorno de la función buscarEquipo y en el main.cpp (usando el operador flecha -> para leer el resultado).

**¿Qué ciclos usaste y por qué esos?**

Use el for en ambas funciones, porque ya se el límite de iteraciones que debo de hacer y es mas facil recorrer el arreglo

**¿Qué constantes usaste y por qué son constantes?**

use const, son constantes porque un módulo de consulta no puede alterar ningún dato de los equipos

**¿Qué funciones reutilizaste de `utilerias.h`, de `torneo.h` o de otro módulo?**

la estructura de Equipo que se definió en torneo.h

**¿Qué casos de rechazo maneja tu módulo y qué mensaje muestra en cada uno?** Si tu módulo es el 3, escribe "No aplica".

Devuelve el nullptr si al buscar, el programa no encuentra ningún nombre que coincida

## 5. Receta

Tu receta en pseudocódigo, escrita antes de programar.

```
Función buscarEquipo(arregloEquipos, totalEquipos, nombreBuscado):
    Para i desde 0 hasta totalEquipos - 1 hacer:
        if arregloEquipos[i].nombre es igual a nombreBuscado entonces:
            return la dirección de memoria de arregloEquipos[i]
        Fin if
    Fin for
    return nulo (no se encontró)
Fin 
```

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

Sí, al probar a mano noté que si devolvía el equipo directamente se creaba una copia. Corregí el diseño para devolver la dirección de memoria (&) y optimizar el programa.

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

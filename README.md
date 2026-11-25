# Proyecto Parcial 3: Sistema de Gestión de un Torneo de Fútbol

> **Importante:** este README es del equipo y debe tener aportaciones de todos los integrantes. La guía completa está en [`PROYECTO.md`](PROYECTO.md).

## 1. Integrantes

| Módulo | Matrícula | Nombre | Usuario de GitHub | Tema |
| --- | --- | --- | --- | --- |
| 1 | [Inserta aquí tu respuesta] | [26110] | [Lucia Tavares] | Registro de equipos |
| 2 | [Inserta aquí tu respuesta] | [26162] | [Nathaly Valdes] | Simulación de partidos |
| 3 | [Inserta aquí tu respuesta] | [26146] | [Oliver López] | Tabla de posiciones |
| 4 | [Inserta aquí tu respuesta] | [26078] | [Gilberto Cantú] | Clasificación y campeón |
| 5 | [Inserta aquí tu respuesta] | [26082] | [Marian Romo] | Consultas |
| 6 | [Inserta aquí tu respuesta] | [26164] | [Maximiliano Muñoz] | Matriz de enfrentamientos |

> **Nota:** en los equipos de 5 integrantes, todos contribuyen al módulo 6. En esa fila escriban "Todo el equipo".

## 2. Opciones del menú

Escriban las opciones del menú en el orden en que aparecen en el programa.
1. Registrar Equipo
2. Mostrar equipos
3. Simular torneo
4. Mostrar resultados
5. Mostrar tabla de posiciones
6. Mostrar Campeon
7. Consultar Equipo
8. Mostrar matriz de enfrentamientos
9. Salir

## 3. Cómo compilar y ejecutar

Desde la carpeta del proyecto:

```
g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o torneo
```

Para ejecutar en macOS:

```
./torneo
```

Para ejecutar en Windows:

```
.\torneo.exe
```

## 4. Tipos de datos abstractos (TDA)

Describan cada TDA que diseñaron como registro (`struct`): qué datos guarda, qué operaciones tiene y por qué.

[En nuestro programa utilizamos dos estructuras principales para guardar y organizar la informacion del torneo.

TDA Equipo

El registro Equipo guarda los datos de cada equipo participante. Contiene su nombre, abreviatura y las estadisticas que obtiene durante el torneo, como partidos jugados, ganados, empatados, perdidos, goles a favor, goles en contra y puntos.

Las operaciones que se realizan con este registro son registrar equipos, mostrar sus datos, consultar su informacion y actualizar sus estadisticas despues de cada partido.

Se utiliza esta estructura porque permite tener toda la informacion de un equipo organizada en un solo registro, facilitando su manejo dentro del programa.

TDA Partido

El registro Partido guarda la informacion de cada enfrentamiento entre dos equipos. Contiene los equipos participantes y los goles que anotaron durante el partido.

Las operaciones que se realizan con este registro son guardar los resultados, mostrar los partidos y consultar los enfrentamientos de cada equipo.

Se utiliza esta estructura porque permite almacenar los resultados de todos los partidos y utilizarlos para calcular las estadisticas del torneo.]

## 5. Reglas del programa

Escriban las decisiones que el equipo tomó y que el cálculo a mano necesita. Por ejemplo: cómo se obtiene la abreviatura y qué pasa si dos se repiten.

[El torneo cuenta con 6 equipos participantes.

Cada equipo juega una vez contra los otros 5 equipos.

En total se realizan 15 partidos.

Los goles de cada partido se generan de manera aleatoria.

Si un equipo gana, recibe 3 puntos.

Si un partido termina empatado, cada equipo recibe 1 punto.

Si un equipo pierde, recibe 0 puntos.

La clasificacion se ordena de mayor a menor cantidad de puntos.

Si dos o mas equipos terminan con los mismos puntos en el primer lugar, el programa muestra los equipos empatados y permite elegir al campeon.

El mejor ataque es el equipo que anota mas goles durante el torneo.

La mejor defensa es el equipo que recibe menos goles.

La tabla de posiciones se muestra ordenada, pero los equipos conservan su orden original de registro para las consultas y otros reportes.

Para registrar un equipo se solicita su nombre y se obtiene una abreviatura de tres letras.

Si dos equipos tienen la misma abreviatura, se debe revisar y resolver la repeticion para que puedan distinguirse correctamente.]

## 6. Equipos del escenario

Los 6 equipos que registran en el escenario obligatorio, en orden de registro.

| # | Nombre | Abreviatura |
| --- | --- | --- |
| 1 | [Porrimamis] | [POR] |
| 2 | [Mecanenas] | [MEC] |
| 3 | [Mojarras] | [MOJ] |
| 4 | [Habibis] | [HAB] |
| 5 | [Neftalis] | [NEF] |
| 6 | [Pescados] | [PES] |

## 7. Cálculo a mano

Ejecuten una corrida en modo aleatorio y copien aquí sus 15 resultados.

```
 Local           Marcador      Vistante
1-Porrimamis     0-4           Mecanenas
2.Porrimamis     4-3           Mojarras
3-Porrimamis     4-1           Habibis
4-Porrimamis     4-4           Neftalis
5.Porrimamis     5-1           Pescados
6-Mecanenas      4-1           Mojarras
7-Mecanenas      4-1           Habibis
8-Mecanenas      4-3          Neftalis
9-Mecanenas      2-1          Pescados
10-Mojarras      0-5          Habibis
11-Mojarras      1-5          Neftalis
12-Mojarras      3-3          Pescados
13-Habibis       3-1          Neftalis
14-Habibis       3-5          Pescados
15-Neftalis      0-3          Pescados
```

Antes de consultar los demás reportes de esa corrida, calculen a mano los resultados.

**Tabla de posiciones:**

| Equipo | PJ | PG | PE | PP | GF | GC | PTS |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Mecanenas] | [5] | [5] | [0] | [0] | [18] | [6] | [15] |

| [Porrimamis] | [5] | [3] | [1] | [1] | [17] | [13] | [10] |

| [Pescados] | [5] | [2] | [1] | [2] | [13] | [13] | [7] |

| [Habibis] | [5] | [2] | [0] | [3] | [13] | [14] | [6] |

| [Neftalis] | [5] | [1] | [1] | [3] | [13] | [15] | [4] |

| [Mojarras] | [5] | [0] | [1] | [4] | [8] | [21] | [1] |

**Campeón o equipos empatados en el primer lugar:** [Mecanenas]  
**Mejor ataque:** [Mecanenas]  
**Mejor defensa:** [Mecanenas]

**¿La salida del programa coincidió con el cálculo a mano? Si no, ¿qué corrigieron?**

[si coincidio]

## 8. Receta del menú

Receta en pseudocódigo del programa principal: el menú y cómo se conecta con cada módulo.

```
[INICIO

    Crear el arreglo de equipos
    Crear el arreglo de partidos
    Inicializar totalEquipos en 0
    Inicializar totalPartidos en 0
    Inicializar simulacionHecha en falso

    Solicitar el nombre del usuario
    Mostrar mensaje de bienvenida

    Mientras la opcion sea diferente de 9

        Mostrar el menu principal
        Solicitar una opcion al usuario

        SEGUN la opcion

            CASO 1:
                Llamar a registrarEquipo
                Registrar un equipo
            FIN CASO

            CASO 2:
                Llamar a mostrarEquipos
                Mostrar los equipos registrados
            FIN CASO

            CASO 3:
                Llamar a simulartorneo
                Simular los partidos
                Llamar a calcularEstadisticasEquipos
                Actualizar las estadisticas
            FIN CASO

            CASO 4:
                Llamar a mostrarResultados
                Mostrar los resultados de los partidos
            FIN CASO

            CASO 5:
                Llamar a mostrarTabla
                Mostrar la tabla de posiciones
            FIN CASO

            CASO 6:
                Llamar a mostrarCampeon
                Mostrar al campeon del torneo
            FIN CASO

            CASO 7:
                Llamar a mostrarFichaEquipo
                Consultar la informacion de un equipo
            FIN CASO

            CASO 8:
                Llamar a consultarMatriz
                Mostrar la matriz de enfrentamientos
            FIN CASO

            CASO 9:
                Terminar el programa
            FIN CASO

        FIN SEGUN

    FIN MIENTRAS

FIN]
```

## 9. Documentación individual

Enlace a la documentación y a la propuesta de mejora de cada integrante.

| Módulo | Documentación | Propuesta de mejora |
| --- | --- | --- |
| 1 | [docs/26110_modulo.md] | [docs/mejoras/26110_mejora.md] |
| 2 | [docs/26162_modulo.md] | [docs/mejoras/26162_mejora.md] |
| 3 | [docs/26146_modulo.md] | [docs/mejoras/26146-mejora.md] |
| 4 | [docs/26078_modulo.md] | [docs/mejoras/26078_mejora.md] |
| 5 | [docs/26082_modulo.md] | [docs/mejoras/26164_mejora.md] |
| 6 | [docs/26164_modulo.md] | [docs/mejoras/26164_mejora.md] |

<!-- Si el equipo es de seis integrantes, agreguen una fila para el módulo 6. En equipos de cinco, agreguen una fila con el enlace a docs/modulo_6/modulo.md, sin propuesta de mejora. -->

## 10. Cambios a la base común

Si cambiaron una constante de `include/torneo.h`, expliquen qué cambiaron y por qué. Si no cambiaron nada, escriban "Sin cambios".

[Sin cambios]
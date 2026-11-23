#pragma once

#include <iostream>
#include <iomanip>
#include <string>

#include <torneo.h>
#include <utilerias.h>
#include <escenario_prueba.h>
#include <estadisticas_equipo.h>

using namespace std;

inline bool simulartorneo(Equipo (&equipos)[MAX_EQUIPOS],
                          int numEquipos,
                          Partido (&partidos)[TOTAL_PARTIDOS],
                          int &numPartidos,
                          bool &yasimulado) {
    if (numEquipos < MAX_EQUIPOS) {
        cout << "Error: Debes registrar los " << MAX_EQUIPOS
             << " equipos antes de simular.\n";
        return false;
    }

    if (yasimulado) {
        cout << "Error: El torneo ya fue simulado anteriormente.\n";
        return false;
    }

    cout << "\n--- MODO DE SIMULACION ---\n";
    cout << "1. Modo Aleatorio\n";
    cout << "2. Modo de Prueba\n";

    int modo = leerEntero("Elige una opcion: ");
    while (modo != 1 && modo != 2) {
        cout << "Opcion no valida. Elige 1 o 2.\n";
        modo = leerEntero("Elige una opcion: ");
    }

    int indicePartido = 0;

    for (int i = 0; i < MAX_EQUIPOS - 1; i++) {
        for (int j = i + 1; j < MAX_EQUIPOS; j++) {
            partidos[indicePartido].local = equipos[i].nombre;
            partidos[indicePartido].visitante = equipos[j].nombre;

            if (modo == 1) {
                partidos[indicePartido].golesLocal = numeroAleatorio();
                partidos[indicePartido].golesVisitante = numeroAleatorio();
            } else {
                partidos[indicePartido].golesLocal = GOLES_PRUEBA[indicePartido][0];
                partidos[indicePartido].golesVisitante = GOLES_PRUEBA[indicePartido][1];
            }

            indicePartido++;
        }
    }

    numPartidos = indicePartido;
    yasimulado = true;

    calcularEstadisticasEquipos(equipos, partidos);

    cout << "\n--- RESULTADOS DE LOS PARTIDOS ---\n";
    cout << left << setw(4) << "#"
         << left << setw(17) << "LOCAL"
         << left << setw(10) << "MARCADOR"
         << left << setw(17) << "VISITANTE" << "\n";

    for (int i = 0; i < numPartidos; i++) {
        string marcador = to_string(partidos[i].golesLocal)
                        + " - "
                        + to_string(partidos[i].golesVisitante);

        cout << left << setw(4) << (i + 1)
             << left << setw(17) << partidos[i].local
             << left << setw(10) << marcador
             << left << setw(17) << partidos[i].visitante << "\n";
    }

    return true;
}
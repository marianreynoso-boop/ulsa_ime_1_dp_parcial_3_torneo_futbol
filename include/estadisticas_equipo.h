#pragma once

#include "torneo.h"

inline void calcularEstadisticas(Equipo equipos[], int totalEquipos,
                                 const Partido partidos[], int totalPartidos) {
    for (int i = 0; i < totalEquipos; ++i) {
        equipos[i].PJ = equipos[i].PG = equipos[i].PE = equipos[i].PP = 0;
        equipos[i].GF = equipos[i].GC = equipos[i].PTS = 0;
    }

    for (int i = 0; i < totalPartidos; ++i) {
        Equipo* local = nullptr;
        Equipo* visitante = nullptr;
        for (int j = 0; j < totalEquipos; ++j) {
            if (nombresIguales(equipos[j].nombre, partidos[i].local)) local = &equipos[j];
            if (nombresIguales(equipos[j].nombre, partidos[i].visitante)) visitante = &equipos[j];
        }
        if (local == nullptr || visitante == nullptr) continue;

        int golesLocal = partidos[i].golesLocal;
        int golesVisitante = partidos[i].golesVisitante;
        local->PJ++; visitante->PJ++;
        local->GF += golesLocal; local->GC += golesVisitante;
        visitante->GF += golesVisitante; visitante->GC += golesLocal;

        if (golesLocal > golesVisitante) {
            local->PG++; local->PTS += PUNTOS_VICTORIA;
            visitante->PP++;
        } else if (golesLocal < golesVisitante) {
            visitante->PG++; visitante->PTS += PUNTOS_VICTORIA;
            local->PP++;
        } else {
            local->PE++; visitante->PE++;
            local->PTS += PUNTOS_EMPATE;
            visitante->PTS += PUNTOS_EMPATE;
        }
    }
}

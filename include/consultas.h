#pragma once

#include <iomanip>
#include <iostream>
#include <string>
#include "torneo.h"
#include "utilerias.h"

inline const Equipo* buscarEquipo(const Equipo* equipos, int totalEquipos,
                                  const std::string& nombre) {
    for (int i = 0; i < totalEquipos; ++i) {
        if (nombresIguales(equipos[i].nombre, nombre)) {
            return &equipos[i];
        }
    }
    return nullptr;
}

inline void imprimirConsulta(const Equipo* equipos, int totalEquipos,
                             const Partido partidos[], int totalPartidos,
                             bool simulacionHecha) {
    if (!simulacionHecha) {
        std::cout << "Primero debes simular el torneo.\n";
        return;
    }
    std::string nombre = leerCadena("Nombre del equipo: ");
    const Equipo* equipo = buscarEquipo(equipos, totalEquipos, nombre);
    std::cout << "--- FICHA DE EQUIPO ---\n";
    if (equipo == nullptr) {
        std::cout << "Equipo no encontrado: " << nombre << '\n';
        return;
    }

    std::cout << "Equipo: " << equipo->nombre << '\n'
              << "Jugados: " << equipo->PJ << '\n'
              << "Ganados: " << equipo->PG << '\n'
              << "Empatados: " << equipo->PE << '\n'
              << "Perdidos: " << equipo->PP << '\n'
              << "Goles a favor: " << equipo->GF << '\n'
              << "Goles en contra: " << equipo->GC << '\n'
              << "Puntos: " << equipo->PTS << "\n\n";

    std::cout << std::left << std::setw(17) << "RIVAL"
              << std::setw(10) << "MARCADOR" << "RESULTADO\n";
    for (int i = 0; i < totalPartidos; ++i) {
        int golesPropios = 0;
        int golesRival = 0;
        std::string rival;
        if (nombresIguales(partidos[i].local, equipo->nombre)) {
            golesPropios = partidos[i].golesLocal;
            golesRival = partidos[i].golesVisitante;
            rival = partidos[i].visitante;
        } else if (nombresIguales(partidos[i].visitante, equipo->nombre)) {
            golesPropios = partidos[i].golesVisitante;
            golesRival = partidos[i].golesLocal;
            rival = partidos[i].local;
        } else {
            continue;
        }

        std::string resultado = golesPropios > golesRival ? "Ganado" :
                                (golesPropios < golesRival ? "Perdido" : "Empatado");
        std::string marcador = std::to_string(golesPropios) + " - " + std::to_string(golesRival);
        std::cout << std::left << std::setw(17) << rival
                  << std::setw(10) << marcador << resultado << '\n';
    }
}

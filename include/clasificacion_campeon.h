#pragma once


#include <iomanip>
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <random>
#include <stdexcept>
#include "torneo.h"
#include "utilerias.h"

inline void intercambiarEquipos(Equipo* uno, Equipo* dos) {
    if (uno != nullptr && dos != nullptr) {
        Equipo temporal = *uno;
        *uno = *dos;
        *dos = temporal;
    }
}

inline void ordenarTabla(Equipo tabla[], int total) {
    for (int i = 0; i < total - 1; ++i) {
        for (int j = i + 1; j < total; ++j) {
            if (tabla[j].PTS > tabla[i].PTS) {
                intercambiarEquipos(&tabla[i], &tabla[j]);
            }
        }
    }
}

inline void mostrarTabla(const Equipo equipos[], int total, bool simulacionHecha) {
    if (!simulacionHecha) {
        std::cout << "Primero debes simular el torneo.\n";
        return;
    }
    std::cout << "--- TABLA DE POSICIONES ---\n";
    std::cout << std::left << std::setw(5) << "POS" << std::setw(17) << "EQUIPO"
              << std::right << std::setw(4) << "PJ" << std::setw(4) << "PG"
              << std::setw(4) << "PE" << std::setw(4) << "PP"
              << std::setw(4) << "GF" << std::setw(4) << "GC"
              << std::setw(5) << "PTS" << '\n';
    Equipo tabla[MAX_EQUIPOS];
    for (int i = 0; i < total; ++i) tabla[i] = equipos[i];
    ordenarTabla(tabla, total);
    for (int i = 0; i < total; ++i) {
        std::cout << std::left << std::setw(5) << i + 1
                  << std::setw(17) << tabla[i].nombre << std::right
                  << std::setw(4) << tabla[i].PJ << std::setw(4) << tabla[i].PG
                  << std::setw(4) << tabla[i].PE << std::setw(4) << tabla[i].PP
                  << std::setw(4) << tabla[i].GF << std::setw(4) << tabla[i].GC
                  << std::setw(5) << tabla[i].PTS << '\n';
    }
}

inline void mostrarCampeon(Equipo equipos[], int total, bool simulacionHecha) {
    if (!simulacionHecha) {
        std::cout << "Primero debes simular el torneo.\n";
        return;
    }
    Equipo tabla[MAX_EQUIPOS];
    for (int i = 0; i < total; ++i) tabla[i] = equipos[i];
    ordenarTabla(tabla, total);

    std::cout << "--- CAMPEON DEL TORNEO ---\n";
    int empatados = 0;
    for (int i = 0; i < total && tabla[i].PTS == tabla[0].PTS; ++i) ++empatados;

    int elegido = 0;
    if (empatados > 1) {
        std::cout << "Hay un empate en el primer lugar con " << tabla[0].PTS << " puntos.\n";
        for (int i = 0; i < empatados; ++i) {
            std::cout << i + 1 << ". " << tabla[i].nombre << '\n';
        }
        while (true) {
            elegido = leerEntero("Elige al campeon: ");
            if (elegido >= 1 && elegido <= empatados) break;
            std::cout << "Opcion no valida. Intenta de nuevo.\n";
        }
        --elegido;
    }

    std::cout << "Campeon: " << tabla[elegido].nombre << '\n';
    std::cout << "Puntos: " << tabla[elegido].PTS << '\n';
}
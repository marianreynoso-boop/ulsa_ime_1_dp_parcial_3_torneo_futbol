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

inline void prepararMatriz(const Equipo equipos[],
                            const Partido partidos[], 
                            std::string m[MAX_EQUIPOS + 1][MAX_EQUIPOS + 1]) {
std::string abreviaturas[MAX_EQUIPOS];

    for (int fila = 0; fila < MAX_EQUIPOS + 1; fila++) {
        for (int columna = 0; columna < MAX_EQUIPOS + 1; columna++) {
        m[fila][columna] = "";
        }
    }

    for (int i = 0; i < MAX_EQUIPOS; i++) {
        abreviaturas[i] = equipos[i].nombre.substr(0,3);    //substr elige las primeras 3 letras
   
        for (int j = 0; j < 3; j++) {
            abreviaturas[i][j] = toupper(abreviaturas[i][j]);   //toupper convierte minuscula a mayuscula
        }
    }

    for (int columna = 1; columna < MAX_EQUIPOS + 1; columna++) {
        m[0][columna] = abreviaturas[columna - 1];
    }

    for (int fila = 1; fila < MAX_EQUIPOS + 1; fila++) {
        m[fila][0] = equipos[fila - 1].nombre;
    }

    for (int i = 1; i < MAX_EQUIPOS + 1; i++) {
        m[i][i] = "---";
    }

    for (int p = 0; p < TOTAL_PARTIDOS; p++) {

    int indiceLocal = -1; //se inicia en -1 por el recorrido de arreglos
    int indiceVisitante = -1;

        for (int i = 0; i < MAX_EQUIPOS; i++) {

            if (equipos[i].nombre == partidos[p].local) {
                indiceLocal = i;
            }

            if (equipos[i].nombre == partidos[p].visitante) {
                indiceVisitante = i;
            }
        }

        if (indiceLocal != -1 && indiceVisitante != -1) {

            m[indiceLocal + 1][indiceVisitante + 1] =
                std::to_string(partidos[p].golesLocal) + "-" + std::to_string(partidos[p].golesVisitante); //std::to_string convierte los numeros a cadenas de texto

            m[indiceVisitante + 1][indiceLocal + 1] =
                std::to_string(partidos[p].golesVisitante) + "-" + std::to_string(partidos[p].golesLocal);
        }
    }
}

inline void mostrarMatriz(const std::string m[MAX_EQUIPOS + 1][MAX_EQUIPOS + 1]) {

    std::cout << "\n--- MATRIZ DE ENFRENTAMIENTOS ---\n";

    for (int fila = 0; fila < MAX_EQUIPOS + 1; fila++) {

        for (int columna = 0; columna < MAX_EQUIPOS + 1; columna++) {

            std::cout << std::left << std::setw(15) << m[fila][columna];

        }

        std::cout << std::endl;
    }
}

inline void consultarMatriz(const Equipo equipos[], const Partido partidos[], bool simulacionHecha) {

    if (!simulacionHecha) {
        std::cout << "Primero debes simular el torneo.\n";
        return;
    }

    std::string matriz[MAX_EQUIPOS + 1][MAX_EQUIPOS + 1];

    prepararMatriz(equipos, partidos, matriz);

    mostrarMatriz(matriz);

    int mayorGoles = equipos[0].GF;
    int menorGolesContra = equipos[0].GC;

    int indiceAtaque = 0;
    int indiceDefensa = 0;

    for (int i = 1; i < MAX_EQUIPOS; i++) {

        if (equipos[i].GF > mayorGoles) {
            mayorGoles = equipos[i].GF;
            indiceAtaque = i;
        }

        if (equipos[i].GC < menorGolesContra) {
            menorGolesContra = equipos[i].GC;
            indiceDefensa = i;
        }
    }

    std::cout << "\nMejor ataque: "
          << equipos[indiceAtaque].nombre
          << " (" << mayorGoles << " goles a favor)\n";

    std::cout << "Mejor defensa: "
          << equipos[indiceDefensa].nombre
          << " (" << menorGolesContra << " goles en contra)\n";
}
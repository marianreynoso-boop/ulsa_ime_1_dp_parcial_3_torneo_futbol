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
                            std::string m[MAX_EQUIPOS + 1][MAX_EQUIPOS + 1]) {
std::string abreviaturas[MAX_EQUIPOS];

    for (int fila = 0; fila < MAX_EQUIPOS + 1; fila++) {
        for (int columna = 0; columna < MAX_EQUIPOS + 1; columna++) {
        m[fila][columna] = "";
        }
    }

    for (int i = 0; i < MAX_EQUIPOS; i++) {
        abreviaturas[i] = equipos[i].nombre.substr(0,3);
   
        for (int j = 0; j < MAX_EQUIPOS; j++) {
            abreviaturas[i][j] = toupper(abreviaturas[i][j]);
        }
    }

    for (int columna = 1; columna < MAX_EQUIPOS + 1; columna++) {
        m[0][columna] = abreviaturas[columna - 1];
    }

    for (int fila = 1; fila < MAX_EQUIPOS + 1; fila++) {
        m[fila][0] = equipos[fila - 1].nombre;
    }

}

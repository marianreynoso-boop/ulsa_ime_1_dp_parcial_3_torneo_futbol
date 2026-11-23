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

inline void prepararMatriz(const Equipo Equipos[], 
                            std::string m[MAX_EQUIPOS + 1][MAX_EQUIPOS + 1]) {
std::string abreviaturas[MAX_EQUIPOS];

for (int fila = 0; fila < MAX_EQUIPOS + 1; fila++) {
    for (int columna = 0; columna < MAX_EQUIPOS + 1; columna++) {
        m[fila][columna] = "";
    }
}

}

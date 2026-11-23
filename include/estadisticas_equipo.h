#pragma once

#include <cctype>
#include <string>
#include "torneo.h"

inline std::string aMinusculasEstadisticas(const std::string& texto) {
    std::string resultado = texto;
    for (size_t i = 0; i < resultado.size(); ++i) {
        resultado[i] = static_cast<char>(
            std::tolower(static_cast<unsigned char>(resultado[i]))
        );
    }
    return resultado;
}

inline void reiniciarEstadisticas(Equipo (&equipos)[MAX_EQUIPOS], int cantidadEquipos) {
    for (int i = 0; i < cantidadEquipos; ++i) {
        equipos[i].PJ = 0;
        equipos[i].PG = 0;
        equipos[i].PE = 0;
        equipos[i].PP = 0;
        equipos[i].GF = 0;
        equipos[i].GC = 0;
        equipos[i].PTS = 0;
    }
}

inline int buscarIndiceEquipo(const Equipo (&equipos)[MAX_EQUIPOS],
                                int cantidadEquipos,
                                const std::string& nombreBuscado) {
    const std::string objetivo = aMinusculasEstadisticas(nombreBuscado);

    for (int i = 0; i < cantidadEquipos; ++i) {
        if (aMinusculasEstadisticas(equipos[i].nombre) == objetivo) {
          return i;
        }
    }

    return -1;
}


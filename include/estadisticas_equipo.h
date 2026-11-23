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
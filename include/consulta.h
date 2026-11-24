#pragma once

#include <iomanip>
#include <iostream>
#include <string>
#include "torneo.h"
#include "utilerias.h"

void mostrarEquipos(const Equipo arregloEquipos[], int totalEquipos);

const Equipo* buscarEquipo(const Equipo arregloEquipos[], int totalEquipos, std::string nombreBuscado);

void mostrarFichaEquipo(const Equipo arregloEquipos[], int totalEquipos);

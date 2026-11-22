#include <iostream>
#include "consulta.h"

 void mostrarEquipos(const Equipo arregloEquipos[], int totalEquipos) {
            if (totalEquipos == 0){
            std::cout << " No hay equipos registrados ";
            return ;
        }
        for (int i = 0; i < totalEquipos; i++){
            std::cout << arregloEquipos[i].nombre << "\n";
        }
    }

const Equipo* buscarEquipo(const Equipo arregloEquipos[], int totalEquipos, std::string nombreBuscado) {
    for (int i = 0; i < totalEquipos; i++) 
    if (arregloEquipos[i].nombre == nombreBuscado) {
        return &arregloEquipos[i];
    }
    return nullptr;
}

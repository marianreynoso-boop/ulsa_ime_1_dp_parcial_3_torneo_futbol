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
int mostrarFichaEquipo(const Equipo arregloEquipos[], int totalEquipos){
    std::string nombreBuscado;
    std::cout <<"Ingrese el nombre del equipo a consultar: ";
    std::cin >> nombreBuscado;

const Equipo* equipoEncontrado = buscarEquipo(arregloEquipos, totalEquipos, nombreBuscado);

if (equipoEncontrado != nullptr) {
    std::cout <<"\n--- FICHA DE EQUIPO ---\n";
    std::cout <<"Equipo: " <<equipoEncontrado->nombre<< "\n";
    std::cout <<"Jugados: " <<equipoEncontrado->PJ<< "\n";
    std::cout <<"Ganados: " <<equipoEncontrado->PG<< "\n";
    std::cout <<"Empatados: " <<equipoEncontrado->PE<< "\n";
    std::cout <<"Perdidos: " <<equipoEncontrado->PP<< "\n";
    std::cout <<"Goles a favor: " <<equipoEncontrado->GF<< "\n";
    std::cout <<"Goles en contra: " <<equipoEncontrado->GC<< "\n";
    std::cout <<"Puntos: " <<equipoEncontrado->PTS<< "\n";
    } else {
 std::cout << "NO SE ENCONTRO NINGUN EQUIPO LLAMADO: " << nombreBuscado << "\n";
    }
}
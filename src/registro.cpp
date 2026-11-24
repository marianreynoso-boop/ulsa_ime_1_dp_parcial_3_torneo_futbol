#include <iostream> 
#include "registro.h"
void registrarEquipo(Equipo arregloEquipos[], int &totalEquipos)  { 
if (totalEquipos >= MAX_EQUIPOS) { 
std::cout << "Error: El torneo esta lleno. Maximo de equipos alcanzado.\n"; 
return; 
}

   

std::cout << "Ingresa el nombre del nuevo equipo: "; 
std::string nuevoNombre; 

  
std::cin.ignore();  
std::getline(std::cin, nuevoNombre);

arregloEquipos[totalEquipos].nombre = nuevoNombre; 
arregloEquipos[totalEquipos].PTS = 0; // Puntos 
arregloEquipos[totalEquipos].PJ = 0;  // Partidos Jugados 
arregloEquipos[totalEquipos].PG = 0;  // Partidos Ganados 
arregloEquipos[totalEquipos].PE = 0;  // Partidos Empatados 
arregloEquipos[totalEquipos].PP = 0;  // Partidos Perdidos 
arregloEquipos[totalEquipos].GF = 0;  // Goles a Favor 
arregloEquipos[totalEquipos].GC = 0;  // Goles en Contra
arregloEquipos[totalEquipos].DIF = 0; // Diferencia de Goles 
    
totalEquipos++; 
std::cout << "\n¡Equipo '" << nuevoNombre << "' registrado con exito!\n";
}
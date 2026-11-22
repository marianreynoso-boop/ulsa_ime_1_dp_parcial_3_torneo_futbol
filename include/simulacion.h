#pragma once

#include<iostream>
#include<iomanip>
#include<string>
#include <torneo.h>
#include <utilerias.h>
#include <escenario_prueba.h> 

using namespace std;
bool simulartorneo (const Equipo [],int numEquipos, Partido partidos[], int &numPartidos, bool&ya simulado){
if (numEquipos <MAX_EQUIPOS){
 cout<< "Error: Debes registrar los "<< MAX_Equipos <<" equipos antes de simular./n";
 return false; 
}
if (ya )
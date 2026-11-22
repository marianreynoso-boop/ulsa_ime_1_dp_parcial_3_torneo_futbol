#pragma once

#include<iostream>
#include<iomanip>
#include<string>
#include <torneo.h>
#include <utilerias.h>
#include <escenario_prueba.h> 

using namespace std;
bool simulartorneo (const Equipo [],int numEquipos, Partido partidos[], int &numPartidos, bool& yasimulado){
if (numEquipos <MAX_EQUIPOS){
 cout<< "Error: Debes registrar los "<< MAX_EQUIPOS <<" equipos antes de simular.\n";
 return false; 
}
if (yasimulado) {
        cout << "Error: El torneo ya fue simulado anteriormente.\n";
        return false;
    }
cout << "\n--- MODO DE SIMULACION ---\n";
    cout << "1. Modo Aleatorio\n";
    cout << "2. Modo de Prueba\n";

    int modo = leerEntero("Elige una opcion: ");
    while (modo != 1 && modo != 2) {
        cout << "Opcion no valida. Elige 1 o 2.\n";
        modo = leerEntero("Elige una opcion: ");
    }

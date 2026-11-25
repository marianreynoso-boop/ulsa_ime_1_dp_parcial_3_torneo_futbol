// Proyecto Parcial 3: Sistema de Gestion de un Torneo de Futbol
// Programa principal (bloque de integracion, de todo el equipo).
//
// Compilar (desde la carpeta del proyecto):
//   g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o torneo
// Ejecutar en macOS:
//   ./torneo
// Ejecutar en Windows:
//   .\torneo.exe
//
// Lean PROYECTO.md antes de escribir codigo.

#include <iostream>
#include <string>
#include <iomanip>

#include "utilerias.h"
#include "torneo.h"

// TODO: incluyan aqui el archivo .h de cada modulo.
#include "clasificacion_campeon.h"
#include "consulta.h"
#include "escenario_prueba.h"
#include "simulacion.h"
#include "estadisticas_equipo.h"
#include "registro.h"
#include "matriz.h"
 // TODO: declaren aqui los datos del torneo.
    //       No usen variables globales.
int main() {
   
    Equipo equipos[MAX_EQUIPOS];
    Partido partidos[TOTAL_PARTIDOS];
    int totalEquipos = 0;
   int totalPartidos = 0;
   bool simulacionHecha = false;

    std::cout << "Ingresa tu nombre: ";
    std::string nombre;
    std::getline(std::cin, nombre);
    std::cout << "Hola " << nombre << "\n";
    std::cout << "Bienvenido al Sistema de Gestion del Torneo de Futbol\n";

    int opcion = 0;

    while (opcion != 9) {
        std::cout << "\nSelecciona una opcion:\n";
        std::cout << "1. Registrar Equipo\n";
        std::cout << "2. Mostrar equipos\n";
        std::cout << "3. Simular torneo\n";
        std::cout << "4. Mostrar resultados\n";
        std::cout << "5. Mostrar tabla de posiciones\n";
        std::cout << "6. Mostrar Campeon\n";
        std::cout << "7. Consultar Equipo\n";
        std::cout << "8. Mostrar matriz de enfrentamientos\n";
        std::cout << "9. Salir\n";
       
        opcion = leerEntero("Ingresa tu opcion: "); 
                
    switch (opcion) {
        case 1:
        registrarEquipo(equipos, totalEquipos); 
        break;
            case 2:
            std::cout << "Lista de Equipos Registrados:\n"; 
            mostrarEquipos(equipos, totalEquipos); 
            break;
                case 3:
                std::cout<< "Simulacion de torneo \n";
                calcularEstadisticasEquipos(equipos, partidos);
                break;
                    case 4:
                    mostrarResultados(partidos, totalPartidos, simulacionHecha);
                    break;
                        case 5:
                        std::cout<< "Tabla de Posiciones: \n";
                        break;
                            case 6:
                            std::cout<< "CAMPEON: \n";
                            break;
    
                                case 7: 
                                mostrarFichaEquipo(equipos, totalEquipos);
                                break;
                                    case 8:
                                    consultarMatriz(equipos, partidos, simulacionHecha);
                                    break;
                                        case 9:
                                        break;
            } //cierra el switch
    } //cierra el while
    return 0;
} //cierra el int main

    // TODO: menu que se repite hasta elegir "Salir".
    //       Una opcion que no existe se rechaza con un mensaje.
    // El menu debe permitir ejecutar el escenario obligatorio, en este orden:
    //
    // Paso 1: elegir cada reporte sin equipos registrados (rechazos).
    // Paso 2: intentar simular sin los 6 equipos (rechazo).
    // Paso 3: registrar 6 equipos. Durante el registro, teclear un nombre
    //         repetido con otras mayusculas o minusculas, uno de menos de
    //         3 caracteres, uno de mas de 15 y uno con acento o enie
    //         (rechazos).
    // Paso 4: intentar registrar un equipo mas (rechazo por lista llena).
    // Paso 5: simular en modo de prueba.
    // Paso 6: intentar simular de nuevo (rechazo).
    // Paso 7: mostrar equipos, resultados, tabla y matriz.
    // Paso 8: mostrar al campeon y elegirlo entre los empatados.
    // Paso 9: consultar un equipo existente y uno inexistente (rechazo).
    // Paso 10: teclear una opcion de menu inexistente (rechazo) y salir.
    // Paso 11: ejecutar de nuevo el programa en modo aleatorio y mostrar
    //          resultados, tabla y campeon.
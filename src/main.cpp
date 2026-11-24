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
            if (totalEquipos >= MAX_EQUIPOS) {
                std::cout << "Error: La lista de equipos esta llena.\n";
                break;
            }

            while (true) {
                std::string nombreEquipo = leerCadena("Ingrese nombre del equipo a registrar: ");

                if (nombreEquipo.size() < MIN_CARACTERES_NOMBRE ||
                    nombreEquipo.size() > MAX_CARACTERES_NOMBRE) {
                    std::cout << "Error: El nombre debe tener entre 3 y 15 caracteres.\n";
                    continue;
                }

                bool valido = true;
                for (int i = 0; i < (int)nombreEquipo.size(); i++) {
                    unsigned char letra = (unsigned char)nombreEquipo[i];
                    if (letra >= 128) {
                        valido = false;
                    }
                }

                if (!valido) {
                    std::cout << "Error: El nombre no puede tener acentos ni enie.\n";
                    continue;
                }

                bool repetido = false;
                for (int i = 0; i < totalEquipos; i++) {
                    if (aMinusculasEstadisticas(equipos[i].nombre) ==
                        aMinusculasEstadisticas(nombreEquipo)) {
                        repetido = true;
                    }
                }

                if (repetido) {
                    std::cout << "Error: Ese equipo ya esta registrado.\n";
                    continue;
                }

                equipos[totalEquipos].nombre = nombreEquipo;
                totalEquipos++;
                std::cout << "Equipo registrado con exito.\n";
                break;
            }
            break;
        case 2:
            std::cout << "Lista de Equipos Registrados:\n"; 
            mostrarEquipos(equipos, totalEquipos); 
            std::cout<< "---Equipos Registrados--- \n" ;
            break;
                case 3:
                    simulartorneo(equipos, totalEquipos, partidos, totalPartidos, simulacionHecha);
                    break;
                    case 4:
                    if (!simulacionHecha) {
                        std::cout << "Primero debes simular el torneo.\n";
                    } else {
                        std::cout << "--- RESULTADOS DE LOS PARTIDOS ---\n";
                        std::cout << std::left << std::setw(4) << "#"
                                  << std::left << std::setw(17) << "LOCAL"
                                  << std::left << std::setw(10) << "MARCADOR"
                                  << std::left << std::setw(17) << "VISITANTE" << "\n";
                        for (int i = 0; i < totalPartidos; i++) {
                            std::string marcador = std::to_string(partidos[i].golesLocal)
                                                 + " - "
                                                 + std::to_string(partidos[i].golesVisitante);
                            std::cout << std::left << std::setw(4) << (i + 1)
                                      << std::left << std::setw(17) << partidos[i].local
                                      << std::left << std::setw(10) << marcador
                                      << std::left << std::setw(17) << partidos[i].visitante << "\n";
                        }
                    }
                    break;
                        case 5:
                        std::cout<< "Tabla de Posiciones: \n";
                        break;
                            case 6:
                            std::cout<< "CAMPEON: \n";
                            break;
                                
                                case 7: {
                                const int mostrarFichaEquipo(const Equipo arregloEquipos[], int totalEquipos);
                                break;
        
        case 9:
        break;
           
    }
    } return 0;
}
  

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
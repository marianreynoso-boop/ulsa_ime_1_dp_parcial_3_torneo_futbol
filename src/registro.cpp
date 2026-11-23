void registrarEquipo(Equipo arregloEquipos[], int &totalEquipos)  { 
    // 
1. Tope de seguridad: Verificar que no exceda el límite del 
torneo 
if (totalEquipos >= MAX_EQUIPOS) { 
std::cout << "Error: El torneo esta lleno. Maximo de equipos 
alcanzado.\n"; 
return; 
}

  // 
2. Pedir los datos al usuario 
std::cout << "Ingresa el nombre del nuevo equipo: "; 
std::string nuevoNombre; 

  // 
Usamos getline en lugar de cin por si el equipo tiene espacios 
(ej. "Real Madrid") 
    // 
std::cin.ignore(); // (Nota: Si se salta la lectura en la 
terminal, descomenta esta línea) 
std::getline(std::cin, nuevoNombre);

 // 
3. Registrar el nombre en el espacio disponible (la posición de 
totalEquipos) 
arregloEquipos[totalEquipos].nombre = nuevoNombre; 
    // 
4. Inicializar todas las estadísticas en 0 para empezar limpios 
arregloEquipos[totalEquipos].PTS = 0; // Puntos 
arregloEquipos[totalEquipos].PJ = 0;  // Partidos Jugados 
arregloEquipos[totalEquipos].PG = 0;  // Partidos Ganados 
arregloEquipos[totalEquipos].PE = 0;  // Partidos Empatados 
arregloEquipos[totalEquipos].PP = 0;  // Partidos Perdidos 
arregloEquipos[totalEquipos].GF = 0;  // Goles a Favor 
arregloEquipos[totalEquipos].GC = 0;  // Goles en Contra
arregloEquipos[totalEquipos].DIF = 0; // Diferencia de Goles 
    // 
5. ¡Aumentar el contador oficial del torneo! 
totalEquipos++; 
std::cout << "\n¡Equipo '" << nuevoNombre << "' registrado con 
exito!\n";
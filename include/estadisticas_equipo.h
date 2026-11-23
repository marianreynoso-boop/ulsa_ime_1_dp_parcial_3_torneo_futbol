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
//para reiniciar las estads d los equipos:
inline void reiniciarEstadisticas(Equipo (&equipos)[MAX_EQUIPOS], int cantidadEquipos) {
    for (int i = 0; i < cantidadEquipos; ++i) {
       
        equipos[i].PJ = 0;
        equipos[i].PG = 0;
        equipos[i].PE = 0;
        equipos[i].PP = 0;
        equipos[i].GF = 0;
        equipos[i].GC = 0;
        equipos[i].PTS = 0;

    }
}

inline int buscarIndiceEquipo(const Equipo (&equipos)[MAX_EQUIPOS],
  int cantidadEquipos,
  const std::string& nombreBuscado) {
    const std::string objetivo = aMinusculasEstadisticas(nombreBuscado);

    for (int i = 0; i < cantidadEquipos; ++i) {
        if (aMinusculasEstadisticas(equipos[i].nombre) == objetivo) {
          return i;
        }
    }

    return -1;
}


inline void acumularResultadoPartido(Equipo& equipoLocal,
                                   Equipo& equipoVisitante,
                                   int golesLocal,
                                   int golesVisitante) {
    equipoLocal.PJ += 1;
    equipoVisitante.PJ += 1;

    equipoLocal.GF += golesLocal;
    equipoLocal.GC += golesVisitante;
    equipoVisitante.GF += golesVisitante;
    equipoVisitante.GC += golesLocal;

    
    if (golesLocal > golesVisitante) {
        equipoLocal.PG += 1;
        equipoLocal.PTS += PUNTOS_VICTORIA;
        equipoVisitante.PP += 1;
        equipoVisitante.PTS += PUNTOS_DERROTA;
    } else if (golesLocal < golesVisitante) {
        equipoVisitante.PG += 1;
        equipoVisitante.PTS += PUNTOS_VICTORIA;
        equipoLocal.PP += 1;
        equipoLocal.PTS += PUNTOS_DERROTA;
    } else {
        //equipolocal.PE += PUNTOS_EMPATE;
        //equipoVisitante += 1;
        //equipoVisitante.PTS += PUNTOS_EMPATE;
    }
 }
                            
 inline void calcularEstadisticasEquipos(Equipo (&equipos)[MAX_EQUIPOS],
   const Partido (&partidos)[TOTAL_PARTIDOS]) {
    reiniciarEstadisticas(equipos, MAX_EQUIPOS);

    for (int p = 0; p < TOTAL_PARTIDOS; ++p) {
    const int idxLocal = buscarIndiceEquipo(equipos, MAX_EQUIPOS, partidos[p].local);
    const int idxVisitante = buscarIndiceEquipo(equipos, MAX_EQUIPOS, partidos[p].visitante);

    if (idxLocal != -1 && idxVisitante != -1) {
        acumularResultadoPartido(
            equipos[idxLocal],
            equipos[idxVisitante],
            partidos[p].golesLocal,
            partidos[p].golesVisitante
        );
    }
}
   }
        
  
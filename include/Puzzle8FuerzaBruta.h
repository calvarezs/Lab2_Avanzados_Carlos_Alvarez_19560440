#ifndef PUZZLE_8_FUERZA_BRUTA_H
#define PUZZLE_8_FUERZA_BRUTA_H
#include "Includes.h"

/*
Procedimiento que calcula los movimientos minimos necesarios para resolver un puzzle 8
Entradas:   *Un puzzle que indica el estado actual del puzzle
            *Un puzzle que indica al puzzle al que quiero llegar
            *Una lista con todos los estados de puzzle generados
            *La lista con valores, cada uno representando la cantidad de movimientos    
                necesarios para resolver el puzzle de alguna forma
*/

void Puzzle8FuerzaBruta(Puzzle* estadoActual,
                        Puzzle* estadoObjetivo,
                        ListaPuzzle* listaEstados,
                        Lista* listaExitos, 
                        int nMovimientos);

#endif
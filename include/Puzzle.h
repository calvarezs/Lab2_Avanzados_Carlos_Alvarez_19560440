#ifndef PUZZLE_H
#define PUZZLE_H
#include "Includes.h"
//TDA para puzzle

//DEFINCION nodo
typedef struct Puzzle
{
	char* Estado;
	struct Puzzle* Siguiente; 
}Puzzle;   

//Funcion constructor
Puzzle* CrearPuzzle(char* palabra);

//Funcion mostrar
void MostrarPuzzle(Puzzle* estadoActual);

//Funcion obtener
int son_iguales(Puzzle* PuzzleA, Puzzle* PuzzleB);

//Funcion modificar
Puzzle* mover_pieza_hacia(int direccion, Puzzle* puzzle);

//Funcion anular
void AnularPuzzle(Puzzle* Puzzle);

#endif
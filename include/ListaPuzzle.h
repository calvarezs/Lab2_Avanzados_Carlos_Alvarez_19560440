#ifndef LISTA_PUZZLE_H
#define LISTA_PUZZLE_H
#include "Includes.h"
//TDA para lista de puzzle
typedef struct ListaPuzzle
{
	Puzzle* Cabeza;
	Puzzle* Cola;

}ListaPuzzle;   

//Funcion constructor
ListaPuzzle* CrearListaPuzzleNueva();

//Funcion Modificar;
ListaPuzzle* AppendListaPuzzle(ListaPuzzle* listaPuzzle, Puzzle* cola);

//Funcion obtener
int ExisteEnListaPuzzle(ListaPuzzle* listaPuzzle, Puzzle* puzzle);

//Funcion verificar propiedad
Puzzle* es_posible_mover_pieza_hacia(int direccion, Puzzle* puzzle, ListaPuzzle* listaPuzzle);

//Funcion anular
void AnularListaPuzzle(ListaPuzzle* listaPuzzle);

#endif
#include "Includes.h"
//TDA para lista de puzzle
//Constructor

Puzzle* CrearPuzzle(char* palabra)
{
	Puzzle* nueva = (Puzzle*) malloc(sizeof(Puzzle)); 
	nueva->Estado = palabra;
	nueva->Siguiente = NULL;
	return nueva;
}

//Funcion obtener
int son_iguales(Puzzle* PuzzleA, Puzzle* PuzzleB)
{
	if(strcmp(PuzzleA->Estado, PuzzleB->Estado)==0)
	{
		return TRUE;
	}
	return FALSE;
}

//FUNCION MOSTRAR
void MostrarPuzzle(Puzzle* estadoActual)
{
	printf("|%c|%c|%c|\n", estadoActual->Estado[0], estadoActual->Estado[1], estadoActual->Estado[2]);
	printf("|%c|%c|%c|\n", estadoActual->Estado[3], estadoActual->Estado[4], estadoActual->Estado[5]);  
	printf("|%c|%c|%c|\n", estadoActual->Estado[6], estadoActual->Estado[7], estadoActual->Estado[8]);
}

//Funcion modificar
Puzzle* mover_pieza_hacia(int direccion, Puzzle* puzzle)
{
	char* palabra;
	char piezaDesplazada;
	int posX, posCont;

	//Ubicar pieza vacia 'x'
	int i = 0;
	while(i < N_PIEZAS_PUZZLE)
	{
		if(!isdigit(puzzle->Estado[i]))
		{
			posX = i; 
			i = N_PIEZAS_PUZZLE;
		}
		i++;
	}

	palabra = (char*) malloc (LARGO_PALABRA_PUZZLE*sizeof(char));
	strcpy(palabra,puzzle->Estado); 

	//Para cada caso ubicar pieza continua en direccion opuesta al movimiento
	switch(direccion)
	{
		case ARRIBA: 
			posCont = posX + ANCHO_PUZZLE; 
			break;
		case ABAJO: 
			posCont = posX - ANCHO_PUZZLE; 
			break;
		case IZQUIERDA: 
			posCont = posX + 1; 
			break;
		case DERECHA: 
			posCont = posX - 1; 
			break;
	}

	//Despues intercambiar de lugares las piezas vacia y continua
	piezaDesplazada = palabra[posCont];
	palabra[posCont] = 'x';
	palabra[posX] = piezaDesplazada; 

	return CrearPuzzle(palabra);
}

//Funcion anular
void AnularPuzzle(Puzzle* Puzzle)
{   
	if(Puzzle->Estado != NULL)
	{ 
		free(Puzzle->Estado);
	} 
	free(Puzzle);    
	return;
} 
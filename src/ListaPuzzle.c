#include "Includes.h"
//TDA para lista de puzzle
//Constructor

ListaPuzzle* CrearListaPuzzleNueva()
{
	ListaPuzzle* nueva = (ListaPuzzle*) malloc(sizeof(ListaPuzzle)); 
	nueva->Cabeza = NULL;
	nueva->Cola = NULL;
	return nueva;
}

//Funcion Modificar;
ListaPuzzle* AppendListaPuzzle(ListaPuzzle* listaPuzzle, Puzzle* cola)
{ 

	if(listaPuzzle->Cabeza == NULL)
	{
		listaPuzzle->Cabeza = cola; 
		listaPuzzle->Cola = cola;
	}
	else
	{ 
		listaPuzzle->Cola->Siguiente = cola;
		listaPuzzle->Cola = cola;
	}
	return listaPuzzle;
}

//Funcion obtener
int ExisteEnListaPuzzle(ListaPuzzle* listaPuzzle, Puzzle* puzzle)
{
	Puzzle* nodoActual = listaPuzzle->Cabeza;
	while(nodoActual != NULL)
    { 
    	if(strcmp(nodoActual->Estado,puzzle->Estado)==0)
    	{
    		return TRUE;
    	}

    	nodoActual = nodoActual->Siguiente;
    } 
	return FALSE;
}


//Funcion verificar propiedad
Puzzle* es_posible_mover_pieza_hacia(int direccion, Puzzle* puzzle, ListaPuzzle* listaPuzzle)
{	
	//Ubicar pieza vacia 'x'
	int posX;
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
	int es_movimiento_disponible;
	es_movimiento_disponible = FALSE;
	switch(direccion)
	{	
		//Si la pieza vacia esta abajo no se puede subir la pieza
		case ARRIBA:
			if(posX < 6)
			{  
				es_movimiento_disponible = TRUE;
			}
			break;
		//Si la pieza vacia esta arriba no se puede subir la pieza	
		case ABAJO:
			if(posX > (ANCHO_PUZZLE - 1))
			{ 
				es_movimiento_disponible = TRUE;
			}
			break;
		//Si la pieza vacia esta a la derecha no se puede subir la pieza
		case IZQUIERDA:
			if(posX%ANCHO_PUZZLE != 2)
			{ 
				es_movimiento_disponible = TRUE;
			}
			break;
		//Si la pieza vacia esta a la izquierda no se puede subir la pieza
		case DERECHA:
			if(posX%ANCHO_PUZZLE != 0)
			{ 
				es_movimiento_disponible = TRUE;
			}
			break; 
	} 
	if(es_movimiento_disponible == FALSE)
	{
		bugTracker("No es mov disponible\n");
		return NULL;
	}

	bugTracker("Mov disponible\n");

	//Se revisa que el nuevo puzzle no sea un valor repetido
	Puzzle* puzzle_posible = mover_pieza_hacia(direccion, puzzle);
	
	if(ExisteEnListaPuzzle(listaPuzzle, puzzle_posible) == FALSE);
	{
		bugTracker("Puzzle existe\n");
		//De ser asi se devuelve la lista puzzle modificada
		return puzzle_posible;
	} 
	bugTracker("Puzzle no existe\n");
	//Si no devolver la lista sin modificar
	AnularPuzzle(puzzle_posible);
	return NULL;
}

//Funcion anular
void AnularListaPuzzle(ListaPuzzle* listaPuzzle)
{ 
	Puzzle* nodoActual = listaPuzzle->Cabeza;
	while(nodoActual != NULL)
    {
    	AnularPuzzle(nodoActual);
    	nodoActual = nodoActual->Siguiente;
    }
    free(listaPuzzle); 
     
	return;
} 
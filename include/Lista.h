#ifndef LISTA_H
#define LISTA_H
#include "Includes.h"
//TDA para lista simple de numeros

//DEFINCION nodo
typedef struct nodo
{
	int Dato;
	struct nodo* Siguiente; 
}nodo;  

//DEFINCION Lista
typedef struct Lista
{ 
	nodo* Cabeza;
	nodo* Cola; 
}Lista;  

//TDA para lista simple de numeros
//Constructor
Lista* CrearListaNueva();

//Funcion Modificar;
Lista* AppendLista(Lista* lista, int dato);

//Funcion obtener
int ObtenerMinimoLista(Lista* lista);

//Funcion anular
void AnularLista(Lista* lista);

#endif
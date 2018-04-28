#include "Includes.h"
//TDA para lista simple de numeros
//Constructor
Lista* CrearListaNueva()
{
	Lista* nueva = (Lista*) malloc(sizeof(Lista)); 
	nueva->Cabeza = NULL;
	nueva->Cola = NULL;
	return nueva;
}

//Funcion Modificar;
Lista* AppendLista(Lista* lista, int dato)
{
	if(dato<0)
	{
		return lista;
	}
	nodo* nuevo = (nodo*) malloc(sizeof(nodo));
	nuevo->Dato = dato;
	nuevo->Siguiente = NULL;

	if(lista->Cabeza == NULL)
	{
		lista->Cabeza = nuevo; 
		lista->Cola = nuevo;
	}
	else
	{ 
		lista->Cola->Siguiente = nuevo;
		lista->Cola = nuevo;
	}
	return lista;
}

//Funcion obtener
int ObtenerMinimoLista(Lista* lista)
{
	if(lista==NULL || lista->Cabeza==NULL)
	{
		return -1;
	}

	nodo* nodoActual = lista->Cabeza;
	int minimo = nodoActual->Dato;

	while(nodoActual != NULL)
    {
    	if(nodoActual->Dato < minimo)
        {
            minimo = nodoActual->Dato;  
        }
        nodoActual = nodoActual->Siguiente;
    } 
	return minimo;
}

//Funcion anular
void AnularLista(Lista* lista)
{
	nodo* nodoActual = lista->Cabeza; 
	while(nodoActual != NULL)
    {
    	free(nodoActual);
    	nodoActual = nodoActual->Siguiente;
    }
    free(lista); 
	return;
}

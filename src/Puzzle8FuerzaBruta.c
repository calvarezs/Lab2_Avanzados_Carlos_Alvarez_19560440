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
                        int nMovimientos)
{ 
    //Si se llega al estado objetivo, añadir el contador de movimientos 
    //a la lista de resultados
    if(nMovimientos > 10)
    {
        return;
    }

    if(son_iguales(estadoActual,estadoObjetivo))
    {
        AppendLista(listaExitos, nMovimientos);
        bugTracker("Objetivo alcanzado\n");
        return;
    }
    if(ExisteEnListaPuzzle(listaEstados,estadoActual)==TRUE)
    {
        bugTracker("Estado pasado\n");
        AnularPuzzle(estadoActual);
        return;
    }
    else
    {
        listaEstados = AppendListaPuzzle(listaEstados, estadoActual);
    }

    bugTracker("Estado actual: \n");
    MostrarPuzzle(estadoActual);
    getchar();

    Puzzle* movimientoArriba = es_posible_mover_pieza_hacia(ARRIBA, estadoActual, listaEstados);
    Puzzle* movimientoAbajo = es_posible_mover_pieza_hacia(ABAJO, estadoActual, listaEstados);
    Puzzle* movimientoIzquierda = es_posible_mover_pieza_hacia(IZQUIERDA, estadoActual, listaEstados);
    Puzzle* movimientoDerecha = es_posible_mover_pieza_hacia(DERECHA, estadoActual, listaEstados);
   
    nMovimientos = nMovimientos + 1;

    //Si se puede mover la pieza arriba
    if(movimientoArriba != NULL)
    {
        bugTracker("Mover arriba\n"); 
        Puzzle8FuerzaBruta(movimientoArriba,estadoObjetivo,listaEstados,listaExitos,nMovimientos);
    }
    //si se puede mover la pieza abajo
    if(movimientoAbajo != NULL)
    {
        bugTracker("Mover abajo\n");  
        Puzzle8FuerzaBruta(movimientoAbajo,estadoObjetivo,listaEstados,listaExitos,nMovimientos);
    }
    //si se puede mover la pieza a la izquierda
    if(movimientoIzquierda != NULL)
    { 
        bugTracker("Mover izquierda\n"); 
        Puzzle8FuerzaBruta(movimientoIzquierda,estadoObjetivo,listaEstados,listaExitos,nMovimientos);
    } 
    //si se puede mover la pieza a la derecha
    if(movimientoDerecha != NULL)
    { 
        bugTracker("Mover derecha\n"); 
        Puzzle8FuerzaBruta(movimientoDerecha,estadoObjetivo,listaEstados,listaExitos,nMovimientos);
    }
    return;
}
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
    printf("\n----------Inicio de rama en altura %d---------\n\n",nMovimientos);
    //Limitador de movimientos, para computadoras de bajo rendimiento
    //Configuracion en archivo "Includes.h" en carpeta "include"
    //ADVERTENCIA: habilitar esta funcion interrumpe el algoritmo
    //             de fuerza bruta. Utilizar bajo su propio criterio.
    if(LIMITAR_MOVIMIENTOS == TRUE && nMovimientos > NUMERO_LIMITE_MOVIMIENTOS)
    {
        printf("Limite movimientos sobrepasado\n");
        return;
    }

    //Si se llega al estado objetivo, añadir el contador de movimientos 
    //a la lista de resultados
    if(son_iguales(estadoActual,estadoObjetivo))
    {
        AppendLista(listaExitos, nMovimientos);
        printf("Objetivo alcanzado\n");
        return;
    }
    if(ExisteEnListaPuzzle(listaEstados,estadoActual)==TRUE)
    {
        printf("Estado pasado\n");
        AnularPuzzle(estadoActual);
        return;
    }
    else
    {
        listaEstados = AppendListaPuzzle(listaEstados, estadoActual);
    }

    printf("Estado actual: \n");
    MostrarPuzzle(estadoActual);

    Puzzle* movimientoArriba = es_posible_mover_pieza_hacia(ARRIBA, estadoActual, listaEstados);
    Puzzle* movimientoAbajo = es_posible_mover_pieza_hacia(ABAJO, estadoActual, listaEstados);
    Puzzle* movimientoIzquierda = es_posible_mover_pieza_hacia(IZQUIERDA, estadoActual, listaEstados);
    Puzzle* movimientoDerecha = es_posible_mover_pieza_hacia(DERECHA, estadoActual, listaEstados);
   
    nMovimientos = nMovimientos + 1;

    //Si se puede mover la pieza arriba
    if(movimientoArriba != NULL)
    {
        printf("Mover arriba\n"); 
        Puzzle8FuerzaBruta(movimientoArriba,estadoObjetivo,listaEstados,listaExitos,nMovimientos);
    }
    //si se puede mover la pieza abajo
    if(movimientoAbajo != NULL)
    {
        printf("Mover abajo\n");  
        Puzzle8FuerzaBruta(movimientoAbajo,estadoObjetivo,listaEstados,listaExitos,nMovimientos);
    }
    //si se puede mover la pieza a la izquierda
    if(movimientoIzquierda != NULL)
    { 
        printf("Mover izquierda\n"); 
        Puzzle8FuerzaBruta(movimientoIzquierda,estadoObjetivo,listaEstados,listaExitos,nMovimientos);
    } 
    //si se puede mover la pieza a la derecha
    if(movimientoDerecha != NULL)
    { 
        printf("Mover derecha\n"); 
        Puzzle8FuerzaBruta(movimientoDerecha,estadoObjetivo,listaEstados,listaExitos,nMovimientos);
    }
    printf("Todas las combinaciones posibles de este nodo de la rama\nhan sido revisadas\n");
    printf("\n----------Fin de rama en altura %d---------\n\n",nMovimientos);
    return;
}
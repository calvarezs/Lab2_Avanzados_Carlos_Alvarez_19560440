#include "Includes.h"

int main()
{
    printf("/////////////Iniciando programa///////////////////\n");

    //Iniciar variables y estructuras de datos
    bugTracker("Iniciar variables y estructuras de datos\n");
    int nMovimientos;
    int resultado;
    char* nombreArchivoEntrada;
    char* nombreArchivoSalida;

    Lista* listaExitos; 

    Puzzle* estadoActual;
    Puzzle* estadoObjetivo;
    ListaPuzzle* listaEstados;

    //Iniciar memoria elementos
    estadoObjetivo = CrearPuzzle("x12345678"); 
    listaEstados = CrearListaPuzzleNueva();
    listaExitos = CrearListaNueva();

    //Obtener datos de archivo 
    nombreArchivoEntrada = (char*)malloc(MAXIMO_LARGO_NOMBRE*sizeof(char));
    nombreArchivoSalida = (char*)malloc(MAXIMO_LARGO_NOMBRE*sizeof(char));
    ObtenerNombresArchivosIO(nombreArchivoEntrada, nombreArchivoSalida); 

    //Leer archivo entrada 
    estadoActual = LeerArchivoInput(nombreArchivoEntrada); 

    //Ejecutar procedimiento principal 
    nMovimientos = 0;
    Puzzle8FuerzaBruta(estadoActual,estadoObjetivo,listaEstados,listaExitos, nMovimientos);

    //Si la lista de combinaciones exitosas contiene elementos
    resultado = ObtenerMinimoLista(listaExitos);

    //Imprimir resultado en archivo entrada 
    EscribirArchivoOutput(nombreArchivoSalida, resultado);

    //Liberar memoria utilizada  
        //Se anulan los nombres de archivo
    free(nombreArchivoEntrada);
    free(nombreArchivoSalida); 
        //Se anula la lista dinamica
    AnularLista(listaExitos);
        //Se anula el estado inicial  
    free(estadoObjetivo); 
        //Finalmente se libera la lista de estados de puzzle.
    AnularListaPuzzle(listaEstados); 

    printf("/////////////Fin de programa///////////////////////\n");
    return 0;
}
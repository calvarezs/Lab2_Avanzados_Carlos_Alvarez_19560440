#include "Includes.h"

Puzzle* LeerArchivoInput(char* nombreArchivoEntrada)
{
	bugTracker("Inicio de funcion LeerArchivoInput\n");
	
	FILE* archivo;
	char* palabra;
    Puzzle* estadoActual;

	palabra = (char*) malloc(LARGO_PALABRA_PUZZLE * sizeof(char));

    archivo = fopen(nombreArchivoEntrada, "r");
    if(!archivo)
    {	
    	printf("Archivo no encontrado\n"); 
        return NULL;
    } 

    fscanf(archivo, " %c %c %c ", &(palabra[0]), &(palabra[1]), &(palabra[2]));
    fscanf(archivo, " %c %c %c ", &(palabra[3]), &(palabra[4]), &(palabra[5]));
    fscanf(archivo, " %c %c %c ", &(palabra[6]), &(palabra[7]), &(palabra[8]));
    palabra[9] = '\0';

    fclose(archivo);

    //Crear resultado
    estadoActual = CrearPuzzle(palabra); 
    
	bugTracker("Fin de funcion LeerArchivoInput\n");	
    return estadoActual;
}
#include "Includes.h"

void EscribirArchivoOutput(char* nombreArchivoSalida, int resultado)
{
	bugTracker("Inicio de funcion LeerArchivoOutput\n");
	
	FILE* archivo; 
	archivo = fopen(nombreArchivoSalida,"w");
    fprintf(archivo, "La cantidad minima de movimientos es %d\n", resultado);
    fclose(archivo); 

	bugTracker("Fin de funcion LeerArchivoOutput\n");	
}
#include "Includes.h"

void EscribirArchivoOutput(char* nombreArchivoSalida, int resultado)
{
	bugTracker("Inicio de funcion LeerArchivoOutput\n");
	
	FILE* archivo; 
	archivo = fopen(nombreArchivoSalida,"w");
	if(resultado>0)
	{
		fprintf(archivo, "La cantidad minima de movimientos es %d\n", resultado);	
	}
	else
	{
		fprintf(archivo, "Resultado no encontrado\n");
	}
    
    fclose(archivo); 

	bugTracker("Fin de funcion LeerArchivoOutput\n");	
}
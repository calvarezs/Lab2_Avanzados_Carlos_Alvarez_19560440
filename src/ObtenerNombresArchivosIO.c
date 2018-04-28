#include "Includes.h"

void ObtenerNombresArchivosIO(char* nombreArchivoEntrada, char* nombreArchivoSalida)
{
	bugTracker("Incio funcion ObtenerNombresArchivosIO\n");
	FILE* fp;

	//obtener nombre archivo entrada
	do
    {
        printf("Nombre el archivo de entrada:\n");
        scanf("%s",nombreArchivoEntrada); 
        fp = fopen(nombreArchivoEntrada, "r");

        if(fp)
        {
			printf("Has seleccionado el archivo: \'%s\'\n", nombreArchivoEntrada);
        }
        else
        {
            printf("Archivo invalido. Por favor intente nuevamente.\n");
        }

    }while(fp == NULL);
    fclose(fp);
 
 	//Obtener nombre archivo salida
	printf("Nombre el archivo de salida:\n");
	scanf("%s",nombreArchivoSalida);  
	printf("Has seleccionado el archivo: \'%s\'\n", nombreArchivoSalida);

	bugTracker("Nombre archivo entrada: ");
	bugTracker(nombreArchivoEntrada);
	bugTracker("Nombre archivo salida: ");
	bugTracker(nombreArchivoSalida);
	bugTracker("\nFin funcion ObtenerNombresArchivosIO\n");
	return;
}
#ifndef INCLUDES_H
#define INCLUDES_H

//Definicion de librerias ANSI utilizadas
#include <stdio.h> 
#include <stdlib.h>  
#include <string.h>
#include <ctype.h>

//Definicion de librerias propias utilizadas
#include "bugTracker.h" 
#include "Lista.h"
#include "Puzzle.h"
#include "ListaPuzzle.h"
#include "ObtenerNombresArchivosIO.h"
#include "LeerArchivoInput.h"
#include "EscribirArchivoOutput.h"
#include "Puzzle8FuerzaBruta.h"

//Definicion de tipo de dato bool
#define TRUE 1
#define FALSE 0  

//Definicion constante DEBUG
#define DEBUG 1

//Definicion constantes direcciones
#define ARRIBA 0
#define ABAJO 1
#define IZQUIERDA 2
#define DERECHA 3

//Definicion otras constantes
#define ALTO_PUZZLE 3
#define ANCHO_PUZZLE 3
#define N_PIEZAS_PUZZLE 9
#define LARGO_PALABRA_PUZZLE 11 
#define MAXIMO_LARGO_NOMBRE 25
#endif
IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib 


_DEPS = Includes.h bugTracker.h Lista.h Puzzle.h ListaPuzzle.h ObtenerNombresArchivosIO.h LeerArchivoInput.h EscribirArchivoOutput.h Puzzle8FuerzaBruta.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o bugTracker.o Lista.o Puzzle.o ListaPuzzle.o ObtenerNombresArchivosIO.o LeerArchivoInput.o EscribirArchivoOutput.o Puzzle8FuerzaBruta.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


#Para Linux intercambiar a Puzzle8.out
#Para Windows intercambiar a Puzzle8.exe
#Ejecucion usando el comando 'make' en terminal o bloque de comandos segun corresponda
Puzzle8.out: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) 

.PHONY: clean

#Ejecutar comando 'make clean' en caso de cambio de código o cambio del sistema operativo usado

clean:
	rm -f $(ODIR)/*.o *.exe *.out




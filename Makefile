all: meuMain.o meuLU.o meuSistLineares.o
	gcc meuMain.o meuLU.o meuSistLineares.o -o meuMain

meuMain.o: meuMain.c
	gcc -c meuMain.c

meuLU.o: meuLU.c meuLU.h meuSistLineares.c meuSistLineares.h
	gcc -c meuLU.c

meuSistLineares.o: meuSistLineares.c meuSistLineares.h
	gcc -c meuSistLineares.c

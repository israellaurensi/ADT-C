#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
	int x;
} Elemento;

typedef struct fila {
	int ini;
	int fim;
	int tam;
	Elemento *vetor;
} Fila;


Fila* create_queue (int tam);

void enqueue (Fila *f, Elemento e);

Elemento dequeue (Fila *f);

int empty (Fila *f);

int full (Fila *f);

void free_queue (Fila *f);
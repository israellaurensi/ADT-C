#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
	int info;
	struct node* next;
} Lista;

void sortLista(Lista *lista);

void insertionSortLista(Lista *lista, int size);

Lista* getElemento(Lista* lista, int pos);

Lista* criar(void);

Lista* inserir(Lista* lista, int elem);

void imprimir(Lista *lista);

Lista* procurar(Lista* lista, int elem);

Lista* remover(Lista* lista, int elem);

void liberar(Lista* lista);
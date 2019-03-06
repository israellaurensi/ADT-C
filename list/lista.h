#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int info;
	struct node* prv;
	struct node* next;
} Lista;

Lista* criar(void);

Lista* inserir(Lista* lista, int elem);

void imprimir(Lista *lista);

Lista* procurar(Lista* lista, int elem);

Lista* remover(Lista* lista, int elem);

void liberar(Lista* lista);
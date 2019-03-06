#include "queue.h";

Fila* create_queue (int tam) {
	Fila *f = (Fila *)malloc(sizeof(Fila));
	f->ini = 0;
	f->fim = 0;
	f->tam = tam;
	f->vetor = (Elemento*)malloc(tam*sizeof(Elemento));
	
	return f;
}

void enqueue (Fila *f, Elemento e) {
	if (full(f)) {
		printf("fila cheia: capacidade esgotada!");
		exit(1); /*aborta programa*/
	}

	f->vetor[f->fim] = e; /*insere elemento*/
	f->fim = (f->fim + 1) % f->tam; /*incremento*/
}

Elemento dequeue (Fila *f) {
	if (empty(f)) {
		printf("fila vazia!");
		exit(1); /*aborta programa*/
	}

	Elemento v = f->vetor[f->ini]; /*guarda o elemento*/
	f->ini = (f->ini + 1) % f->tam; /*incremento*/
	
	return v;
}

int empty(Fila *f) {
	return (f->ini == f->fim);
}

int full(Fila *f) {
	return (f->ini == ((f->fim + 1) % f->tam));
}

void free_queue(Fila *f) {
	free(f->vetor);
	free(f);
}

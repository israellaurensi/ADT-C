#include "lista.h"

void sortLista(Lista *lista) {
	Lista *v;
	int k = 0;
	
	// contando numero de elementos na lista
	for (v = lista; v != NULL; v = v->next) k++;
	
	insertionSortLista(lista, k);
}

void insertionSortLista(Lista *lista, int size) {
	Lista *v;
	Lista *f;
	
	int key, k = 1, p;

	for (k = 1; k < size; k++) {
		v = getElemento(lista, k);
		key = v->info;
	
		p = k-1;
		while (key < getElemento(lista, p)->info && p >= 0) {
			v = getElemento(lista, p);
			f = getElemento(lista, p+1);
			
			f->info = v->info;
			p--;
		}
		
		f = getElemento(lista, p+1);
		f->info = key;
	}
}

Lista* getElemento(Lista* lista, int pos) {
	Lista *v = lista;
	int i = 0;
	while (i < pos) {
		v = v->next;
		i++;
	}
	
	return v;
}

Lista* criar(void) {
	return NULL;
}

Lista* inserir(Lista* lista, int elem) {
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->info = elem;
	novo->next = lista;
	
	return novo;
}

void imprimir(Lista* lista) {
	Lista *v;
	
	printf("\nLista: ");
	for (v = lista; v != NULL; v = v->next) {
		printf("[%d] ", v->info);
	}
	printf("\n\n");
}

Lista* procurar(Lista* lista, int elem) {
	Lista *v;
	
	for (v = lista; v != NULL; v = v->next) {
		if (v->info == elem) {
			return v;
		}
	}
	
	return NULL;
}

Lista* remover(Lista* lista, int elem) {
	Lista *prv = NULL;
	Lista *v = lista;
	
	while((v != NULL) && (v->info != elem)) {
		prv = v;
		v = v->next;
	}
	
	if (v == NULL) return lista;
	
	if (prv == NULL) {
		lista = v->next;
	} else {
		prv->next = v->next;
	}
	
	free(v);
	return lista;
}

void liberar(Lista* lista) {
	Lista *v;
	v = lista;
	
	while(v != NULL) {
		Lista* aux = v->next;
		free(v);
		v = aux;
	}
}
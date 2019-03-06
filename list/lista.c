#include "lista.h"

Lista* criar(void) {
	return NULL;
}

Lista* inserir(Lista* lista, int elem) {
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->info = elem;
	novo->next = lista;
	novo->prv = NULL;
	
	if (lista != NULL)
		lista->prv = novo;
	
	return novo;
}

void imprimir(Lista* lista) {
	Lista *v;
	
	for (v = lista; v != NULL; v = v->next) {
		printf("Valor: %d\n", v->info);
	}
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
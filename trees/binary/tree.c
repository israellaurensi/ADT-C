#include "tree.h"

Arvore* cria_arv_vazia (void) {
	return NULL;
}

Arvore* arv_constroi (int c, Arvore* e, Arvore* d) {
	Arvore* a = (Arvore*)malloc(sizeof(Arvore));
	a->info = c;
	a->esq = e;
	a->dir = d;
	
	return a;
}

int verifica_arv_vazia (Arvore* a) {
	return (a == NULL);
}

Arvore* arv_libera (Arvore* a) {
	if (!verifica_arv_vazia(a)) {
		arv_libera (a->esq);
		arv_libera (a->dir);
		free(a);
	}
	
	return NULL;
}

// imprime a arvore em pré-ordem
void arv_imprime_pre(Arvore* a) {
	if (!verifica_arv_vazia(a)) {
		printf("%d ", a->info);
		arv_imprime_pre(a->esq);
		arv_imprime_pre(a->dir);
	}
}

// imprime a arvore em in-ordem (ordem simétrica)
void arv_imprime_in(Arvore* a) {
	if (!verifica_arv_vazia(a)) {
		arv_imprime_in(a->esq);
		printf("%d ", a->info);
		arv_imprime_in(a->dir);
	}
}

// imprime a arvore em pós-ordem
void arv_imprime_pos(Arvore* a) {
	if (!verifica_arv_vazia(a)) {
		arv_imprime_pos(a->esq);
		arv_imprime_pos(a->dir);
		printf("%d ", a->info);
	}
}

int buscar (Arvore *a, int v) {
	if (a == NULL) { return 0; }
	
	else if (v < a->info) {
		return buscar (a->esq, v);
	}
	
	else if (v > a->info) {
		return buscar (a->dir, v);
	}
	
	else { return 1; }
}

Arvore* inserir (Arvore *a, int v) {
	if (a == NULL) {
		a = (Arvore*)malloc(sizeof(Arvore));
		a->info = v;
		a->esq = a->dir = NULL;
	}
	else if (v < a->info) {
		a->esq = inserir (a->esq, v);
	}
	else { a->dir = inserir (a->dir, v); }
	
	return a;
}

int min(Arvore* a) {
	int menor;
	Arvore *t;
	
	for (t = a; t != NULL; t = t->esq)
		menor = t->info;
		
	return menor;
}

int max(Arvore* a) {
	int maior;
	Arvore *t;
	
	for (t = a; t != NULL; t = t->dir)
		maior = t->info;
		
	return maior;
}

int checa_arv_busca(Arvore *a) {
	if (a != NULL) {
		if ((checa_arv_busca(a->esq) < a->info) && (checa_arv_busca(a->dir) > a->info)) return 0;
	}
	
	return 1;
}
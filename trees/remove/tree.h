#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct arvore {
	int info;
	struct arvore *esq;
	struct arvore *dir;
} Arvore;

Arvore* cria_arv_vazia (void);
Arvore* arv_constroi (int c, Arvore* e, Arvore* d);

int verifica_arv_vazia (Arvore* a);
Arvore* arv_libera (Arvore* a);
int arv_pertence (Arvore* a, int c);

int conta_nos(Arvore *a);
int conta_folhas(Arvore *a);
int max_arvore(Arvore *a);
Arvore* espelha_arvore_inPlace(Arvore *a);
Arvore* espelha_arvore(Arvore *a);

void arv_imprime (Arvore* a);
void arv_imprime_textual(Arvore* a);

void arv_imprime_pre(Arvore* a);
void arv_imprime_in(Arvore* a);
void arv_imprime_pos(Arvore* a);

int buscar (Arvore *a, int v);
Arvore* inserir (Arvore *a, int v);

Arvore* remover(Arvore *a, int elem);

int min(Arvore* a);
int max(Arvore* a);
#include <stdio.h>
#include <stdlib.h>

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
void arv_imprime (Arvore* a);
void arv_imprime_textual(Arvore* a);
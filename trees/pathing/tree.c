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
// imprime primeira a raiz, depois o nó esquerdo e depois o nó direito
void arv_imprime_pre(Arvore* a) {
	if (!verifica_arv_vazia(a)) {
		printf("%d ", a->info);
		arv_imprime_pre(a->esq);
		arv_imprime_pre(a->dir);
	}
}

// imprime a arvore em in-ordem (ordem simétrica)
// imprime primeiro a raiz, depois o nó esquerdo e depois o nó direito
void arv_imprime_in(Arvore* a) {
	if (!verifica_arv_vazia(a)) {
		arv_imprime_in(a->esq);
		printf("%d ", a->info);
		arv_imprime_in(a->dir);
	}
}

// imprime a arvore em pós-ordem
// imprime primeiro o nó esquerdo, depois o nó direito e depois a raiz
void arv_imprime_pos(Arvore* a) {
	if (!verifica_arv_vazia(a)) {
		arv_imprime_pos(a->esq);
		arv_imprime_pos(a->dir);
		printf("%d ", a->info);
	}
}

// conta a quantidade de nós de uma arvore
// para cada chamada recursiva, será criado um contador
// esse contador além de incrementar o contador para 1 (pois tem que contar o nó que está no momento)
// ele recebe o soma dos outros contadores dos nós filhos (estrutura da chamada recursiva)
/*

			1
		2		5
	3	4		6	7
	
	soma 1 = 1 ...
	soma 2 = 1 ...
	soma 3 = 1, retorna
	soma 2 = 1 + soma 3 ...
	soma 4 = 1, retorna
	soma 2 = 1 + soma 3 + soma 2 = 3, retorna
	soma 1 = 1 + soma 2 ...
	soma 5 = 1 ...
	soma 6 = 1, retorna
	soma 5 = 1 + soma 6 ...
	soma 7 = 1, retorna
	soma 5 = 1 + soma 6 + soma 7 = 3, retorna
	soma 1 = 1 + soma 2 + soma 5 = 1 + 3 + 3 = 7
	total nós = 7

*/
int conta_nos(Arvore *a) {
	int sum = 0;

	if (!verifica_arv_vazia(a)) {
		sum++;
		sum += conta_nos(a->esq);
		sum += conta_nos(a->dir);
	}
	
	return sum;
}

// conta o número de folhas de uma arvore
// cada chamada recursiva possui uma variavel
// essa variavel vai receber o soma de quantos nós folhas as outras chamadas contaram
// um nó é folha se ambos seus filhos são nulos
// ou seja, a partir do momento que tanto a->esq quanto a->dir forem nulos, retorna 1
// pois o nó a é uma folha
/*

			1
		2		5
	3	4		6	7
	
	fol 1 = 0
	fol 2 = 0
	fol 3 = 1, retorna
	fol 2 = 1
	fol 4 = 1, retorna
	fol 2 = 2, retorna
	fol 1 = 2
	fol 5 = 0
	fol 6 = 1, retorna
	fol 5 = 1
	fol 7 = 1, retorna
	fol 5 = 2, retorna
	fol 1 = 4, retorna

*/
int conta_folhas(Arvore *a) {
	int fol = 0;
	
	if (!verifica_arv_vazia(a)) {
		if (verifica_arv_vazia(a->esq) && verifica_arv_vazia(a->dir)) return 1;
		fol += conta_folhas(a->esq);
		fol += conta_folhas(a->dir);
	}
	
	return fol;
}

// procura o maior elemento da arvore
int max_arvore(Arvore *a) {
	int md, me;
	if (!verifica_arv_vazia(a)) {
		me = max_arvore(a->esq);
		md = max_arvore(a->dir);

		if (a->info > me && a->info > md) return a->info;
		else {
			if (md > me) return md;
			else return me;
		}
	}
}

// calcula a altura de uma arvore
int calcula_altura(Arvore *a) {
	if (verifica_arv_vazia(a)) return -1;
	else {
		return 1 + (calcula_altura(a->esq) > calcula_altura(a->dir) ? calcula_altura(a->esq) : calcula_altura(a->dir));
	}
}

// verifica se uma arvore binaria é cheia (ou completa)
// retorno: 0 para cheia e 1 para não cheia
// verificar se o nó possui dois filhos, exceto quando ele for um nó folha
int verifica_arvore_cheia(Arvore *a) {
	if (calcula_altura(a) == 0) x = 1;
	else {
		int i;
		for (i = 0; i < calcula_altura(a); i++) x = x * 2;
	}
	
	if (x == conta_folhas(a)) return 1;
	else return 0;
}

// espelha a arvore original nela mesma
Arvore* espelha_arvore_inPlace(Arvore *a) {
	Arvore *temp;
	if (!verifica_arv_vazia(a)) {
		espelha_arvore(a->esq);
		espelha_arvore(a->dir);
		
		temp = a->esq;
		a->esq = a->dir;
		a->dir = temp;
	}
	
	return a;
}

// criar uma arvore espelhada da original
Arvore* espelha_arvore(Arvore *a) {
	if (a == NULL)
		return NULL;
	else {
		Arvore *temp = malloc(sizeof(Arvore));
	
		temp->info = a->info;
		temp->esq = espelha_arvore(a->dir);
		temp->dir = espelha_arvore(a->esq);
	
		return temp;
	}
}
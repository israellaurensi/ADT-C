#include "tree.h"

/*

	para criar uma arvore é preciso antes de tudo ter um ponteiro (nulo) para depois receber as referencias
	para o ponteiro raiz

*/
Arvore* cria_arv_vazia (void) {
	return NULL;
}

/*

	constroi uma arvore (que pode ser um subarvore) a partir de uma raiz (int c, que é a info do nó)
	uma referencia para o filho esquerdo e uma para o filho direito
	ambos os filhos esquerdo e direito podem apontar para um outro nó ou para nulo, no caso de o nó corrente
	ser uma folha (não possui filhos)

*/
Arvore* arv_constroi (int c, Arvore* e, Arvore* d) {
	Arvore* a = (Arvore*)malloc(sizeof(Arvore));
	a->info = c;
	a->esq = e;
	a->dir = d;
	
	return a;
}

/*

	verifica se a arvore é vazia, ou seja, se ela existe

*/
int verifica_arv_vazia (Arvore* a) {
	return (a == NULL);
}

/*

	libera os ponteiros relacionados a dada arvore
	sera deletado então a memoria que as referencias para os filhos da arvore ocupam
	e depois o nó raiz

*/
Arvore* arv_libera (Arvore* a) {
	if (!verifica_arv_vazia(a)) {
		arv_libera (a->esq);
		arv_libera (a->dir);
		free(a);
	}
	
	return NULL;
}

/*

	imprime em IN-ORDEM

*/
void arv_imprime(Arvore* a) {
	if (!verifica_arv_vazia(a)) {
		printf("%d ", a->info);
		arv_imprime(a->esq);
		arv_imprime(a->dir);
	}
}

void arv_imprime_textual(Arvore* a) {
	if (!verifica_arv_vazia(a)) {
		printf("<");
		printf("%c", a->info);
		arv_imprime_textual(a->esq);
		arv_imprime_textual(a->dir);
		printf(">");
	} else {
		printf("<>");
	}
}

/*

	checa se um elemento está presente na arvore
	a verificação é feita a partir de uma checagem utilizando operadores lógicos em apenas uma sentença
	tal sentença avalia se o elemento é o elemento que se procura, se o elemento está na arvore da esquerda
	e se o elemento está na arvore da direita ... caso alguma dessas verificações seja verdadeira, toda a sequencia
	de chamadas recursivas será verdadeira, pois a sentença é uma sequencia de || (basta um ser verdade para tudo ser verdade)

*/
int arv_pertence(Arvore *a, int e) {
	if (verifica_arv_vazia(a)) {
		return 0;
	} else {
		return a->info == e || arv_pertence(a->esq, e) || arv_pertence(a->dir, e);
	}
}

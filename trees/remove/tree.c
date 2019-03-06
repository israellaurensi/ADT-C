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

void arv_imprime_textual(Arvore* a) {
	if (!verifica_arv_vazia(a)) {
		printf("<");
		printf("%d", a->info);
		arv_imprime_textual(a->esq);
		arv_imprime_textual(a->dir);
		printf(">");
	} else {
		printf("<>");
	}
}

int arv_pertence (Arvore* a, int c) {
	int d;
	if(!verifica_arv_vazia(a)) {
		if (a->info == c) return 0;
		arv_pertence(a->esq, c);
		arv_pertence(a->dir, c);
	}
	
	return 1;
}

// conta a quantidade de nós de uma arvore
int conta_nos(Arvore *a) {
	int sum = 1;

	if (!verifica_arv_vazia(a)) {
		sum += conta_nos(a->esq);
		sum += conta_nos(a->dir);
		return sum;
	} else {
		return 0;
	}
}

// conta o número de folhas de uma arvore
int conta_folhas(Arvore *a) {
	int sum = 0;

	if (a == NULL) return 0;

	if (!verifica_arv_vazia(a)) {
		if (verifica_arv_vazia(a->esq) && verifica_arv_vazia(a->dir)) return sum += 1;
		else {
			sum += conta_folhas(a->esq);
			sum += conta_folhas(a->dir);
		}
	}
	
	return sum;
}

// procura o maior elemento da arvore
int max_arvore(Arvore *a) {
	int maior = 0;
	int e, d;
	if (!verifica_arv_vazia(a)) {
		e = max_arvore(a->esq);
		if (e > a->info) return e;
		else maior = a->info;
		
		d = max_arvore(a->dir);
		if (d > a->info) return d;
		else maior = a->info;
	}
	
	return maior;
}

// calcula a altura de uma arvore
// int calcula_altura(Arvore *a) {
// 	int alt = 0;
// 	if (!verifica_arv_vazia(a)) {
// 		calcula_altura(a->esq);
// 		calcula_altura(a->dir);
// 		//procura as folhas
// 	}
// }

// verifica se uma arvore binaria é cheia (ou completa)
// retorno: 1 para cheia e 0 para não cheia
int verifica_arvore_cheia(Arvore *a) {
	if (!verifica_arv_vazia(a)) {
		verifica_arvore_cheia(a->esq);
		verifica_arvore_cheia(a->dir);
		
		if (verifica_arv_vazia(a->esq) || verifica_arv_vazia(a->dir)) return 0;
	}
	
	return 1;
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

int buscar (Arvore *a, int v) {
	if (a == NULL) { return 0; }
	
	else if (v < a->info) {
		buscar (a->esq, v);
	}
	
	else if (v > a->info) {
		buscar (a->dir, v);
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

/* para remover um elemento devem ser considerados alguns casos:
	-> se o elemento a ser removido não possui nenhum filho (ou seja, é uma folha)
		: neste caso o procedimento é simples, deve-se apenas liberar a memória ocupada pelo elemento
			e retornar nulo
	-> se o elemento a ser removido possuir apenas 1 filho (esquerdo ou direito)
		: neste caso é preciso antes de tudo saber qual dos filhos o nó possui
			uma vez descoberto, é preciso criar um nó auxiliar, que receberá esse filho
			e depois podemos remover o elemento desejado, porém o processo ainda não terminou
			afinal, precisamos dizer passar o filho para o lugar onde seu nó pai estava
			mas aí entra a recursão, afinal o elemento pai do elemento que queriamos remover já estava esperando
			para saber quem seria seu filho (atráves das chamadas recursivas), e uma vez que o filho assumiu o lugar 
			do nó pai (que foi removido), a arvore não tem sua estruturada violada
	-> se o elemento a ser removido possuir dois filhos (ai fodeu)
		: neste caso, temos que procurar o maior elemento da subarvore a esquerda do nó a ser removido
			assim que encontrarmos este, é preciso trocar os VALORES (a->info) do nó a ser removido com esse nó
			a mais direita da subarvore da esquerda (gzus). depois disso, o procedimento é simples, basta
			percorrer até o utlimo elemento da direita da subarvore da esquerda do nó a ser removido e então remove-lo
			assim conseguimos manter a estrutura da arvore binaria de busca (menor na esquerda e maior na direita)
		
		*/

Arvore* remover(Arvore *a, int elem) {

	if (a == NULL) {
		return NULL;
	} else {
		if (a->info > elem) {
			// esquerda
			a = remover(a->esq, elem);
		} else if (a->info < elem) {
			// direita
			a = remover(a->dir, elem);
		} else {
			// igual
			// elemento a ser removido
			if((a->esq == NULL) && (a->dir == NULL)) {
				// primeiro caso -> folha
				free(a);
				a = NULL;
			} else if (a->esq == NULL) {
				Arvore *tmp = a;
				a = a->dir;
				free(tmp);
			} else if (a->dir == NULL) { 
				// pode ser o filho esquerdo
				// se o filho direito for vazio, entao essa raiz possui um FILHO ESQUERDO
				Arvore *tmp = a;
				a = a->esq;
				free(tmp);
			} else {
				// dois filhos
				Arvore *tmp = a->esq;
				while(tmp->dir != NULL) {
					tmp = tmp->dir;
				}
				
				a->info = tmp->info;
				tmp->info = elem;
				a->esq = remover(a->esq, elem);
			}
		}
	}
	
	return a;
}
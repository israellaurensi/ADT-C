/*

	Para qualquer número a ser buscado, a procura sempre será dividida na metade para cada nova
		iteração, enquanto não encontrar o elemento.
	Para as arvores binarias de pesquisa, as opções se restrigem a esquerda (menor) e direita (maior),
		ou seja, cada elemento novo que o alg. passar, a busca percorre para um dos lados apenas.

*/

#include "tree.h"

int main (int argc, char *argv[]) {

	Arvore *a = cria_arv_vazia();
	Arvore *b = cria_arv_vazia();
	int i, k, r;
	clock_t t1, t2;
	
	srand(time(NULL));
	for (i = 0; i < 10; i++) {
		a = inserir(a, i);
	}
	
	// for (i = 0; i < 100000; i++) {
	// 	a = inserir(a, rand() % 99999);
	// }
	
	// for (i = 0; i < 100; i++) {
	// 	a = inserir(a, i+1);
	// }
	
	printf("\n\n");
	t1 = clock();
	k = buscar(a, 1);
	// k = min(a);
	// k = max(a);
	// k = checa_arv_busca(a);
	t2 = clock();
	t1 = t2 - t1;
	
	if (k == 0) printf("Não foi encontrado o elemento\n\n");
	else printf("O elemento foi encontrado\n\n");
	
	arv_imprime_in(a);
	// printf("\nMenor elemento da arvore é: %d", k);
	// printf("\nMaior elemento da arvore é: %d", k);
	
	// if (k == 0) printf("\n\nA arvore dada é uma arvore binaria de busca");
	// else printf("\n\nA arvore dada não é uma arvore binaria de busca");

	printf ("\n\nTempo de execução: (%f seconds).\n\n", ((float)t1) / CLOCKS_PER_SEC);
	// arv_imprime_in(a);
	printf("\n");
	
	return 0;
}

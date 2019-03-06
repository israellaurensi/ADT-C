/*

	Para qualquer número a ser buscado, a procura sempre será dividida na metade para cada nova
		iteração, enquanto não encontrar o elemento.
	Para as arvores binarias de pesquisa, as opções se restrigem a esquerda (menor) e direita (maior),
		ou seja, cada elemento novo que o alg. passar, a busca percorre para um dos lados apenas.

*/

#include "tree.h"

int main (int argc, char *argv[]) {

	int i, k;

	Arvore *a = cria_arv_vazia();

	a = inserir(a, 30);
	a = inserir(a, 35);
	a = inserir(a, 90);
	a = inserir(a, 95);
	a = inserir(a, 20);
	a = inserir(a, 10);
	a = inserir(a, 37);
	a = inserir(a, 50);

	printf ("\nArvore antes: ");
	arv_imprime_in(a);
	
	// folha
	a = remover(a, 10);

	// um filho
	//a = remover(a, 90);

	// dois filhos
	//a = remover(a, 50);

	printf ("\nArvore depois: ");
	arv_imprime_in(a);
	printf("\n\n");
	
	return 0;
}

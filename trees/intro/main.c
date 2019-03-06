#include "tree.h"

int main (int argc, char *argv[]) {
	
	// if (argc < 2) {
	// 	printf("\n\nUse: %s ...\n\n", argv[0]);
	// 	return 1;
	// }
	
	int pertence;
	// Arvore *a, *a1, *a2, *a3, *a4, *a5;
	// a1 = arv_constroi('d', cria_arv_vazia(), cria_arv_vazia());
	// a2 = arv_constroi('b', cria_arv_vazia(), a1);
	// a3 = arv_constroi('e', cria_arv_vazia(), cria_arv_vazia());
	// a4 = arv_constroi('f', cria_arv_vazia(), cria_arv_vazia());
	// a5 = arv_constroi('c', a3, a4);
	// a  = arv_constroi('a', a2, a5);
	
	Arvore *a = arv_constroi(1, 
		arv_constroi(2, 
			cria_arv_vazia(), 
			arv_constroi(3, 
				cria_arv_vazia(), 
				cria_arv_vazia())), 
		arv_constroi(4, 
			arv_constroi(5, 
				cria_arv_vazia(), 
				cria_arv_vazia()), 
			arv_constroi(6, 
				cria_arv_vazia(),
				cria_arv_vazia())));
	
	printf("\n");
	arv_imprime(a);
	printf("\n");
	// 
	// arv_imprime_textual(a);
	// printf("\n\n");

	// podando o lado direto da arvore
	// a->dir = arv_libera(a->dir);
	
	// arvore depois da poda
	// printf("\n");
	// arv_imprime(a);
	// printf("\n\n");

	pertence = arv_pertence(a, 3);
	if (pertence == 1) printf("\nO numero pertence a Arvore!\n\n");
	else printf("\nO numero não pertence a Arvore!\n\n");
	
	return 0;
}
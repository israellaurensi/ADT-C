#include "tree.h"

int main (int argc, char *argv[]) {

	Arvore *a = arv_constroi (50,
		arv_constroi(30, 
			arv_constroi(20, 
				arv_constroi(10, 
					cria_arv_vazia(), 
					cria_arv_vazia()), 
				arv_constroi(15, 
					cria_arv_vazia(), 
					cria_arv_vazia())), 
			arv_constroi(40, 
				arv_constroi(35, 
					cria_arv_vazia(), 
					cria_arv_vazia()), 
				arv_constroi(45, 
					cria_arv_vazia(), 
					cria_arv_vazia()))
		),
		arv_constroi(90, 
			arv_constroi(85, 
				arv_constroi(75, 
					cria_arv_vazia(), 
					cria_arv_vazia()), 
				arv_constroi(70, 
					cria_arv_vazia(), 
					cria_arv_vazia())
			),
			arv_constroi(95, 
				arv_constroi(60, 
					cria_arv_vazia(), 
					cria_arv_vazia()),
				arv_constroi(55, 
					cria_arv_vazia(), 
					cria_arv_vazia())))
	);
	
	// Arvore *a = arv_constroi(1, 
	// 	arv_constroi(2, 
	// 		cria_arv_vazia(), 
	// 		arv_constroi(3, 
	// 			cria_arv_vazia(), 
	// 			cria_arv_vazia())), 
	// 	arv_constroi(4, 
	// 		arv_constroi(5, 
	// 			cria_arv_vazia(), 
	// 			cria_arv_vazia()), 
	// 		arv_constroi(6, 
	// 			cria_arv_vazia(),
	// 			cria_arv_vazia())));

	printf("\nPre ordem: ");
	arv_imprime_pre(a);
	printf("\n\nIn ordem: ");
	arv_imprime_in(a);
	printf("\n\nPos ordem: ");
	arv_imprime_pos(a);
	printf("\n");

	printf("\nNúmero de Nós: %d\n", conta_nos(a));

	printf("\nNúmero de Folhas: %d\n", conta_folhas(a));
	
	printf("\nAltura da Arvore: %d\n", calcula_altura(a));
	
	printf("\nMaior elemento da arvore: %d\n", max_arvore(a));
	
	if (verifica_arvore_cheia(a) == 0)
		printf("\nEstado da Arvore: cheia\n");
	else
		printf("\nEstado da Arvore: não cheia\n");
		
	// printf("\nComprimento do Caminho é: %d\n", calcula_caminho(a, 10));
		
	Arvore *e;
	e = espelha_arvore_inPlace(a);
	printf("\nArvore espelhada (pré-ordem): ");
	arv_imprime_pre(e);

	printf("\n\n");
	
	return 0;
}

#include "lista.h"

int main() {
	
	int i;
	
/* Lista */
	Lista *lista;

/* Criando lista a partir da função "criar" */
	lista = criar();
	
/* Inserindo novos elementos */
	srand(time(NULL));
	for (i = 0; i < 10; i++)
		lista = inserir(lista, ((rand() % 50) + 10));
	
/* Imprimindo lista a partir da função "imprimir" */
	imprimir(lista);
	
/* Ordenando lista */
	sortLista(lista);
	imprimir(lista);
	
/* Liberando lista */
	liberar(lista);
	
	return 0;
}
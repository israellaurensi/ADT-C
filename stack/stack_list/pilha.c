#include "pilha.h"

Pilha* create_stack (void) {
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	p->topo = NULL;

	return p;
}

void push (Pilha *p, char elem) {
	No *n = (No*)malloc(sizeof(No));
	n->info = elem;
	n->next = p->topo;
	p->topo = n;
}

double pop (Pilha *p) {
	if (empty(p)) exit(1);

	No *n = p->topo;
	double elem = n->info;

	p->topo = n->next;

	free(n);

	return elem;
}

void print (Pilha *p) {
	No *n;
	printf("\nPilha: ");
	if (empty(p)) printf("| p | ->");
	for (n=p->topo; n!=NULL; n=n->next) {
		printf("%c ", n->info);
	}
	printf("\n\n");
}

int empty(Pilha *p) {
	return (p->topo == NULL);
}

void free_stack (Pilha *p) {
	No *n = p->topo;
	while (n != NULL) {
		No *temp = n->next;
		free(n); /*desalocando os nos*/
		n = temp;
	}
	free (p); /*desalocando a pilha*/
}

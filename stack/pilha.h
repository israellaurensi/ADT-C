#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char info;
	struct node *next;
} No;

typedef struct pilha {
	No *topo;
} Pilha;

Pilha* create_stack(void);

void push(Pilha *p, char elem);

char pop(Pilha *p);

void print (Pilha *p);

int empty(Pilha* p);

void free_stack (Pilha *p);

void apaga_ganha(char *num, int d);
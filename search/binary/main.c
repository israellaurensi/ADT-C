/*

	Método de busca em um vetor de números ORDENADOS, onde procura determinado elemento através da divisão e conquista.
	
	Algoritmo:
		1. Pega-se o meio do vetor
			2. Se o elemento que se procura for maior que o elemento do meio
				3. Volta ao passo 1 para o vetor começando da posição atual + 1 (meio+1) até a ultima posição
			4. Se o elemento que se procura for mnenor que o elemento do meio
				5. Volta ao passo 1 para o vetor começando do 0 (inicio) e com o fim sendo a posição atual - 1 (meio-1)
			6. Se o elemento que se procura for igual ao elemento do meio
				7. Retorna a posição atual, elemento encontrado

	Complexidade: O(log n)

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int binarySearch(int *array, int p, int r, int num);
int RbinarySearch(int *array, int p, int r, int num);

int main (int argc, char *argv[]) {
	
	if (argc < 2) {
		printf("\n\nUse: %s number\n\n", argv[0]);
		return 1;
	}
	
	int array[100];
	int n = 100, i, q;
	int num = atoi(argv[1]);
	
	clock_t t1, t2;
	
	for (i = 0; i < n; i++) array[i] = i;
	
	t1 = clock();
	// q = binarySearch(array, 0, n, num);
	q = RbinarySearch(array, 0, n, num);
	// q = busca_binaria(array, 0, n, num);
	t2 = clock();
	t1 = t2 - t1;
	
	printf("\nFound at position [%d]\n", q);
	printf ("Time: (%f seconds).\n\n", ((float)t1) / CLOCKS_PER_SEC);
	
	return 0;
}

int binarySearch(int *a, int i, int f, int e) {
	
 	// meio
	int mid;

	while (f >= i) {
		
		// enquanto o meio não for o número desejado, continuar repetindo o processo de pegar
		// sempre o meio
		mid = (i+f)/2;
		
		// se o meio escolhido for maior do que o elemento desejado
		// diminuir o vetor para: Inicio = meio+1, Fim = fim
		if (a[mid] < e) i = mid+1;
		
		// se o meio escolhido for menor do que o elemento desejado
		// diminuior o vetror para: Inicio = inicio, Fim = meio-1
		else if (a[mid] > e) f = mid-1;
		
		// se nenhum dos casos acima for verdade, então o meio
		// é o elemento desejado, retornar a posição encontrada (meio)
		else return mid;
		
		
	}
	
	// se o elemento não foi encontrado
	// retornar um valor invalido
	return -1;
}

int RbinarySearch(int *array, int p, int r, int num) {
	if (r >= p) {
		int mid = (p+r)/2;
		
		if (array[mid] < num) return RbinarySearch(array, mid+1, r, num);
		else if (array[mid] > num) return RbinarySearch(array, p, mid-1, num);
		
		return mid;
	}
}
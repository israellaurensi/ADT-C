/*

	Busca linear é um método de busca que percorre por toda a estrutura de dados (vetor, lista, fila...)
		elemento por elemento em forma sequencial até encontrar o elemento desejado.
	Por exemplo, dado o vetor: [4] [9] [3] [1] [0] [2] [8] [7], deseja-se encontrar o elemento 0.
		-> [4] = [0]? N
			-> contador++
		-> [9] = [0]? N
			-> contador++
		-> [3] = [0]? N
			-> contador++
		-> [1] = [0]? N
			-> contador++
		-> [0] = [0]? S
			-> retorna contador
	
	Algoritmo:
		1. Começa no primeiro elemento, ou seja, posição 0 do vetor
			2. Checa se o elemento nessa posição é igual ao elemento desejado
				3. Caso seja, retorna a posição do elemento encontrado
			4. Casos não seja, passa a posição atual para a próxima posição do vetor
				5. Retorna ao passo 3

	Complexidade: O(n)

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int linearSearch(int *array, int n, int num);

int main() {
	
	int array1[8];
	int array2[8];
	int n = 8, i, l1, l2, r, num;
	
	clock_t t1, t2, t3, t4;
	
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		r = rand() % n;
		array1[i] = i;
		array2[i] = r;
	}
	
	num = r;
	
	t1 = clock();
	l1 = linearSearch(array1, n, num);
	t2 = clock();
	t1 = t2 - t1;
	
	t3 = clock();
	l2 = linearSearch(array2, n, num);
	t4 = clock();
	t3 = t4 - t3;
	
	printf("\nEm ordem: Found at position [%d]\n", l1);
	printf ("Time: (%f seconds).\n\n", ((float)t1) / CLOCKS_PER_SEC);
	
	printf("\nAleatorio: Found at position [%d]\n", l2);
	printf ("Time: (%f seconds).\n\n", ((float)t3) / CLOCKS_PER_SEC);
	
	return 0;
}

int linearSearch(int *array, int n, int num) {
	int k = 0;
	while ((num != array[k]) && (k <= n)) k++;
	
	if (k >= n) return -1;
	else return k;
}
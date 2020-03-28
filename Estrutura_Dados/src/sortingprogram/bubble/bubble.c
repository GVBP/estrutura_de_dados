/*
 * bubble.c
 *
 *  Created on: 14 de mar de 2020
 *      Author: Guilherme Victor Borges Pereira
 */

/**
 * Método Bolha (Bubble)
 *
 * > Percorra o vetor e execute as operações a seguir.
 *
 * 		> Tome seus elementos dois a dois adjacentes.
 *
 * 		> Se os elementos não estão em ordem, então ordene.
 *
 * 		> Senão, avance para o próximo par.
 *
 * 		> Repita a operação até que nenhuma troca possa ser feita no vetor inteiro.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(const int arr[], const char str[], int idx);
void swap(int arr[], int idx);

void bubble(int arr[], int idx) {
	int n = idx;
	char str[] = "Bubble";
	clock_t start_t, end_t;
	float total_t;

	start_t = clock();
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-i-1; j++) {
			if (arr[j] > arr[j+1])
				swap(arr, j);
		}
	}
	end_t = clock() - start_t;

	printArray(arr, str, idx);
	printf("\n");
	total_t = ((float)end_t) / CLOCKS_PER_SEC;
	printf("Time: %f seconds.\n", total_t);
	printf("Exiting of the program...\n");
}

void swap(int arr[], int idx) {
	int swap = arr[idx];
	arr[idx] = arr[idx+1];
	arr[idx+1] = swap;
}

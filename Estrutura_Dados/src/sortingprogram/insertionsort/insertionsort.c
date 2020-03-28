/*
 * insertionsort.c
 *
 *  Created on: 14 de mar de 2020
 *      Author: Guilherme Victor Borges Pereira
 */

/**
 * Método Insertion Sort
 *
 * > Percorra o vetor e execute as operações a seguir.
 *
 * 		> Encontre o primeiro elemento do vetor e insira em sua posição correta.
 *
 * 		> Encontre o segundo elemento do vetor e insira em sua posição correta.
 *
 * 		> E assim por diante, até que o vetor esteja ordenado.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(const int arr[], const char str[], int idx);

void insertionsort(int arr[], int idx) {
	int n = idx, current, j;
	char str[] = "InsertionSort";
	clock_t start_t, end_t;
	float total_t;

	start_t = clock();
	for (int i = 1; i < n; i++) {
		current = arr[i];
		j = i - 1;

		while ((j >= 0) && arr[j] > current) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = current;
	}
	end_t = clock() - start_t;

	printArray(arr, str, idx);
	printf("\n");
	total_t = ((float)end_t) / CLOCKS_PER_SEC;
	printf("Time: %f seconds.\n", total_t);
	printf("Exiting of the program...\n");
}

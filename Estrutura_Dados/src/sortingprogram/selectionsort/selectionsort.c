/*
 * selectionsort.c
 *
 *  Created on: 14 de mar de 2020
 *      Author: Guilherme Victor Borges Pereira
 */

/**
 * Método Selection Sort
 *
 * > Percorra o vetor e execute as operações a seguir.
 *
 * 		> Encontre o menor elemento do vetor e troque com a primeira posição.
 *
 * 		> Encontre o segundo menor elemento e troque com a segunda posição.
 *
 * 		> E assim por diante, até que o vetor esteja ordenado.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(const int arr[], const char str[], int idx);
void swapFunction(int arr[], int idx, int min_idx);

void selectionsort(int arr[], int idx) {
	int n = idx;
	char str[] = "SelectionSort";
	clock_t start_t, end_t;
	float total_t;

	start_t = clock();
	for (int i = 0; i < n-1; i++) {
		int min_idx = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}
		if (arr[i] != arr[min_idx])
			swapFunction(arr, i, min_idx);
	}
	end_t = clock() - start_t;

	printArray(arr, str, idx);
	printf("\n");
	total_t = ((float)end_t) / CLOCKS_PER_SEC;
	printf("Time: %f seconds.\n", total_t);
	printf("Exiting of the program...\n");
}

void swapFunction(int arr[], int idx, int min_idx) {
	int swap = arr[idx];
	arr[idx] = arr[min_idx];
	arr[min_idx] = swap;
}

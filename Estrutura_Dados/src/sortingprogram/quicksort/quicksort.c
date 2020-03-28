/*
 * quicksort.c
 *
 *  Created on: 14 de mar de 2020
 *      Author: Guilherme Victor Borges Pereira
 */

/**
 * Método Quick Sort
 *
 * > Escolha um pivô.
 *
 * > Separe os elementos menores que o pivô para a esquerda e os elementos maiores que o pivô para a direita.
 *
 * > Recursivamente, execute o mesmo procedimento para elementos à esquerda do pivô.
 *
 * > Recursivamente, execute o mesmo procedimento para elementos à direita do pivô.
 *
 * Separar o vetor
 *
 * > Defina i e j começando pela esquerda e direita, respectivamente.
 *
 * > Faça uma varredura com a variável i para a direita até que encontre um elemento v[i] maior que o pivô.
 *
 * > Faça uma varredura com a variável j para a esquerda até que encontre um elemento v[i] menor que o pivô.
 *
 * > Troque v[i] com v[j].
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(const int arr[], const char str[], int idx);
void qs(int arr[], int left, int right);
int partition(int arr[], int left, int right);
void change(int arr[], int i, int j);

void change(int arr[], int i, int j) {
	int swap = arr[i];
	arr[i] = arr[j];
	arr[j] = swap;
}

int partition(int arr[], int left, int right) {
	int i = left + 1; //1
	int j = right; //19
	int pivo = arr[left]; //1° [0]

	while (i <= j) {
		if (arr[i] <= pivo) i++;
		else if (arr[j] > pivo) j--;
		else if (i <= j) {
			change(arr, i, j);
			i++;
			j--;
		}
	}
	change(arr, left, j);
	return j;
}

void qs(int arr[], int left, int right) {
    if(left < right) {
        int j = partition(arr, left, right);
        qs(arr, left, j-1);
        qs(arr, j+1, right);
    }
}

void quicksort(int arr[], int idx) {
	int size = idx;
	char str[] = "QuickSort";
	clock_t start_t, end_t;
	float total_t;

	start_t = clock();
	qs(arr, 0, (size-1));
	end_t = clock() - start_t;

	printArray(arr, str, idx);
	printf("\n");
	total_t = ((float)end_t) / CLOCKS_PER_SEC;
	printf("Time: %f seconds.\n", total_t);
	printf("Exiting of the program...\n");
}

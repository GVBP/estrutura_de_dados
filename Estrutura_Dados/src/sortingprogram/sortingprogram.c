/*
 * sortingprogram.c
 *
 *  Created on: 8 de mar de 2020
 *      Author: Guilherme Victor Borges Pereira
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void randomvalue(int arr[], int idx);
void bubble(int arr[], int idx);
void selectionsort(int arr[], int idx);
void insertionsort(int arr[], int idx);
void quicksort(int arr[], int idx);
void timsort(int arr[], int idx);
void arrayCopy(int arr[], int copy_arr[], int idx);
void printRandom(int arr[], int idx);

void arrayCopy(int arr[], int copy_arr[], int idx) {
	for (int i = 0; i < idx; i++)
		copy_arr[i] = arr[i];
}

void sortingprogram() {
	setlocale(LC_ALL, "pt_br.UTF-8");

	int t, idx = 100, arr[idx];

	randomvalue(arr, idx);
	printf("\n");

	do {
		printf("\n");
		printf("===================================\n");
		printf("1. Bubble\n");
		printf("2. Selection Sort\n");
		printf("3. Insertion Sort\n");
		printf("4. Quick Sort\n");
		printf("5. Timsort\n");
		printf("===================================\n");
		printf("Escolha qual o tipo de ordenação:\n");
		scanf("%d", &t);
		printf("\n");

		int copy_arr[idx];

		switch(t) {
			case 1:
				arrayCopy(arr, copy_arr, idx);
				printf("\n");
				printRandom(arr, idx);
				printf("\n");
				bubble(copy_arr, idx);
				printf("\n");
				break;
			case 2:
				arrayCopy(arr, copy_arr, idx);
				printf("\n");
				printRandom(arr, idx);
				printf("\n");
				selectionsort(copy_arr, idx);
				printf("\n");
				break;
			case 3:
				arrayCopy(arr, copy_arr, idx);
				printf("\n");
				printRandom(arr, idx);
				printf("\n");
				insertionsort(copy_arr, idx);
				printf("\n");
				break;
			case 4:
				arrayCopy(arr, copy_arr, idx);
				printf("\n");
				printRandom(arr, idx);
				printf("\n");
				quicksort(copy_arr, idx);
				printf("\n");
				break;
			case 5:
				arrayCopy(arr, copy_arr, idx);
				printf("\n");
				printRandom(arr, idx);
				printf("\n");
				timsort(copy_arr, idx);
				printf("\n");
				break;
			default:
				system("clear");
				printf("Error! Digite novamente\n");
				printf("\n");
				break;
		}
	} while(1==1);
}

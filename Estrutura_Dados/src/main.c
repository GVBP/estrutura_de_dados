/*
 * main.c
 *
 *  Created on: 9 de mar de 2020
 *      Author: Guilherme Victor Borges Pereira
 */

#include <stdio.h>
#include <stdlib.h>

void randomvalue(int arr[], int idx);
void sortingprogram( void );

int main( void ) {
	int t;
	int idx = 100;
	int arr[idx];

	do {
		printf("\n");
		printf("===================================\n");
		printf("1. Random value\n");
		printf("2. Sorting Program\n");
		printf("===================================\n");
		printf("Escolha a atividade:\n");
		scanf("%d", &t);

		switch(t) {
			case 1:
				randomvalue(arr, idx);
				break;
			case 2:
				sortingprogram();
				break;
			default:
				system("clear");
				printf("Error! Digite novamente\n");
				break;
		}
	} while(1==1);
	return 0;
}

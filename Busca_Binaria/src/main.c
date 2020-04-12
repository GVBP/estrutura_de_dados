/*
 * main.c
 *
 *  Created on: 12 de abr de 2020
 *      Author: guilherme
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main( void )
{
	setlocale(LC_ALL, "pt_br.UTF-8");

	int t, idx = 20, arr[idx];

	randomvalue(arr, idx);
	quicksort(arr, idx);

	printf("\n");

	do {
		printf("======================================\n");
		printf("1st. Busca Binária.\n");
		printf("======================================\n");
		printf("Digite um número a ser buscado no array:\n");
		scanf("%d", &t);
		printf("\n\n");

		binarysearch(arr, idx, t);
		printf("\n\n");
	} while(1==1);

	return 0;
}

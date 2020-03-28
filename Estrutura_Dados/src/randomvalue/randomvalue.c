/*
 * randomvalue.c
 *
 *  Created on: 8 de mar de 2020
 *      Author: Guilherme Victor Borges Pereira
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(const int arr[], const char str[], int idx);
void printRandom(int arr[], int idx);

void printRandom(int arr[], int idx) {
	char str[] = "Random";

	printArray(arr, str, idx);
}

void randomvalue(int arr[], int idx) {

	srand(time(NULL));

	for (int n = 0; n != idx; ++n) {
		int x = 101;
		while(x > 100)
			x = 1 + rand()/((RAND_MAX + 1u)/100);
		arr[n] = x;
	}
	printRandom(arr, idx);
	printf("\n");
}

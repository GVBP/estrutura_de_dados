/*
 * printarray.c
 *
 *  Created on: 12 de abr de 2020
 *      Author: guilherme
 */

#include <stdio.h>
#include <stdlib.h>

void printArray(const int arr[], const char str[], int idx) {

	printf("%s: ", str);
	for(int loop = 0; loop < idx; loop++) {
		if ((loop % 20) == 0)
			printf("\n");
		printf("%d ", arr[loop]);
	}
	printf("\n");
}

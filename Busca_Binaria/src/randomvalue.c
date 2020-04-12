/*
 * randomvalue.c
 *
 *  Created on: 12 de abr de 2020
 *      Author: guilherme
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomvalue(int arr[], int idx)
{
	srand(time(NULL));

	for (int n = 0; n != idx; ++n)
	{
		int x = 101;
		while(x > 100)
			x = 1 + rand()/((RAND_MAX + 1u)/100);
		while(x < 0)
			x = 1 + rand()/((RAND_MAX + 1u)/100);
		arr[n] = x;
	}
	printf("\n");
}

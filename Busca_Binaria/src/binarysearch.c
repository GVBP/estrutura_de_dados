/*
 * binarysearch.c
 *
 *  Created on: 12 de abr de 2020
 *      Author: guilherme
 */

#include <stdio.h>
#include <stdlib.h>

int p(int left, int right)
{
	int i = left;
	int j = right;

	while (i < j)
	{
		i++;
		j--;
	}
	return j;
}

void bs(int arr[], int left, int right, int t)
{
	int j = p(left, right);
	if (t == arr[j])
	{
		printf("Valor buscado existe e esta localizado na posição %d do vetor.", j);
		return;
	}
	else if (t > arr[j])
		bs(arr, left, j-1, t);
	else if (t < arr[j])
		bs(arr, j+1, right, t);
}

void binarysearch(int arr[], int idx, int t)
{
	if (t < arr[0] || t > arr[idx-1])
		printf("Valor buscado não existe no vetor.");
	else
	{
		bs(arr, 0, idx-1, t);
	}
}

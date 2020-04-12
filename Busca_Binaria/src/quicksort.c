/*
 * quicksort.c
 *
 *  Created on: 12 de abr de 2020
 *      Author: guilherme
 */

#include <stdio.h>
#include <stdlib.h>

void change(int arr[], int i, int j)
{
	int swap = arr[i];
	arr[i] = arr[j];
	arr[j] = swap;
}

int partition(int arr[], int left, int right)
{
	int i = left + 1;
	int j = right;
	int pivo = arr[left];

	while (i <= j)
	{
		if (arr[i] <= pivo) i++;
		else if (arr[j] > pivo) j--;
		else if (i <= j)
		{
			change(arr, i, j);
			i++;
			j++;
		}
	}
	change(arr, left, j);
	return j;
}

void qs(int arr[], int left, int right)
{
	if (left < right)
	{
		int j = partition(arr, left, right);
		qs(arr, left, j-1);
		qs(arr, j+1, right);
	}
}

void quicksort(int arr[], int idx)
{
	int size = idx;
	char str[] = "QuickSort";

	qs(arr, 0, (size-1));
	printArray(arr, str, idx);
	printf("\n");
}

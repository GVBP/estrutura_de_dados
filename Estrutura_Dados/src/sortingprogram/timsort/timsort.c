/*
 * timsort.c
 *
 *  Created on: 14 de mar de 2020
 *      Author: Guilherme Victor Borges Pereira
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(const int arr[], const char str[], int idx);
void ts(int arr[], int n);
void insertionSort(int arr[], int left, int right);
void merge(int arr[], int l, int m, int r);
int min(int a, int b);

static int RUN = 10;

void insertionSort(int arr[], int left, int right) {
	for (int i = left + 1; i <= right; i++)	{
		int temp = arr[i];
		int j = i - 1;
		while (arr[j] > temp && j >= left) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

void merge(int arr[], int l, int m, int r) {
	int len1 = m - l + 1, len2 = r - m;
	int left[len1];
	int right[len2];
	for (int x = 0; x < len1; x++) {
		left[x] = arr[l + x];
	}
	for (int x = 0; x < len2; x++) {
		right[x] = arr[m + 1 + x];
	}

	int i = 0;
	int j = 0;
	int k = l;

	while (i < len1 && j < len2) {
		if (left[i] <= right[j]) {
			arr[k] = left[i];
			i++;
		} else {
			arr[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < len1) {
		arr[k] = left[i];
		k++;
		i++;
	}

	while (j < len2) {
		arr[k] = right[j];
		k++;
		j++;
	}
}

int min(int a, int b) {
	if (a < b)
		return a;
	return b;
}

void ts(int arr[], int n) {

	for (int i = 0; i < n; i += RUN) {
		insertionSort(arr, i, min((i + 31), (n - 1)));
	}

	for (int size = RUN; size < n; size = 2 * size) {
		for (int left = 0; left < n; left += 2 * size) {
			int mid = left + size - 1;
			int right = min((left + 2 * size - 1), (n - 1));

			merge(arr, left, mid, right);
		}
	}
}

void timsort(int arr[], int idx) {
	int n = idx;
	char str[] = "TimSort";
	clock_t start_t, end_t;
	float total_t;

	start_t = clock();
	ts(arr, n);
	end_t = clock() - start_t;

	printArray(arr, str, idx);
	printf("\n");
	total_t = ((float)end_t) / CLOCKS_PER_SEC;
	printf("Time: %f seconds.\n", total_t);
	printf("Exiting of the program...\n");
}

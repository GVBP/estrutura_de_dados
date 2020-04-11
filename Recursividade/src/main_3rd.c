/*
 * main_3rd.c
 *
 *  Created on: 11 de abr de 2020
 *      Author: guilherme
 */

void naturalType(int k, int arr[], int n, int t)
{
	if (k == arr[n])
		t++;
	printf("\n k = %d", k);
	printf("\n arr[n] = %d", arr[n]);
	printf("\n n = %d", n);
	if (n == 0) {
		printf("\n > Resultado: dígito %d em %s ocorre %d.", k, arr, t);
		return;
	}
	printf("(n == 0)");
	highInPower( k, arr, n-1, t );
}

void main_3rd()
{
	printf("3rd.\n");
	printf("Escreva uma função recursiva que determine quantas vezes um dígito K ocorre\n");
	printf("em um número natural N. Por exemplo, o dígito 2 ocorre 3 vezes em 762021192.\n");
	printf("O valor pode ser digitado como String.\n");

	int k, t, n;

	n = 9;
	int arr[9] = {7,6,2,0,2,1,1,9,2};
	k = 2;

	naturalType( k, arr, n-1, 0 );
}

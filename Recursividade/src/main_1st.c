/*
 * main_1st.c
 *
 *  Created on: 11 de abr de 2020
 *      Author: guilherme
 */

long highInPower(int x, int n)
{
	if (n == 1)
		return x;
	return x * highInPower( x, n-1 );
}

void main_1st()
{
	printf("1st.\n");
	printf("Implemente uma função recursiva que, dados dois números inteiros x\n");
	printf("e n, calcula o valor de x elevado na potencia de n.\n");

	int x, n;
	long result;

	x = 5;
	n = 15;

	result = x * highInPower( x, n-1 );
	printf("\n > Resultado: ( %d^%d ) = %ld.", x, n, result);
}

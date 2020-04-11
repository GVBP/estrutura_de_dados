/*
 * main_2nd.c
 *
 *  Created on: 11 de abr de 2020
 *      Author: guilherme
 */

long successiveSum(int x, int n)
{
	if (n == 1)
		return x;
	return x + highInPower( x, n-1 );
}

void main_2nd()
{
	printf("2nd.\n");
	printf("Crie uma função recursiva que, dados dois números inteiros x e n, resolva\n");
	printf("a multiplicação dos números através de somas sucessivas.\n");
	printf("Por exemplo, 3 e 7 -> 7 + 7 + 7 = 21 (somar três vezes o número sete).\n");

	int x, n;
	long result;

	x = 7;
	n = 3;

	result = x + successiveSum( x, n-1 );
	printf("\n > Resultado: ( %d e %d ) = %ld.", n, x, result);
}

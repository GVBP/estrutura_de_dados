/*
 * main_4th.c
 *
 *  Created on: 11 de abr de 2020
 *      Author: guilherme
 */

void towerOfHanoi(int n, char from, char to, char aux)
{
	if (n == 1) {
		printf("\n Movendo o disco 1 da coluna %c para a coluna %c", from, to);
		return;
	}
	towerOfHanoi(n-1, from, aux, to);
	printf("\n Movendo o disco %d da coluna %c para a coluna %c", n, from, to);
	towerOfHanoi(n-1, aux, to, from);
}

void main_4th()
{
	printf("4th.\n");
	printf("Resolver o problema da Torre de Hanoi que esta no material.\n");

	int r, n = 4;

	towerOfHanoi( n, 'A', 'C', 'B' );
}

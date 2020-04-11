/*
 * main.c
 *
 *  Created on: 11 de abr de 2020
 *      Author: guilherme
 */

#include <stdio.h>
#include <stdlib.h>

void main_1st();
void main_2nd();
void main_3rd();
void main_4th();

int main( void ) {
	int t;

	do {
		printf("======================================\n");
		printf("1st. Elevado na Potência.\n");
		printf("2nd. Soma Sucessiva.\n");
		printf("3rd. Dígito.\n");
		printf("4th. Torre de Hanoi.\n");
		printf("======================================\n");
		printf("Escolha a atividade:\n");
		scanf("%d", &t);
		printf("\n\n");

		switch(t) {
			case 1:
				main_1st();
				break;
			case 2:
				main_2nd();
				break;
			case 3:
				main_3rd();
				break;
			case 4:
				main_4th();
				break;
			default:
				printf("\n\nError! Digite novamente\n");
				break;
		}
		printf("\n\n");
	} while(1==1);

	return 0;
}

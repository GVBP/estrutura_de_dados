/*
 * main.c
 *
 *  Created on: 27 de abr de 2020
 *      Author: guilherme.victor
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

#define d 256

void rabinKarp()
{
	FILE *inFilePtr;

	char nomeArq[100];
	char frase[40];
	int sizeFrase;
	int sizeArq;
	int i = 0;
	int j = 0;
	int ptrFrase = 0;
	int ptrArq = 0;
	int numPrimo = 101;
	int hash = 1;
	int aux = 0;
	int arrayIndex[50];
	int index = 0;

	printf("\nFind..");

	printf("\nDigite o caminho completo do Arquivo: ");
	scanf("%s", nomeArq);

	printf("Digite uma frase para busca: ");
	scanf("%s", frase);

	sizeFrase = strlen(frase);

	if ( (inFilePtr = fopen(nomeArq, "r") ) == NULL )
	{
		printf("\narquivo não pode ser aberto.");
	}
	else
	{
		fseek (inFilePtr, 0, SEEK_END);
		sizeArq = ftell(inFilePtr);

		for (i = 0; i < sizeFrase-1; i++)
				hash = (hash*d) % numPrimo;

		for (i = 0; i < sizeFrase; i++)
		{
			ptrFrase = (d * ptrFrase + frase[i]) % numPrimo;
			fseek(inFilePtr, i, SEEK_SET);
			ptrArq   = (d * ptrArq + fgetc(inFilePtr)) % numPrimo;
		}

		for (i = 0; i <= sizeArq - sizeFrase; i++)
		{
			system("cls");
			printf("%d%%..", ((i * 100)/(sizeArq - sizeFrase)));

			if ( ptrFrase == ptrArq )
			{
				for (j = 0; j < sizeFrase; j++)
				{
					fseek(inFilePtr, i+j, SEEK_SET);
					if ( fgetc(inFilePtr) != frase[j])
						break;
				}
				if (j == sizeFrase){
					arrayIndex[index] = i;
					index++;
				}
			}

			if ( i < sizeArq - sizeFrase )
			{
				fseek(inFilePtr, i, SEEK_SET);
				aux = fgetc(inFilePtr);
				fseek(inFilePtr, i + sizeFrase, SEEK_SET);
				ptrArq = ( d* (ptrArq - aux * hash) + fgetc(inFilePtr)) % numPrimo;
				if (ptrArq < 0)
					ptrArq = (ptrArq + numPrimo);
			}
		}

		fclose(inFilePtr);
	}
	printf("\n\nO total encontrado no texto foi %d", index);
	for (i = 0; i < index; i++)
		printf("\nFrase encontrada no index %d", arrayIndex[i]);

	printf("\nFinished\n");
}

void forcaBruta()
{
	FILE *inFilePtr;

	char nomeArq[100];
	char frase[40];
	int sizeFrase;
	int sizeArq;
	int i = 0;
	int j = 0;
	int ptrArq = 0;
	int arrayIndex[50];
	int index = 0;

	printf("\nFind..");

	printf("\nDigite o caminho completo do Arquivo: ");
	scanf("%s", nomeArq);

	printf("Digite uma frase para busca: ");
	scanf("%s", frase);

	sizeFrase = strlen(frase);

	if ( (inFilePtr = fopen(nomeArq, "r") ) == NULL )
	{
		printf("\narquivo não pode ser aberto.");
	}
	else
	{
		fseek (inFilePtr, 0, SEEK_END);
		sizeArq = ftell(inFilePtr);

		fseek(inFilePtr, 0, SEEK_SET);
		ptrArq = fgetc(inFilePtr);

		for (i = 0; i <= sizeArq - sizeFrase; i++)
		{
			system("cls");
			printf("%d%%..", ((i * 100)/(sizeArq - sizeFrase)));

			if ( frase[0] == ptrArq )
			{
				for (j = 0; j < sizeFrase; j++)
				{
					fseek(inFilePtr, i+j, SEEK_SET);
					if ( fgetc(inFilePtr) != frase[j])
						break;
				}
				if (j == sizeFrase){
					arrayIndex[index] = i;
					index++;
				}
			}

			if ( i < sizeArq - sizeFrase )
			{
				fseek(inFilePtr, i+1, SEEK_SET);
				ptrArq = fgetc(inFilePtr);
			}
		}

		fclose(inFilePtr);
	}
	printf("\n\nO total encontrado no texto foi %d", index);
	for (i = 0; i < index; i++)
		printf("\nFrase encontrada no index %d", arrayIndex[i]);

	printf("\nFinished\n");
}

char encerrar()
{
	char resposta = 'n';
	printf("Você deseja encerrar o programa?");
	printf("\n >> ");
	scanf("%s", &resposta);
	if (resposta == 'S' || resposta == 's')
		return resposta = 'S';
	return resposta;
}

int main( void )
{
	setlocale(LC_ALL, "");

	int escolha = 0;
	do
	{
		printf("Escolha o algoritmo de busca..");
		printf("\n----------------------------");
		printf("\n [1]. Rabin Karp.");
		printf("\n [2]. Força Bruta.");
		printf("\n >> ");
		scanf("%d", &escolha);

		switch(escolha)
		{
			case 1:
					rabinKarp();
					system("pause");
					system("cls");
					break;
			case 2:
					forcaBruta();
					system("pause");
					system("cls");
					break;
			default:
					printf("\n\nA opção selecionada não existe.");
					system("pause");
					system("cls");
		}
	} while(encerrar() != 'S');
	return 0;
}

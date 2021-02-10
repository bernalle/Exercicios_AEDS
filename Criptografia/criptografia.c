#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

//Irá permutar os blocos trocando primeiro com último e por ai vai
void permutar(char *string_aux, int quantidade_de_palavras)
{

	int i;
	int j = quantidade_de_palavras - 2;
	char c;

	for (i = 0; i < (quantidade_de_palavras / 2); i = i + 4)
	{
		c = string_aux[i];
		string_aux[i] = string_aux[j];
		string_aux[j] = c;
		j = j - 4;
	}
	j = quantidade_de_palavras - 1;

	for (i = 1; i < (quantidade_de_palavras / 2); i = i + 4)
	{
		c = string_aux[i];
		string_aux[i] = string_aux[j];
		string_aux[j] = c;
		j = j - 4;
	}
}

//Irá trocar duas letras de posição
void refletir(char *string_aux, int quantidade_de_palavras)
{

	int i;
	char c;

	for (i = 0; i < quantidade_de_palavras - 1; i = i + 2)
	{
		c = string_aux[i];
		string_aux[i] = string_aux[i + 1];
		string_aux[i + 1] = c;
	}
}

//Cifra de César, troca o caracter 5 para esquerda
void cifraCesar(char *string_aux, int quantidade_de_palavras)
{
	int j;

	for (j = 0; j < quantidade_de_palavras; j++)
	{

		if (string_aux[j] == '#')
		{
			string_aux[j] = ' ';
		}

		else
		{
			if (string_aux[j] == 'a' || string_aux[j] == 'b' || string_aux[j] == 'c' || string_aux[j] == 'd' || string_aux[j] == 'e' || string_aux[j] == 'A' || string_aux[j] == 'B' || string_aux[j] == 'C'|| string_aux[j] == 'D'|| string_aux[j] == 'E')
			{
				string_aux[j] = string_aux[j] + 26;
			}
			string_aux[j] = string_aux[j] - 5;
		}
	}
}

int main()
{

	char nome_arquivo[MAX];
	printf("Digite o nome do arquivo: ");
	scanf("%s", nome_arquivo);

	printf("\n--------------------\n");
	printf("Mensagem codificada: ");
	printf("\n--------------------\n");

	FILE *f = fopen(nome_arquivo, "r");
	int quantidade_de_palavras = 0;
	char string_aux[20000];

	fscanf(f, "%s", string_aux);
	printf("%s", string_aux);
	fclose(f);

	quantidade_de_palavras = strlen(string_aux);

	refletir(string_aux, quantidade_de_palavras);
	permutar(string_aux, quantidade_de_palavras);
	cifraCesar(string_aux, quantidade_de_palavras);

	printf("\n\n----------------------\n");
	printf("Mensagem decodificada: ");
	printf("\n----------------------\n");

	printf("%s", string_aux);

	return 0;
}

/****************

LAED1 - Problema da Mochila

Alunos(as): Gabriel Bernalle Matozinhos e Vitor Brandão Raposo

Data:23/09/20

****************/

#include <stdio.h>
#include <stdlib.h>

void mochila(char *nameTxt){

    FILE *arc;
    arc = fopen(nameTxt, "r");
    if (arc == NULL){
        printf("\nERROR: IMPOSSIBLE TO OPEN THE FILE");
        exit(1);
    }

    int capacidade, qtdItens;
    fscanf(arc, "%i", &capacidade);
    fscanf(arc,"%i",&qtdItens);

    int itemValor[qtdItens];
    int itemPeso[qtdItens];
	int solucao[qtdItens];

    for (int i = 0; i < qtdItens; i++) fscanf(arc,"%i %i",&itemPeso[i], &itemValor[i]);
    for (int i = 0; i < qtdItens; i++) fscanf(arc,"%i",&solucao[i]);
    
	fclose(arc);
    
	int capacidadeDisponivel = capacidade;
	int valorTotal = 0;
	int valorSolucao = 0;
	int pesoSolucao = 0;

	for(int i = 0; i < qtdItens; i++) valorSolucao += solucao[i] * itemValor[i];
	for(int i = 0; i < qtdItens; i ++) pesoSolucao += solucao[i] * itemPeso[i];

	int x = 0;
	int contador;

	if(capacidadeDisponivel > 0){
		while (capacidadeDisponivel >0){
			x = 0;
			contador = -1;
			for(int i = 0; i < qtdItens; i++){
				if((capacidadeDisponivel - itemPeso[i] >= 0 ) && (contador == -1 || (itemValor[i] > itemValor[x]))){
					x = i;
					contador++;
				}
			}
			if(contador > -1){
				capacidadeDisponivel -=itemPeso[x];
				valorTotal += itemValor[x];
				itemValor[x] = 0;
			}
			else break;
		}
		if(valorTotal <= valorSolucao && (capacidade >= pesoSolucao)) printf("Solucao otima.");
		if(valorTotal > valorSolucao && (capacidade >= pesoSolucao)) printf("Solucao viavel mas nao otima.");
		if(capacidade < pesoSolucao) printf("Solucao inviavel.");
	}

}

int main()
{
    char nameTxt[60];
    printf("Digite o nome do arquivo: ");
    scanf("%s", nameTxt);

    mochila(nameTxt);
}

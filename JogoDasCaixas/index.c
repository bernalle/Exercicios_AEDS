#include<stdio.h>

int main(){

    const char nameTxt[10];
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s",&nameTxt);

    char hook; //fisgar caracter dentro do arquivo
    const int **boxMatrix;
    FILE *arq = fopen(nameTxt,"rt");
    if(arq == NULL){
        printf("Problemas na abertura do arquivo");
        return 0;
    }
    



}
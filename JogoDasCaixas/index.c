#include <stdio.h>
#include <string.h>

int main()
{

    const char nameTxt[10];
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", &nameTxt);


    char hook; //fisgar caracter dentro do arquivo
    int **boxMatrix = malloc(20 * sizeof(int));
    FILE *arq = fopen(nameTxt, "r");
    if (arq == NULL)
    {
        printf("Problemas na abertura do arquivo");
        return 0;
    }
    hook = (getc((int) arq) - 48);
    boxMatrix[0][0] = hook;
    int fileira = 0;
    int caixa = 0;

  //Problema de Loop  
    while (hook = (getc(arq)) != EOF)
    {
        for (caixa; caixa != '\n'; caixa++)
        {
            hook = getc((int)arq - '0');
            boxMatrix[fileira][caixa] = hook;
        }
        fileira++;
    }
    fclose(arq);

    printf("\n Entrou\n "); 

    //printf("%i",boxMatrix[0][0]);
    
}
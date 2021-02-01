#include <stdio.h>
#include <string.h>

int main()
{

    printf("\n Entrou");
    const char nameTxt[10];
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", &nameTxt);

    char hook; //fisgar caracter dentro do arquivo
    int **boxMatrix;
    FILE *arq = fopen(nameTxt, "r");
    if (arq == NULL)
    {
        printf("Problemas na abertura do arquivo");
        return 0;
    }

    hook = (fgetc(arq) - 48);
    boxMatrix[0][0] = hook;
    int fileira = 1;
    int caixa = 0;

    while (hook = (fgetc(arq) - 48) != EOF)
    {
        for (caixa; caixa != '\n'; caixa++)
        {
            boxMatrix[fileira][caixa] = hook;
        }
        fileira++;
    }
    fclose(arq);

    for (int i = 0; i < 5; i++)
    {
        printf("Entrou");
        for (int j = 0; i < 5; j++)
        {
            printf("%i %i",boxMatrix[i][j]);
        }
    }
}
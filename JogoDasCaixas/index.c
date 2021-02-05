#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void matrixCalculation(int **value, int fileira, int coluna)
{
    int maior;
    int soma[fileira];
    soma[0] = value[0][0];

    for (int i = 1; i <= fileira; i++)
    {
        for (int j = 0; j <= coluna; j++)
        {
           soma[i] = soma[i] + value[i][j];
        }    
    }
    
    maior = soma[0];
    int resultado;
    int linha;
    int col;

    for (int i = 1; i <= fileira; i++)
    {
        for (int j = 0; j <= coluna; j++)
        {
            resultado = value[i][j] + soma[j];
            if (maior < resultado)
            {
                maior = resultado;
                linha = i;
                col = j;
            }
        }      
    }
    printf("Resposta: fileira %d, caixa %d.",linha,col +1);  
}

void createIntMatrix(char *nameTxt)
{
    FILE *arc;
    arc = fopen(nameTxt, "r");
    if (arc == NULL)
    {
        printf("\nERROR: IMPOSSIBLE TO OPEN THE FILE");
        exit(1);
    }

    // Creation of dinamic matrix, max 20 rows

    int **intMatrix; //point to point
    int numOfRow = 20;
    int numOfColumn = 19;

    intMatrix = (int **)calloc(numOfRow, sizeof(int *)); // vector
    if (intMatrix == NULL)
    {
        printf("\n ERROR: IMPOSSIBLE TO ALLOCATE ROW"); // -- Checkpoint --
        exit(1);
    }
    for (int i = 0; i < numOfRow; i++)
    {
        intMatrix[i] = (int *)calloc(numOfColumn, sizeof(int)); //integers
        if (intMatrix[i] == NULL)
        {
            printf("\n ERROR: IMPOSSIBLE TO ALLOCATE COLUMN"); // -- Checkpoint --
            exit(1);
        }
    }
    
    int valorRepet;
    int fileira;
    int coluna;
    int i,j;
    char auxiliar[] = "%i";

    fscanf(arc, "%i", &valorRepet);

    for (i = 0; i < valorRepet; i++)
    {
        for ( j = 0; j < valorRepet; j++)
        {
            fscanf(arc,auxiliar,&intMatrix[i][j]);
            strcat(auxiliar," %i");
        }
    }
    fileira = i;
    coluna = j;

    matrixCalculation(intMatrix,fileira,coluna);

    fclose(arc);
}

int main()
{
    char nameTxt[10];
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", nameTxt);

    createIntMatrix(nameTxt);
}

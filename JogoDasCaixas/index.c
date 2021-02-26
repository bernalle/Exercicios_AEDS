#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void matrixCalculation(int **value, int loopValue)
{
    int summation[loopValue - 1];
    int i, j;
    int auxSum = 0;
    summation[0] = value[0][0];

    for (i = 1; i < loopValue; i++)
    {
        for (j = 0; j < (i + 1); j++)
        {
            auxSum = auxSum + value[i][j];
        }
        summation[i] = auxSum;
        auxSum = 0;
    }
    // -- CheckPoint --

    int highestValue;
    int row;
    int column;
    int a, b;
    int result;
    int counter;
    int fixedValue = value[0][0];

    if (loopValue == 1)
    {
        row = 0;
        column = 0;
    }
    else
    {

        for (a = 1; a < loopValue; a++)
        {
            for (b = 0; b < (a + 1); b++)
            {
                result = value[a][b];
                for (counter = 0; counter < a; counter++)
                {
                    result = result + summation[counter];
                }
                // -- Checkpoint, result FunFa
                if (fixedValue > result)
                {
                    highestValue = fixedValue;
                }
                if (fixedValue < result)
                {
                    highestValue = result;
                    fixedValue = highestValue;
                    row = a;
                    column = b;
                }
            }
        }
    }
    printf("Resposta: fileira %d, caixa %d.", row + 1, column + 1);
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
    int loopValue;
    fscanf(arc, "%i", &loopValue);

    int **intMatrix; //point to point
    int numOfRow = loopValue;
    int numOfColumn = loopValue;

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

    int i, j;

    for (i = 0; i < loopValue; i++)
    {
        for (j = 0; j < (i + 1); j++)
        {
            fscanf(arc, "%i", &intMatrix[i][j]);
        }
    }

    matrixCalculation(intMatrix, loopValue);

    fclose(arc);
}

int main()
{
    char nameTxt[10];
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", nameTxt);

    createIntMatrix(nameTxt);
}

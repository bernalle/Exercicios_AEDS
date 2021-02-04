#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void matrixCalculation(int **intMatrix)
{
    int i, j;

    for (i = 0; i < strlen(intMatrix); i++)
    {
        for (j = 0; j < strlen(intMatrix); j++)
        {
            printf("\n%i", intMatrix[i][j]);
        }
    }

}

void createIntMatrix(char *nameTxt)
{

    printf("%s", nameTxt); // -- Checkpoint --

    FILE *arc;
    arc = fopen(nameTxt, "r");
    if (arc == NULL)
    {
        printf("\nERROR: IMPOSSIBLE TO OPEN THE FILE");
        exit(1);
    }

    printf("\nSuccess to open the File"); // -- Checkpoint --

    // Creation of dinamic matrix, max 20 rows

    int **intMatrix; //point to point
    const int numOfRow = 21;
    const int numOfColumn = 231;

    intMatrix = (int **)malloc(numOfRow * sizeof(int *)); // vector
    if (intMatrix == NULL)
    {
        printf("\n ERROR: IMPOSSIBLE TO ALLOCATE ROW"); // -- Checkpoint --
        exit(1);
    }
    for (int i = 0; i < numOfRow; i++)
    {
        intMatrix[i] = (int *)malloc(numOfColumn * sizeof(int)); //integers
        if (intMatrix[i] == NULL)
        {
            printf("\n ERROR: IMPOSSIBLE TO ALLOCATE COLUMN"); // -- Checkpoint --
            exit(1);
        }
    }

    int ch; // integer for character reading
    int rows = 0;
    int columns = 0;
    int aux1 = 0;
    int aux2 = 0;
    const int aux3 = -1;

    intMatrix[rows][columns] = (ch = fgetc(arc)) - 48;
    aux2 = intMatrix[0][0];

    printf("\n   intMatrix is printing  %i", intMatrix[rows][columns]); // --Checkpoint --

    while ((ch = fgetc(arc)) != EOF)
    {     
        printf("\nEsta printando");
        if (ch == '\n')
        {
            intMatrix[rows]++;
            intMatrix[columns] = 0;
            aux2 = ch;
            printf("\nNow intMatrix is printing  %i", intMatrix[rows][columns]);
        }
        if (ch == '-')
        {
            aux2 = ch;
            printf("\nNow intMatrix is printing  %i", intMatrix[rows][columns]);
        }
        
        if (ch == ' ')
        {
            intMatrix[columns]++;
            aux2 = ch;
            printf("\nNow intMatrix is printing  %i", intMatrix[rows][columns]);
        }
        else
        {
            aux1 = (ch) - 48;
            
            if (aux2 == '\n' || aux2 == ' ')
            {
                intMatrix[rows][columns] = aux1;
                aux2 = aux1;
                printf("\nNow intMatrix is printing  %i", intMatrix[rows][columns]);
            }
            if (aux2 = '-')
            {
                aux2 = aux3;
                intMatrix[rows][columns] = (aux2 * 10) + aux1;
                printf("\nNow intMatrix is printing  %i", intMatrix[rows][columns]);
            }
            
            else{
                intMatrix[rows][columns] = (aux2 * 10) + aux1;
                printf("\nNow intMatrix is printing  %i", intMatrix[rows][columns]);
            }  
        }
        printf("\nNow intMatrix is printing  %i", intMatrix[rows][columns]);
    }

    //matrixCalculation(intMatrix);

    fclose(arc);
}

int main()
{
    const char nameTxt[10];
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", nameTxt);

    createIntMatrix(nameTxt);
}

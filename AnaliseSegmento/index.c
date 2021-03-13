#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void matrix(int *vetEl, int count, int *typeSeg){
	printf("Matriz:\n");
	
	for(int i = 0; i < count;i++) printf("%i ",typeSeg[i]);
	printf("\n");
	for(int i = 0; i < count;i++) printf("%i ",vetEl[i]);

}

void nElements(int *elementsVector, int count, int *typeSeg){
	int numEl = 1;
	int auxVar = elementsVector[0];
	int vetEl[count];
	int j = 0;

	for(int i = 1; i <= count; i++){
		if(auxVar == elementsVector [i]){
			numEl++;
		}
		else{
			vetEl[j] = numEl;
			numEl = 1;
			auxVar = elementsVector[i]; 
			j++;
		}
	}

	matrix(vetEl, j, typeSeg);
}

void mapping(int *elementsVector, int count){
	int *typeSeg;
	typeSeg = (int*) malloc(count * sizeof(int));
	
	int seg = 1;
	typeSeg[0] = seg;
	seg = 2;
	int allValues[count];
	int aux = elementsVector[0];
	allValues[0] = elementsVector[0];
	int j = 0;

	for(int i = 0; i < count; i++){
		if (elementsVector[i] != aux)
		{
			j++;
			allValues[j] = elementsVector[i]; 
			aux = elementsVector[i];
			typeSeg[j] = seg ++;
		}	
	}

	//for(int i =0; i< 4; i++)printf("%i ",typeSeg[i]);
	
	int auxInt[j];
	for (int i = 0; i < j; i++){
		auxInt[i] = allValues[i];
	}
	
	for(int i = 0; i < j; i++){
		for(int c = 0; c < j; c++){
			if(auxInt[i] == allValues[c]){
				typeSeg[c] = typeSeg[i]; 
			}
		}
	}
	
	//for(int i =0; i< 4; i++)printf("%i ",typeSeg[i]);

	int organiza = 2;

	for(int i = 0; i <= j; i++){
		if (organiza < typeSeg[i]){
			organiza ++;
			typeSeg[i] = organiza;
		}
	}

	nElements(elementsVector, count, typeSeg);

}

void mainSeg(char *nameTxt){

    FILE *arc;
    arc = fopen(nameTxt, "r");
    if (arc == NULL){
        printf("\nERROR: IMPOSSIBLE TO OPEN THE FILE");
        exit(1);
    }

	int *elementsVector;
	elementsVector = (int*) malloc(1000 * sizeof(int));
	int count = 0;
    int i = 0;
	
	while(1){
        if((fscanf(arc,"%i",&elementsVector[i]) == -1)){
            break;
        }
        else{
            // printf("%i ",elementsVector[i]);
			count ++;
            i++;
        }
    }
	// printf("\n %i",count);

	fclose(arc);

	mapping(elementsVector, count);

}

int main(){

    char nameTxt[60];
    printf("Digite o nome do arquivo: ");
    scanf("%s", nameTxt);

    mainSeg(nameTxt);
}

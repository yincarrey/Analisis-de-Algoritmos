#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 10
#define MAX 100

void initialization(int size);
void *MetodoBurbuja(int *array, int size);

int main(){
    
    int size;

    printf("Ingresar largo del array: ");
    scanf("%d", &size);

    initialization(size);
    return 0;
};

void initialization(int size){

    int *array;
    
    array = (int*) malloc(size * sizeof(int));

    if (array == NULL){
        printf("Error al reservar memoria.\n");
    }

    else{
        srand(time(NULL));

        for (int i = 0; i < size; i++){
            array[i] = (MIN + (rand() % (MAX - (MIN-1))));
        }

        array = (int*) realloc(array,size * sizeof(int));

        if (array == NULL){
            printf("Error al reservar memoria.\n");
        }
        else{
            MetodoBurbuja(array, size);
        }
        
    }
    
}

void *MetodoBurbuja(int *array, int size){

    int aux = 0;
    
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){

            if(array[j] > array[j+1]){

                aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
            }
        }
    }

    for (int i = 0; i < size; i++){
        printf("%d\t", array[i]);
    }

    free(array);
};
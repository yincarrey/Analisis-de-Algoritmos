#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 10
#define MAX 100
#define size 100

void initialization();
void MetodoBurbuja(int *array);

int main(){
    
    initialization();
    return 0;
};

void initialization(){

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
            MetodoBurbuja(array);
        }   
    }
}

void MetodoBurbuja(int *array){

    int aux = 0;
    
    for (int i = 0; i < size; i++){
        for (int j = size-1; j > i; j--){

            if(array[j-1] > array[j]){

                aux = array[j-1];
                array[j-1] = array[j];
                array[j] = aux;
            }
        }
    }

    for (int i = 0; i < size; i++){
        printf("%d\t", array[i]);
    }

    free(array);
};
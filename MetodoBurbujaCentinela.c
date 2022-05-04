#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <time.h>

#define MIN 10
#define MAX 100
#define size 100

void initialization();
void MetodoBurbujaCentinela(int *array);

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
            MetodoBurbujaCentinela(array);
        }   
    }
}

void MetodoBurbujaCentinela(int *array){

    int aux = 0;
    bool centinela = true;
    
    for (int i = 0; i < size; i++){

        centinela = false;
        for (int j = size-1; j > i; j--){

            if(array[j-1] > array[j]){

                aux = array[j-1];
                array[j-1] = array[j];
                array[j] = aux;
                centinela = true;
            }
        }

        if (centinela == false){
            break;
        }
    }

    for (int i = 0; i < size; i++){
        printf("%d\t", array[i]);
    }

    free(array);
};
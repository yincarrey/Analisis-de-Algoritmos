#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 10
#define MAX 100

void initialization(int size);
void MetodoInsercionBinaria(int *array, int size);

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
            MetodoInsercionBinaria(array, size);
        }     
    }
}

void MetodoInsercionBinaria(int *array, int size){

    int aux, first, last, mid;

    for (int i = 1; i < size; i++){

        aux = array[i];
        first = 0;
        last = i-1;

        while (first <= last){
            mid = (int) ((first + last)/2);
            if (aux <= array[mid]){
                last = mid - 1;
            }
            else{
                first = mid + 1;
            }
        }

        for (int k = i - 1; k >= first; k--){
            array[k+1] = array[k];
        }
        array[first] = aux;  
    }

    for (int i = 0; i < size; i++){
        printf("%d\t", array[i]);
    }

    free(array);
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 10
#define MAX 100
#define size 100

void initialization();
void MetodoInsercionBinaria(int *array);

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
            MetodoInsercionBinaria(array);
        }     
    }
}

void MetodoInsercionBinaria(int *array){

    int aux, first, last, mid;
    
    clock_t start = clock();

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

    clock_t stop = clock();
    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tiempo transcurrido en ms: %.4f", elapsed);
    
}
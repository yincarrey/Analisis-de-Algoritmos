#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 10
#define MAX 100
#define size 100

void initialization();
void MetodoInsercionDirecta(int *array);

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
            MetodoInsercionDirecta(array);
        }     
    }
}

void MetodoInsercionDirecta(int *array){

    int pos, aux;

    clock_t start = clock();

    for (int i = 0; i < size; i++){
        
        pos = i;
        aux = array[i];

        while ((pos > 0) && (aux < array[pos-1])){
            
            array[pos] = array[pos-1];
            pos--;
        }

        array[pos] = aux;
    }

    for (int i = 0; i < size; i++){
        printf("%d\t", array[i]);
    }

    free(array);

    clock_t stop = clock();
    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tiempo transcurrido en ms: %.4f", elapsed);
    
}
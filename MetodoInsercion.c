#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 10
#define MAX 100

void initialization(int size);
void MetodoInsercionDirecta(int *array, int size);

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
            MetodoInsercionDirecta(array, size);
        }     
    }
}

void MetodoInsercionDirecta(int *array, int size){

    int pos, aux;

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
    
}
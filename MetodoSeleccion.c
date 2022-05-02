#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 10
#define MAX 100

void initialization(int size);
void MetodoSeleccion(int *array, int size);

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
            MetodoSeleccion(array, size);
        }   
    }
}

void MetodoSeleccion(int *array, int size){

    int aux, min;

    for (int i = 0; i < size-1; i++){
        min = i;
        for (int j = i+1; j < size; j++){

            if (array[j] < array[min]){
                min = j;
            }  
        }
        aux = array[i];
        array[i] = array[min];
        array[min] = aux;
    }
    
    for (int i = 0; i < size; i++){
        printf("%d\t", array[i]);
    }

    free(array);
}
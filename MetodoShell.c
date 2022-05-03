#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 10
#define MAX 100

void initialization(int size);
void MetodoShell(int *array, int size);

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
            MetodoShell(array, size);
        }   
    }
}



void  MetodoShell(int *array, int size){

    int temp, j;

    for (int gap = size / 2; gap > 0; gap /= 2){

        for (int i = gap; i < size; i += 1){

            temp = array[i];

            for (j = i; j >= gap && array[j - gap] > temp; j -= gap){
                array[j] = array[j - gap];
            }
            array[j] = temp;
                
        }
    }

    for (int i = 0; i < size; i++){
        printf("%d\t", array[i]);
    }

    free(array);
}
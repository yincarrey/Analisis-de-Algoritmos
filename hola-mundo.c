#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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

    int array[size];

    srand(time(NULL));

    for (int i = 0; i < size; i++){
        array[i] = (10 + (rand() % 91));
    }

    MetodoBurbuja(array, size);
    
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
};
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 10
#define MAX 100
#define size 100

void initialization();
void MetodoShell(int *array);

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
            MetodoShell(array);
        }   
    }
}



void  MetodoShell(int *array){

    int temp, j;

    clock_t start = clock();

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

    clock_t stop = clock();
    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tiempo transcurrido en ms: %.4f", elapsed);
}
#include<stdio.h>
#include<stdlib.h>

void newArray(int*, int);
void showArray(int*, int);

int main(){
    int *array;
    int i;
    printf("Introduzca el numero de elementos que tendra el arreglo.\n");
    scanf("%d", &i);
    array = (int*) calloc(i, sizeof(int));
    newArray(array, i);
    showArray(array, i);
}

void newArray(int* a, int i){
    for(int j = 0; j < i; j++){
        printf("Introduzca el valor que quiere guardar en la posicion %d.\n", j);
        scanf("%d", &a[j]);
    }
}

void showArray(int*a, int i){
    for(int k = 0; k < i; k++){
        printf("El valor en la posicion %d del arreglo es %d. \n", k, a[k]);
    }
}


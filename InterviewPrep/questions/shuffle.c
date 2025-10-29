#include <stdlib.h>
void shuffle(int arr[], int size){
    for(int i = 0; i<size; i++){
        int k = (rand() % 5);
        int temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
}

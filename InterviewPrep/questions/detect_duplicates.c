#include "stdbool.h"
#include <stdlib.h>
#include <string.h>
/*bool has_duplicates(int arr[], int size){
    for(int i = 0; i < size-1; i++){
        int key = arr[i];
        for(int j = i+1; j < size; j++){
            if(arr[j] == key)
                return true;

        }
    }
    return false;
}*/


int max_val = 500;
bool has_duplicates(int arr[], int size){
    bool seen[max_val];
    memset(seen, 0, sizeof(seen));
    for(int i = 0; i < size-1; i++){
        if(seen[arr[i]])
            return true;
        seen[arr[i]] = true;
    }
    return false;
}

#include "stdio.h"
int sliding_window_max(int original[], int orig_size, int window_size, int output[]){
    int left = 0; 
    int right = left + window_size-1; //to start, is 2 given 3
    int sum = 0;

    for(int i = left; i < window_size; i++)
        sum+=original[left];
    //initial sum of window
    printf("init size: %d\n", sum);
    int sum_copy = sum;
    int left_copy = left;
    int right_copy = right;

    for(int i = right; i < orig_size-1; i++){
        sum_copy = sum - original[left_copy++] + original[++right_copy]; //update
        if(sum_copy > sum){
            left = left_copy;
            right = right_copy;
            sum = sum_copy;
        }
    }
    
    printf("init size: %d\n", sum);
    for(int i = 0; i < window_size; i++)
        output[i] = original[left++];


    return window_size;
}

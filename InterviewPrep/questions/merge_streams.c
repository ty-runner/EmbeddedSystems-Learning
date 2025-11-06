#include "merge_streams.h"
#include "stdio.h"
void merge_streams(Event a[], int a_size, Event b[], int b_size, Event out[]){
    int i = 0;
    int j =0;
    int idx = 0;
    printf("zTIMESTAMP: %d\n", a[0].timestamp);
    while(i < a_size && j < b_size){
        if(a[i].timestamp <= b[j].timestamp){
            out[idx] = a[i];
            i++;
        }

        else if(a[i].timestamp > b[j].timestamp){
            out[idx] = b[j];
            j++;
        }
        idx++;
    }

    printf("zTIMESTAMP: %d\n", out[0].timestamp);
    while(i < a_size){
        out[idx] = a[i];
        i++;
        idx++;
    }

    while(j < b_size){
        out[idx] = b[j];
        j++;
        idx++;
    }

    printf("zTIMESTAMP: %d\n", out[0].timestamp);

}

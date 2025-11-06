#ifndef MERGE_STREAMS_H
#define MERGE_STREAMS_H

typedef struct{
    int timestamp;
    int value;
} Event;

void merge_streams(Event a[], int a_size, Event b[], int b_size, Event out[]);
#endif

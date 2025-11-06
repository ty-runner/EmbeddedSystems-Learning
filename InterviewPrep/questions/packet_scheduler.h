#ifndef PACKET_SCHEDULER_H
#define PACKET_SCHEDULER_H

typedef struct {
    int id;
    int prio;
} Task;

int schedule(Task tasks[], int size, int order[]);
#endif


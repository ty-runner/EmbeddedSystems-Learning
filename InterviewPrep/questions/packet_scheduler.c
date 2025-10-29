#include "packet_scheduler.h"


int schedule(Task tasks[], int size, int order[]){
    //sort tasks by prio
    //
    for(int i = 0; i < size-1; i++){
        for(int j = i+1; j < size; j++){
            if(tasks[i].prio > tasks[j].prio){
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    for(int i = 0; i < size; i++){
        order[i] = tasks[i].id;
    }
    return size;
}


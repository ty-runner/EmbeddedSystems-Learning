#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#define BUFFER_SIZE 5
typedef struct{ //FIFO behavior
	int buffer[BUFFER_SIZE];
	int* buf_start; //start location of buffer region
	int* buf_end; //end location of buffer region
	int* data_start;
	int* data_end;
} RB;

void rb_init(RB* rb){
	rb->buf_start = rb->buffer;
	rb->buf_end = rb->buffer + BUFFER_SIZE;
	rb->data_end = rb->buf_start;
	rb->data_start = rb->buf_start;
}
bool is_empty(RB* rb){
	return (rb->data_start == rb->data_end);
}
bool is_full(RB* rb){
	//if we increment our write pointer by 1 and is at the boundary, we wrap around
	return ((rb->data_end + 1 == rb->buf_end) ? rb->buf_start : rb->data_end + 1) == rb->data_start;
}

bool write(RB* rb, int data){
	if(is_full(rb))
		return false;
	*(rb->data_end) = data;
	rb->data_end = (rb->data_end + 1 == rb->buf_end) ? rb->buf_start : rb->data_end+1;
	return true;
}

bool read(RB* rb, int* data){
	if(is_empty(rb))
		return false;
	*data = *(rb->data_start);
	rb->data_start = (rb->data_start + 1 == rb->buf_end) ? rb->buf_start : rb->data_start+1;
	return true;
}

void print_buffer(RB* rb){
	for(int i = 0; i < BUFFER_SIZE; i++){
		printf("%d\n", (rb->buffer)[i]);
	}
}

int main(){
	    RB rb;
	    rb_init(&rb);
	    // Write 5 bytes
	    for (uint8_t i = 0; i < 5; i++)
		write(&rb, i + 10);
	    printf("IS FULL? %d\n", is_full(&rb));
	    print_buffer(&rb);
	    // Read 3 bytes
	    //
	    //
	    int val;
	    while (!is_empty(&rb)) {
		read(&rb, &val);
		printf("Read: %d\n", val);
	    }
	    printf("\n");
	    for (int i = 0; i < 3; i++) {
		if(read(&rb, &val))
			printf("Read: %d\n", val);
		else
			printf("EMPTY\n");
	    }
	    printf("\n");
	    // Write 4 more bytes (wraps around)
	    for (uint8_t i = 0; i < 4; i++)
		write(&rb, i + 20);

	    // Read all remaining bytes
	    while (!is_empty(&rb)) {
		read(&rb, &val);
		printf("Read: %d\n", val);
	    }
	    return 0;
}

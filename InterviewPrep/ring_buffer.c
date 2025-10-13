#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define BUFFER_SIZE 8  // fixed size

typedef struct {
    uint8_t buffer[BUFFER_SIZE];
    uint8_t *buf_start;
    uint8_t *buf_end;
    uint8_t *data_start;  // next byte to read
    uint8_t *data_end;    // next byte to write
} RingBuffer;

void rb_init(RingBuffer *rb){
    rb->buf_start = rb->buffer;
    rb->buf_end = rb->buf_start + BUFFER_SIZE;
    rb->data_start = rb->buf_start;
    rb->data_end = rb->data_start;
}

bool rb_is_empty(RingBuffer *rb){
    return(rb->data_start == rb->data_end);
}

bool rb_is_full(RingBuffer *rb){
    return ((rb->data_end +1 == rb->buf_end) ? rb->buf_start : rb->data_end+1) ==rb->data_start;
}

bool rb_read(RingBuffer *rb, uint8_t* val){
    //read the data means we are consuming a block of data
    if(rb_is_empty(rb))
        return false;

    *val = *rb->data_start;
    rb->data_start = (rb->data_start+1 == rb->buf_end) ? rb->buf_start : rb->data_start+1;
    return true;
}

bool rb_write(RingBuffer *rb, uint8_t val){
    if(rb_is_full(rb))
        return false;

    *rb->data_end = val;
    rb->data_end = (rb->data_end + 1 == rb->buf_end) ? rb->buf_start : rb->data_end+1;
    return true;
}
int main() {
    RingBuffer rb;
    rb_init(&rb);

    // Write 5 bytes
    for (uint8_t i = 0; i < 5; i++)
        rb_write(&rb, i + 10);

    // Read 3 bytes
    uint8_t val;
    for (int i = 0; i < 3; i++) {
        rb_read(&rb, &val);
        printf("Read: %d\n", val);
    }

    // Write 4 more bytes (wraps around)
    for (uint8_t i = 0; i < 4; i++)
        rb_write(&rb, i + 20);

    // Read all remaining bytes
    while (!rb_is_empty(&rb)) {
        rb_read(&rb, &val);
        printf("Read: %d\n", val);
    }

    return 0;
}


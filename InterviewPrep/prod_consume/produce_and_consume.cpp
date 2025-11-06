#include "mutex.h"
#include "ring_buffer.h"
#include <thread>
#include <vector>
#include <iostream>

Mutex spin_lock;
RingBuffer rb;

void producer(std::vector<int>& vec){
    //write data into ring buffer
    static int idx = 0;
    while(idx < vec.size()){
        spin_lock.lock();
        if(!rb.is_full()){
            rb.write(vec[idx]);
            idx++;
        }
        spin_lock.unlock();
    }
}
void consumer(std::vector<int>& vec){
    //read data into ring buffer
    static int idx = 0;
    int val;
    while(idx < vec.size()){
        spin_lock.lock();
        if(!rb.is_empty()){
            rb.read(val);
            vec[idx] = val;
            idx++;
        }
        spin_lock.unlock();
    }
}
int main(){
    std::vector<int> input = {5, 4, 3, 2, 1};
    std::vector<int> output(input.size());
    std::thread p(producer, std::ref(input));
    std::thread c(consumer, std::ref(output));

    p.join();
    c.join();

    std::cout << "Final output: ";
    for (auto v : output)
        std::cout << v << " ";
    std::cout << std::endl;

    return 0;
}

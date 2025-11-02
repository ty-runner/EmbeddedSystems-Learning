#ifndef MUTEX_H
#define MUTEX_H

#include <iostream>
#include <vector>
#include <atomic>
class Mutex{
	private:
        std::atomic_flag lock_flag = ATOMIC_FLAG_INIT; //init to false
	public:
        void lock(){
            std::cout << "LOCKING\n";
            while(lock_flag.test_and_set(std::memory_order_acquire)){}
        }
        void unlock(){
            std::cout << "UNLOCKING\n";
            lock_flag.clear(std::memory_order_release);
        }
};
#endif

#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <iostream>
#include <vector>
#define BUFFER_SIZE 5

class RingBuffer{
	private:
		std::vector<int> buffer;
		int* buf_start; //start location of buffer region
		int* buf_end; //end location of buffer region
		int* data_start;
		int* data_end;
	public:
		RingBuffer(size_t size = BUFFER_SIZE){ //constructor
			buffer.resize(size);
			buf_start = buffer.data();
			buf_end = buffer.data() + buffer.size();
			data_start = buf_start;
			data_end = buf_start;
			std::cout << "SIZE: " << buffer.size() << std::endl;
		}

		bool is_empty(){
			return (data_start == data_end);
		}

		bool is_full(){
			return (data_end + 1 == buf_end ? buf_start : data_end + 1) == data_start;
		}

		bool write(int data){
			if(is_full()) //call might be problematic
				return false;
			*data_end = data;
			data_end = data_end + 1 == buf_end ? buf_start : data_end+1;
			return true;
		}

		bool read(int& data){
			if(is_empty()) //call might be problematic
				return false;
			data = *data_start;
			data_start = data_start + 1 == buf_end ? buf_start : data_start+1;
			return true;
		}

		void print_buffer(){
			for(auto i : buffer){
				std::cout << "i = " << i << std::endl;
			}
		}
		
		~RingBuffer(){
			std::cout << "exiting the stack" << std::endl;
		}
};
#endif

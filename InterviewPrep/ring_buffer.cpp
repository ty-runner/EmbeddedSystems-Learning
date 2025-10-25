#include <iostream>
#include <vector>
#define BUFFER_SIZE 5

class RingBuffer{
	private:
		/*struct RB{ //FIFO behavior
			int buffer[BUFFER_SIZE];
			int* buf_start; //start location of buffer region
			int* buf_end; //end location of buffer region
			int* data_start;
			int* data_end;
		};*/
		//int buffer[BUFFER_SIZE];
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

int main(){
	    RingBuffer rb;
	    printf("IS FULL? %d\n", rb.is_full());
	    printf("IS EMPTY? %d\n", rb.is_empty());
	    // Write 5 bytes
	    for (uint8_t i = 0; i < 5; i++)
		rb.write(i + 10);
	    rb.print_buffer();
	    printf("IS FULL? %d\n", rb.is_full());
	    // Read 3 bytes
	    //
	    //
	    
	    int val;
	    while (!rb.is_empty()) {
		rb.read(val);
		printf("Read: %d\n", val);
	    }
	    printf("\n");
	    for (int i = 0; i < 3; i++) {
		if(rb.read(val))
			printf("Read: %d\n", val);
		else
			printf("EMPTY\n");
	    }
	    printf("\n");
	    // Write 4 more bytes (wraps around)
	    for (uint8_t i = 0; i < 5; i++)
		rb.write(i + 20);
	    rb.read(val);
	    rb.write(24);
	    rb.print_buffer();
	    // Read all remaining bytes
	    while (!rb.is_empty()) {
		rb.read(val);
		printf("Read: %d\n", val);
	    }
	    return 0;
}

#include <iostream>
#include <assert.h>
//producer adds to a buffer of size N at a rate of X elements per second
//consumer takes Y elements out of the buffer every m seconds
//determine minimum y to satify buffer overflow mitigation
int determine_min_y(int ti, int x, int m, int N){
    int res = x*ti - N;
    if(res % ((ti/m))){
        res = res / ((ti/m));
        res += 1; //it will be truncated if there is a remainder, for the inequality to hold true, round up
        return res;
    }
    return res / ((ti/m));
}


int main(){
    int ti = 20;
    int x = 3;
    int m = 1;
    int N = 19;
    int y = determine_min_y(ti, x, m, N);
    std::cout << determine_min_y(ti, x, m, N);
    
    int buffer_size = 0;
    for(int i = 0; i < ti; i++){
        buffer_size += x;
        assert(buffer_size <= N);
        buffer_size -= ti % m == 0 ? y : 0;
        assert(buffer_size >= 0);
    }
    std::cout << "Final size: " << buffer_size << std::endl;
     
    return 0;
}

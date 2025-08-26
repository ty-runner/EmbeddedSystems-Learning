#include <iostream>

float get_height(){
    std::cout<<"Enter height of the tower in meters: ";
    float res;
    std::cin >> res;
    return res;
}

void sim_time(float height){
    float res = height;
    int i = 0;
    while(res > 0.0){
        res = height - (9.8 * i * i / 2);
        if(res > 0.0)
            std::cout<<"At "<<i<<" seconds, the ball is at height: "<<res<<" meters\n"; 
        else
            std::cout<<"At "<<i<<" seconds, the ball is on the ground \n"; 
        i++;

    }
}
int main(){
    //output the height of the ball above the ground after 0,1,2,3,4,5, cant be < 0
    float height = get_height();
    sim_time(height);
    return 0;
}


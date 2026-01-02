#include <algorithm> // std::find, std::min_element
#include <cmath> // std::abs
#include <cstddef> // std::size_t
#include <iostream>
#include <vector>
#include "Random.h"

#define RAND_RANGE_MIN 2
#define RAND_RANGE_MAX 4
int getStartNumber(){
    int start {};
    std::cout << "Start where? ";
    std::cin >> start;
    return start;
}

int getSequenceCount(){
    int count {};
    std::cout << "How many? ";
    std::cin >> count;
    return count;
}
int getUserGuess(){
    int guess {};
    std::cin >> guess;
    return guess;
}
std::vector<int> generateNums(int start, int count){ //currently generates squares
    std::vector<int> nums (count);
    int mult = Random::get<int>(RAND_RANGE_MIN,RAND_RANGE_MAX); //our random multiplying
    for(int i = 0; i < count; i++){
        nums[i] = (start + i) * (start + i) * mult;
    }
    std::cout << "I generated " << count<< " square numbers. Do you know what each number is after multiplying it by " << mult << "?\n";
    return nums;
}

bool findAndRemove(std::vector<int>& nums, int guess){
    auto found{ std::find(nums.begin(), nums.end(), guess)};
    if(found == nums.end())
        return false;
    nums.erase(found);
    return true;
}

void printSuccess(std::vector<int> nums){
    std::cout << "Nice! ";
    if(nums.size() > 0)
        std::cout << nums.size() << " numbers left.\n";
    else
        std::cout << "You found all nums!\n";
    return;
}

void printFailure(std::vector<int> nums, int guess){
    std::cout << "whomp whomp you lose\n";
    return;
}
int main(){
    std::vector<int> nums = generateNums(getStartNumber(), getSequenceCount());

    while (true)
    {
        int guess{ getUserGuess() };

        if (!findAndRemove(nums, guess))
        {
            printFailure(nums, guess);
            break;
        }

        printSuccess(nums);
        if (nums.size() == 0)
            break;
    }
    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
void string_to_int_pair(std::string line, int& x, int& y){
	std::size_t pos = line.find("   ");
	if(pos != std::string::npos){
		x = std::stoi(line.substr(0,pos));
		y = std::stoi(line.substr(pos + 3));
	}
	std::cout << x << std::endl;
}

int main() {
    std::ifstream inputFile("day1.txt"); // Open the file
    std::vector<int> arr0;
    std::vector<int> arr1;
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) { // Read line by line
	    int x, y;
            //std::cout << line << std::endl;
	    string_to_int_pair(line, x, y);		
	    arr0.push_back(x);
	    arr1.push_back(y);
        }
        inputFile.close(); // Close the file
    } else {
        std::cerr << "Error: Unable to open file." << std::endl;
        return 1; // Indicate an error
    }
    std::sort(arr0.begin(), arr0.end());
    std::sort(arr1.begin(), arr1.end());
    int total = 0;
    for(int i = 0; i < arr0.size(); i++){
	    std::cout << "INTS " << arr0[i] << std::endl;
	    total += (arr0[i] > arr1[i] ? arr0[i]-arr1[i] : arr1[i] - arr0[i]);
    }
    std::cout << "RESULT: " << total;
    //sort both arrays
    //
    return 0; // Indicate successful execution
}

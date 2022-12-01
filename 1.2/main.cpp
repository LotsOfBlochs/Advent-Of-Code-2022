#include <fstream>
#include <math.h>
#include <string>
#include <iostream>

int main(int argc, char const *argv[])
{
	if(argc != 2){
		std::cout << "Please include file path as argument!";
		return 1;
	}
	std::ifstream stream = std::ifstream(argv[1], std::ios::in);
	if(!stream.is_open()){
		std::cout << "Error opening file.";
		std::cout << stream.exceptions();
	}
	int highestCalories = 0;
	int secondCalories = 0;
	int thirdCalories = 0;
	int currentCalories = 0;
	for(std::string str; getline(stream, str);){
		if(str.length() == 0){
			if(currentCalories > highestCalories){
				thirdCalories = secondCalories;
				secondCalories = highestCalories;
				highestCalories = currentCalories;
			} else if(currentCalories > secondCalories){
				thirdCalories = secondCalories;
				secondCalories = currentCalories;
			} else if(currentCalories > thirdCalories){
				thirdCalories = currentCalories;
			}
			currentCalories = 0;
		}
		else{
			currentCalories += std::stoi(str);
		}
	}
	std::cout << highestCalories << ", " << secondCalories << ", " << thirdCalories << std::endl;
	std::cout << highestCalories + secondCalories + thirdCalories;
	return 0;
}

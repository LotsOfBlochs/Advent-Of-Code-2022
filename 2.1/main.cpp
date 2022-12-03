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
	int totalScore = 0;
	for(std::string str; getline(stream, str);){
		char opponent = (str.at(0) - 'A');
		char me = (str.at(2) - 'X');
		
		totalScore += me + 1;
		if(opponent == me)
			totalScore += 3;
		else if((opponent == 0 && me == 1) || (opponent == 1 && me == 2) || (opponent == 2 && me == 0))
			totalScore += 6;
	}
	std::cout << totalScore;
	return 0;
}

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
		char result = (str.at(2) - 'X');
		
		if(result == 1)
			totalScore += 3 + opponent + 1;
		else if(result == 2)
			totalScore += 6 + (opponent + 1) % 3 + 1;
		else
			if(opponent == 0)
				totalScore += 3;
			else
				totalScore += (opponent - 1) % 3 + 1;
	}
	std::cout << totalScore;
	return 0;
}

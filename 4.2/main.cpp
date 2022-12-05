#include <fstream>
#include <string>
#include <iostream>
#include <unordered_map>

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
	int count = 0;
	for(std::string str; getline(stream, str);){
		int start1, end1, start2, end2;
		start1 = std::stoi(str.substr(0, str.find('-')));
		end1 = std::stoi(str.substr(str.find('-') + 1, str.find(',') - str.find('-')));
		start2 = std::stoi(str.substr(str.find(',') + 1, str.find_last_of('-') - str.find(',')));
		end2 = std::stoi(str.substr(str.find_last_of('-') + 1, str.size() - str.find_last_of('-')));
		
		if((start2 <= start1 && start1 <= end2) 
		  ||(start1 <= start2 && start2 <= end1) 
		  || (start1 <= end2 && end2 <= end1) 
		  || (start2 <= end1 && end1 <= end2))
		  	count++;

	}
	std::cout << count;
	return 0;
}

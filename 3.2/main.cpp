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
	int priority = 0;
	for(std::string firstElf; getline(stream, firstElf);){
		std::string secondElf;
		getline(stream, secondElf);
		std::string thirdElf;
		getline(stream, thirdElf);
		std::unordered_map<char, char> characters;

		for(char character : firstElf)
			characters[character] = 1;

		for(char character : secondElf)
			characters[character] = (characters[character] >= 1)? 2 : 0;

		for(char character : thirdElf)
			if(characters[character] == 2){
				if(character < 'a')
					priority += character - 'A' + 27;
				else
					priority += character - 'a' + 1;
				break;
			}
	}
	std::cout << priority;
	return 0;
}

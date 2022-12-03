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
	for(std::string str; getline(stream, str);){
		std::string firstHalf = str.substr(0, str.length()/2);
		std::string secondHalf = str.substr(str.length()/2);
		std::unordered_map<char, bool> characters;

		for(char character : firstHalf)
			characters[character] = true;

		for(char character : secondHalf)
			if(characters[character]){
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

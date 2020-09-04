#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "param.hpp"

int main(){
	std::string command;
	std::vector<std::string> parseCommand;
	std::string tempCommand;
	std::stringstream sstream;

	std::cout << "$$$ ";

	std::getline(std::cin, command);
	sstream.clear();
	sstream << command;
	
	while(sstream >> tempCommand){
		parseCommand.push_back(tempCommand);
	}

	Param param(parseCommand);

}

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "parse.hpp"
#include "param.hpp"

int main(){
	std::string command;
	std::vector<std::string> parsedCommand;

	std::cout << "$$$ ";
	std::getline(std::cin, command);

	Parse toParse;
	parsedCommand = toParse.Parsing(command); 

	Param param(parsedCommand);
	param.PrintParams();

}

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "parse.hpp"
#include "param.hpp"

int main(int argc, char *argv[]){
	std::string command;
	std::vector<std::string> parsedCommand;

	std::cout << "$$$ ";
	std::getline(std::cin, command);

	Parse toParse;
	parsedCommand = toParse.Parsing(command); 

	Param param(parsedCommand);
	param.CheckArguments();

	std::string debug = "-Debug";
	std::string toCompare;
	
	for(int i = 0; i < argc; i++){
		toCompare = *(argv+i);	
		
		if(toCompare == debug){
			param.PrintParams();
			break;
		}
	}
}

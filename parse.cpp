#include "parse.hpp"

std::vector<std::string> Parse::Parsing(std::string command){

	char *token;
	char tempCommand[command.length()+1];
	strcpy(tempCommand,command.c_str());
	token = strtok(tempCommand, " ");

	while(token != NULL){
		this->parsed.push_back(token);
		token = strtok(NULL, " ");
	}

	return this->parsed;
}

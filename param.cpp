#include "param.hpp"

Param::Param(std::vector<std::string> inputCommand){

	//intial value is NULL
	this->inputRedirect = NULL;
	this->outputRedirect = NULL;

	//calls private function to intialize all private variables
	ParseCommandLine(inputCommand);
	
}

void Param::PrintParams(){

	std::cout << "InputRedirect: [" << ((inputRedirect != NULL) ? inputRedirect : "NULL") << "]" << std::endl 
		<< "OutputRedirect: [" << ((outputRedirect != NULL) ? outputRedirect : "NULL") << "]" << std::endl 
		<< "ArgumentCount: [" << argumentCount << "]" << std::endl;
	
	for (int i = 0; i < argumentCount; i++){
		std::cout << "ArgumentVector[" << i << "]: [" <<
		argumentVector[i] << "]" << std::endl;
	}
}

void Param::ParseCommandLine(std::vector<std::string> inputCommand){

	int numOfArgs = 0;

	for(unsigned int i = 0; i < inputCommand.size(); i++){
		if(inputCommand.at(i).at(0) == '<' && inputCommand.at(i).size() > 1){
			this->inputRedirect = &inputCommand.at(i).at(1);
		}
		else if(inputCommand.at(i).at(0) == '>' && inputCommand.at(i).size() > 1){
			this->outputRedirect = &inputCommand.at(i).at(1);
		}
		else{
			this->argumentVector[numOfArgs] = &inputCommand.at(i).at(0);
			numOfArgs++;
		}
	}
	
	this->argumentCount = numOfArgs;

}

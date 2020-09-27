/** @file param.cpp
 *  @brief This Param object does error handling and assigns tokenized command input to variables
 *
 *  This object reads in a vector<string> which include words that have been parsed from the command line, 
 *  and stores them into their respective slot. This object can print the class variables assignments
 *  when the program is run in -Debug mode. Param also checks for keyword exit and invalid inputs.
 *
 *  @author Thati Vang (tv20)
 *  @author Kenya Holland (kmh99)
 */

#include "param.hpp"

Param::Param(std::vector<std::string> inputCommand){
	this->inputRedirect = NULL;
	this->outputRedirect = NULL;

	ParseCommandLine(inputCommand);
}

void Param::ParseCommandLine(std::vector<std::string> inputCommand){
	/*  counter  */
	int numOfArgs = 0;
	
	for(unsigned int i = 0; i < inputCommand.size(); i++){
		/*  checks for < or > with a size = 1, terminating program.
		 *  checks for < or > with size > 1, assigning them to inputRedirect or outputRedirect.
                 *  all other strings are assigned to argumentVector[],
		 *  and increment the counter for the total number of arguments.
		 */
		if(inputCommand.at(i).at(0) == '<' && inputCommand.at(i).size() == 1){
			std::cout << "ERROR: specify input name" << std::endl << "PROGRAM TERMINATED" << std::endl;
			exit(1);
		}
		else if(inputCommand.at(i).at(0) == '>' && inputCommand.at(i).size() == 1){
			std::cout << "ERROR: specify output name" << std::endl << "PROGRAM TERMINATED" << std::endl;
			exit(1);
		}
		else if(inputCommand.at(i).at(0) == '<' && inputCommand.at(i).size() > 1){
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


void Param::PrintParams(){
	std::cout << "InputRedirect: [" << ((inputRedirect != NULL) ? inputRedirect : "NULL") << "]" << std::endl 
		<< "OutputRedirect: [" << ((outputRedirect != NULL) ? outputRedirect : "NULL") << "]" << std::endl 
		<< "ArgumentCount: [" << argumentCount << "]" << std::endl;
	
	for (int i = 0; i < argumentCount; i++){
		std::cout << "ArgumentVector[" << i << "]: [" <<
		argumentVector[i] << "]" << std::endl;
	}
}

void Param::CheckArguments(){
	std::string toExit = "exit";
	std::string toCompare;

	/*  loops through argumentVector[],
	 *  sets toCompare with argumentVector[i]
	 *  and compares it with toExit
	 */
	for(int i = 0; i < argumentCount; i++){
		toCompare = this->argumentVector[i];
	
		if(toCompare == toExit){
			std::cout << "PROGRAM TERMINATED" << std::endl;
			exit(0);
		}
	}

	/*  If atoi() returns 0, then the input for the second argument is not a number and is invalid  */
	int argumentTwo = atoi(this->argumentVector[1]);
	
	if(argumentTwo == 0){
		std::cout << "ERROR: second argument must be integer" << std::endl << "PROGRAM TERMINATED" << std::endl;
		exit(1);
	}
}


const char* Param::getNumProcesses(){
	const char* processes = this->argumentVector[1];
	return processes;
}

const char* Param::getFileName(){
	const char *name = this->argumentVector[0];
	return name;
}

const char* Param::getInputRedirect(){
	const char* input = this->inputRedirect;
	return input;
}

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

Param::Param(){
	this->inputRedirect = NULL;
	this->outputRedirect = NULL;
	this->argumentCount = 0;
}

void Param::Initialize(char** tokenizedCommand,int maxTokens){
	/*  counter  */
	int numOfArgs = 0;
	
	for(int i = 0; i < maxTokens; i++){
		/*  checks for < or > with a size = 1, terminating program.
		 *  checks for < or > with size > 1, assigning them to inputRedirect or outputRedirect.
                 *  all other strings are assigned to argumentVector[],
		 *  and increment the counter for the total number of arguments.
		 */
		if(tokenizedCommand[i][0] == '<' && tokenizedCommand[i][1] == '\0'){
			std::cout << "ERROR: specify input name" << std::endl << "PROGRAM TERMINATED" << std::endl;
			exit(1);
		}
		else if(tokenizedCommand[i][0] == '>' && tokenizedCommand[i][1] == '\0'){
			std::cout << "ERROR: specify output name" << std::endl << "PROGRAM TERMINATED" << std::endl;
			exit(1);
		}
		else if(tokenizedCommand[i][0] == '<' && tokenizedCommand[i][0] != '\0'){
			this->inputRedirect = tokenizedCommand[i];
		}
		else if(tokenizedCommand[i][0] == '>' && tokenizedCommand[i][0] != '\0'){
			this->outputRedirect = tokenizedCommand[i];
		}
		else{
			//if(numOfArgs == 1){
			//	if(atoi(tokenizedCommand[i]) != 0){
					this->argumentVector[numOfArgs] = tokenizedCommand[i];
			//	}
			//}
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

bool Param::CheckExit(){
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
			return false;
		}
	}

	/*  If atoi() returns 0, then the input for the second argument is not a number and is invalid  */
	
	return true;
}


const char* Param::GetNumProcesses(){
	const char* processes = this->argumentVector[1];
	return processes;
}

const char* Param::GetFileName(){
	const char *name = this->argumentVector[0];
	return name;
}

const char* Param::GetRange(){
	const char *range = this->argumentVector[2];
	return range;
}

const char* Param::GetInputRedirect(){
	const char* input = this->inputRedirect;
	return input;
}

const char* Param::GetOutputRedirect(){
	const char* output = this->outputRedirect;
	return output;
}

void Param::FreeMemory(){
	for(int i = 0; i < this->argumentCount; i++){
		delete[] this->argumentVector[i];
	}
	//delete[] this->argumentVector;
	this->inputRedirect = nullptr;
	this->outputRedirect = nullptr;
	this->argumentCount = 0;
}
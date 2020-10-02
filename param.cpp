/** @file param.cpp
 *  @brief This Param object does error handling and assigns tokenized command input to variables
 *
 *  This object reads in a char** which include words that have been parsed from the command line, 
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

bool Param::Initialize(char** tokenizedCommand,int maxTokens){
	int numOfArgs = 0;
	
	//loops through each token and assigns them correctly to the class variables
	for(int i = 0; i < maxTokens; i++){
		 //checks token to see if it only consist of a single character < or >
		if(tokenizedCommand[i][0] == '<' && tokenizedCommand[i][1] == '\0'){
			std::cout << "ERROR: specify input name" << std::endl;
			return false;
		}
		else if(tokenizedCommand[i][0] == '>' && tokenizedCommand[i][1] == '\0'){
			std::cout << "ERROR: specify output name" << std::endl;
			return false;
		}
		//assigns to input or output redirect if the token is accompanied by > or <
		else if(tokenizedCommand[i][0] == '<' && tokenizedCommand[i][0] != '\0'){
			this->inputRedirect = tokenizedCommand[i];
		}
		else if(tokenizedCommand[i][0] == '>' && tokenizedCommand[i][0] != '\0'){
			this->outputRedirect = tokenizedCommand[i];
		}
		//assigns all other tokens to the argumentVector
		else{
			this->argumentVector[numOfArgs] = tokenizedCommand[i];
			numOfArgs++;
			//keeps trak of the index
		}
	}
	
	//initialized the argumentCount
	this->argumentCount = numOfArgs;
	
	//returns false due to error to skip evrything and tne loops back to user input
	//otherwise, returns true
	return true;
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

void Param::CheckExit(){
	std::string toExit = "exit";
	std::string toCompare;

	//loops through argumentVector[] and compares it with "exit"
	//if true, will terminate
	for(int i = 0; i < argumentCount; i++){
		toCompare = this->argumentVector[i];
	
		if(toCompare == toExit){
			std::cout << "PROGRAM TERMINATED" << std::endl;
			exit(0);
		}
	}
}

bool Param::CheckArgumentTwo(){
	//returns false to loop back to user input when there are less than 2 comman inputs
	if(argumentCount < 2){
		std::cout << "ERROR: enter correct filename and/or number of processes" << std::endl;
		return false;
	}
	
	//checks to see if the argumentVector[1] is a number
	//if fase, then program will terminate
	if(argumentCount > 1){
		int argumentTwo = atoi(this->argumentVector[1]);
	
		if(argumentTwo == 0){
			std::cout << "ERROR: second argument must be integer" << std::endl;
			exit(1);
		}
	}
	
	return true;
}

char* Param::GetNumProcesses(){
	return this->argumentVector[1];
}

char* Param::GetFileName(){
	return this->argumentVector[0];
}

char* Param::GetRange(){
	return this->argumentVector[2];
}

char* Param::GetInputRedirect(){
	return this->inputRedirect;
}

char* Param::GetOutputRedirect(){
	return this->outputRedirect;
}
/** @file parse.cpp
 *  @brief A Parse object that handles tokenizing input
 *
 *  This object reads in a string, which is a series of words seperated by spaces,
 *  and uses strtok() function to seperate each word. 
 *
 *  @author Thati Vang (tv20)
 *  @author Kenya Holland (kmh99)
 */

#include "parse.hpp"

Parse::Parse(){
	this->tokens = nullptr;
	this->maxTokens = 0;
}

char** Parse::Tokenize(std::string *commandPtr){
	//convert from const char* to char*
	char* convertString = const_cast<char*>(commandPtr->c_str());

	//tokenize first word
	char* token = strtok(convertString, " ");
	std::vector<char*> holdTokens;

	//continues until end of string
	while(token != NULL){
		//increment total tokens
		this->maxTokens++;
		
		//pushes tokens onto a vector
		holdTokens.push_back(token);
		
		//get next token
		token = strtok(NULL, " ");
	}
	
	//allocate space
	this->tokens = new char*[maxTokens];
	
	//set max characters for each word
	int max = 32;
	for(int i = 0; i < maxTokens; i++){
		this->tokens[i] = new char[max];
	}
	
	//initialize tokens with the ones in vector
	for(int i = 0; i < maxTokens; i++){
		this->tokens[i] = holdTokens.at(i);
	}

	return this->tokens;
}

int Parse::GetMaxTokens(){
	return this->maxTokens;
}

void Parse::FreeMemory(){
	for(int i = 0; i < this->maxTokens; i++){
		//std::cout << "token[" << i << "]: " << tokens[i] << std::endl;
		//delete[] tokens[i];
	}
	
	delete[] this->tokens;
	
	for(int i = 0; i < this->maxTokens; i++){
		//std::cout << "after token[" << i << "]: " << tokens[i] << std::endl;
	}
	
}
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
	char* convertString = const_cast<char*>(commandPtr->c_str());

	char* token = strtok(convertString, " ");
	std::vector<char*> holdTokens;

	while(token != NULL){
		this->maxTokens++;
		holdTokens.push_back(token);
		token = strtok(NULL, " ");
	}
	
	this->tokens = new char*[maxTokens];
	
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
		delete[] this->tokens[i];
	}
	delete[] this->tokens;
	
}
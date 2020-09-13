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

std::vector<std::string> Parse::Parsing(std::string command){
	/*  stores a word  */
	char *token;

	/*  a char to store the the user input, command  */
	char tempCommand[command.length()+1];
	
	/*  copies command to tempCommand, 
	 *  convert from string to char
	 */
	strcpy(tempCommand,command.c_str());

	/*  tokenize the first word in tempCommand until a space is detected  */
	token = strtok(tempCommand, " ");

	/*  pushes the token onto the vector parsed, then
	 *  assigns token the next word and loops until
	 *  end of line
	 */
	while(token != NULL){
		this->parsed.push_back(token);
		token = strtok(NULL, " ");
	}

	return this->parsed;
}

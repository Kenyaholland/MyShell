/** @file parse.cpp
 *  @brief A Parse object that handles tokenizing input
 *
 *  This object reads in a string - which is a series of words seperated by spaces - and uses strtok()
 *  function to seperate each word.
 *
 *  @author Thati Vang (tv20)
 *  @author Kenya Holland (kmh99)
 */

#include "parse.hpp"

/* @brief returns the vector to main()
 *
 * Creates local variables char pointer called token
 * and a char array called tempCommand of size of amount
 *  of words in command. Then strcopt() is used to copy
 *  the string command into the char tempCommand.
 *  strtok() then assigns tempCommand and a delimiter
 *  to char pointer token. Token is then put through a
 *  while loop until empty and pushes each word into
 *  the vector called parsed. Function then returns
 *  parsed vector.
 *
 * @param command The string of words the user input from main
 * @return vector<string>
 */
std::vector<std::string> Parse::Parsing(std::string command){
	
	/* stores command and delimiter when assigned to strtok() function */
	char *token;
	/*to store string command as char to use in strtok*/
	char tempCommand[command.length()+1];
	
	/*copies string command into a char command variable tempCommand */
	strcpy(tempCommand,command.c_str());

	/* stores tempCommand and delimiter to token for parsing */
	token = strtok(tempCommand, " ");

	/* goes through tempCommand and pushes each word seperated by delimiter to the class vector called  parsed */
	while(token != NULL){
		this->parsed.push_back(token);
		token = strtok(NULL, " ");
	}

	return this->parsed;
}

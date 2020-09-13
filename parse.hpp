/** @file parse.hpp
 *  @brief A Parse object that handles tokenizing input
 *
 *  This object reads in a string, which is a series of words seperated by spaces,
 *  and uses strtok() function to seperate each word. 
 *
 *  @author Thati Vang (tv20)
 *  @author Kenya Holland (kmh99)
 */

#ifndef PARSE_HPP
#define PARSE_HPP

/*  Includes  */
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>

class Parse{
	private:
		/*  Vector that stores the parsed commands  */
		std::vector<std::string> parsed; 
	public:
		/** @brief Parses and returns the vector of tokens to main().
		 *
		 *  Creates local variables char* token and 
		 *  char tempCommand[] with its size equal to the 
		 *  user input's + 1. This is to ensure that tempCommand
		 *  have enough memory to add the end of line character "\0".
		 *  Then strcpy() is used to copy the user's input
		 *  into tempCommand[]. The strtok() function is used to
		 *  tokenize the first word in tempCommand. 
		 *  The token is pushed onto the vector parsed. The token
		 *  is assigned the next word from tempCommand
		 *  in a loop until end of line.
		 *  Function then returns the vector.
		 *
		 *  @param command The string of words from user input.
		 *  @return vector<string> Tokens of the command line.
		 */
		std::vector<std::string> Parsing(std::string); 
};

#endif

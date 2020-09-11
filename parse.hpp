/** @file parse.hpp
 *  @brief A Parse object that handles tokenizing input
 *
 *  This object reads in a string - which is a series of words seperated by spaces - and uses strtok()
 *  function to seperate each word. 
 *
 *  @author Thati Vang (tv20)
 *  @author Kenya Holland (kmh99)
 */

#ifndef PARSE_HPP
#define PARSE_HPP

/* Includes */
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>

class Parse{
	private:
		/*
		 * Vector that stores the parsed commands
		 */
		std::vector<std::string> parsed; 
	public:
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
		std::vector<std::string> Parsing(std::string); 
};

#endif

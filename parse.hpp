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
		char** tokens;
		int maxTokens;
	public:
		Parse();
		char** Tokenize(std::string *);
		int GetMaxTokens();
		void FreeMemory();
};

#endif

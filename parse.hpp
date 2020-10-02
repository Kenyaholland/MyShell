/** @file parse.hpp
 *  @brief A Parse object that handles tokenizing input
 *
 *  This object reads in a *string, and uses tokenizes each word. 
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
		/** @brief Constructor
		 *
		 *	Initialize tokesn to nullptr and maxTokens to 0  
		 *
		 */
		
		char** Tokenize(std::string *);
		/** @brief Tokenize the string argument
		 *
		 *  Tokenize the first word in the string and push it onto
		 *	a vector. Then loops until the string ends. Then space
		 *	was allocated using NEW for each token in the vector.
		 *	The token was assigned each element in the vector of char*.
		 *  The pointer to the array of tokens was returned.
		 *
		 *  @param a pointer to the user input
		 *	@return a pointer to an array of tokens
		 */	
		
		int GetMaxTokens();
		/** @brief return an integer
		 *
		 *	Returns the number of tokens that was counted while the
		 *	string was tokenized.
		 *
		 *  @return the number of tokens
		 */		

		void FreeMemory();
		/** @brief Deallocate memory
		 *
		 *  Free the memory due to using NEW to prevent memory leaks.
		 */
};

#endif

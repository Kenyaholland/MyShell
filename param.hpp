/** @file param.hpp
 *  @brief This Param object does error handling and assigns tokenized command input to variables
 *
 *  This object reads in parsed command from the Parse object 
 *  and stores the tokens into their respective slot. This 
 *  object then prints an output of the class variables assignments.
 *  Param also checks for keyword exit and invalid inputs.
 *
 *  @author Thati Vang (tv20)
 *  @author Kenya Holland (kmh99)
 */

#ifndef PARAM_HPP
#define PARAM_HPP

/* Inlcudes */
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#define MAXARGS 32

class Param{
	private:
		char *inputRedirect; /* file name or NULL */
		char *outputRedirect; /* file name or NULL */
		int argumentCount; /* number of tokens in argument vector */
		char *argumentVector[MAXARGS]; /* array of strings */
		
		/* @brief assigns tokens from passed in vector to certain variables
 		*
 		* This function uses an if-else srtucture to do error
		* handling as well as to ensure that each word gets
		* assigned to the correct class variable.
		* This function cycles through each word in vector
		* input command. It ensures that if there is a < or >
		* at the beginning of a word, then it will store
		* the word as inputRedirect or outputRedirect, depending
		* on which way the arrow faces. It also ensures that the
		* program will terminate if there is a space after th arrow.
		* All other words get stored in argumentVector and the		 
		* argument count is increased with each word stored in vector.
		*
 	 	* @param inputCommand the parsed version of user command input initillay read in my Parse object.
 	 	* @return void
 		*/
		void ParseCommandLine(std::vector<std::string>);
	public:
		/* @brief constructor of param object
                *
                * Initializes class variables to NULL and passes in parameter vector to ParseCommandLine.
                *
                * @param inputCommand the parsed version of user command input initillay read in my Parse object.
                */
		Param(std::vector<std::string>);
		
		/* @brief prints summary of class variables
                 * 
		 * This functions makes a visual output of all the class variables and what their
		 * value was assigned to. 
                 *
                 * @return void
                 */
		void PrintParams();
		
		/* @brief Does error checking and checks for keyword exit to terminate program
		 *
		 * This function checks for keyword exit in any part of the command line entered.
		 * It also ensures that the second argument from the command is a number. 
                 * 
		 * @return void
		 */
		void CheckArguments();
};

#endif

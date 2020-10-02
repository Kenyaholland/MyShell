/** @file param.hpp
 *  @brief This Param object does error handling and assigns tokenized command input to variables
 *
 *  This object reads in a vector<string> which include words that have been parsed from the command line, 
 *  and stores them into their respective slot. This object can print the class variables assignments
 *  when the program is run in -Debug mode. Param also checks for keyword exit and invalid inputs.
 *
 *  @author Thati Vang (tv20)
 *  @author Kenya Holland (kmh99)
 */

#ifndef PARAM_HPP
#define PARAM_HPP

/*  Inlcudes  */
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#define MAXARGS 32

class Param{
	private:
		/*  file name or NULL  */
		char *inputRedirect;
		char *outputRedirect;

		/*  number of tokens in argument vector */
		int argumentCount;

		/*  array of strings  */
		char *argumentVector[MAXARGS];
		

	public:
	
		/** @brief Constructor
		 *  
		 *  Initializes input and output redirect to to NULL.
		 *  Calls ParseCommandLine() and passes in the string vector.
		 *
		 *  @param Vector of parsed strings from user input
		 */
		Param();
		
		/** @brief prints summary of class variables
		 *
		 *  This functions makes a visual output of all the class variables
		 *  and what their value was assigned to. It will print NULL in place
		 *  of inputRedirect or outputRedirect if the user did not specify
		 *  an input or output redirect. Otherwise, the function will print
		 *  what the user specified as the input or output redirect. 
		 *
		 *  @return void
		 */
		void PrintParams();
		
		/** @brief checks for exit and error handling
		 *
		 *  This function checks for keyword exit in any part of the command line entered,
		 *  and will terminate when found.
		 *  It also ensures that the second argument from the command is a number,
		 *  otherwise the program will terminate.
		 *
		 *  @return void
		 */
		void CheckExit();
		bool CheckArgumentTwo();
		/** @brief Assigns tokens from a vector to respective variables.
		 *
		 *  This function uses an if-else structure to do error
		 *  handling as well as to ensure that each word gets
		 *  assigned to the correct class variable.
		 *  This function cycles through each word in vector
		 *  input command. It ensures that if there is a < or >
		 *  at the beginning of a word, then it will store
		 *  the word as inputRedirect or outputRedirect, depending
		 *  on which way the arrow faces. It also ensures that the
		 *  program will terminate if there is only a single < or >.
		 *  All other words get stored in argumentVector[] and the		 
		 *  argument count is increased with each word stored.
		 *
		 *  @param inputCommand Vector of parsed strings from user input.
		 *  @return void
		 */
		bool Initialize(char**,int);
		const char* GetNumProcesses();
		const char* GetFileName();
		const char* GetRange();
		const char* GetInputRedirect();
		const char* GetOutputRedirect();
		void FreeMemory();
};

#endif

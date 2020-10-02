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
		char *inputRedirect;
		char *outputRedirect;
		int argumentCount;
		char *argumentVector[MAXARGS];
	public:
		Param();
		/** @brief Constructor
		 *  
		 *  Initializes input and output redirect to to NULL
		 *  and argumentCount to 0
		 *
		 */
		
		bool Initialize(char**,int);		
		/** @brief Assigns tokens to respective variables.
		 *
		 *  This function uses an if-else structure to do error
		 *  handling as well as to ensure that each word gets
		 *  assigned to the correct class variable.
		 *  This function cycles through each word in char* token[]
		 *  and ensures that if there is a < or >
		 *  at the beginning of a word, then it will store
		 *  the word as inputRedirect or outputRedirect.
		 *  It also ensures that the program will loop to user 
		 *  input if there is only a single < or >.
		 *  All other words get stored in argumentVector[] and		 
		 *  argumentCount is increased with each word stored.
		 *  The return value is a bool that will let the program
		 *  know whether it should start from the user input.
		 *
		 *  @param char** tokens and int maxTokens
		 *  @return bool
		 */
		
		void PrintParams();
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
		
		void CheckExit();
		/** @brief checks for exit and error handling
		 *
		 *  This function checks for keyword exit in any part of the 
		 *  command line entered, and will terminate when found.
		 *
		 *  @return void
		 */
		
		bool CheckArgumentTwo();
		/** @brief checks the argumentVector
		 *
		 *  Checks argumentVector[1] and make sure it is a number.
		 *  Also checks to make sure there are more than two parameters
		 *  entered by the user. If less than 2 user inputs, returns fasle
		 *  and loops back to user input. If it is not a number, program
		 *  will terminate. Otherwise, return true.
		 *
		 *  @return bool
		 */
		
		char* GetNumProcesses();
		char* GetFileName();
		char* GetRange();
		char* GetInputRedirect();
		char* GetOutputRedirect();
		/** @brief getters
		 *
		 *	Getters that return the appropriate variables
		 *
		 *  @return char*
		 */
};

#endif

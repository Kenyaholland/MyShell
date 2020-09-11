/** @file param.cpp
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

#include "param.hpp"

/* @brief constructor of param object
 *
 * Initializes class variables to NULL and passes in parameter vector to ParseCommandLine.
 *
 * @param inputCommand the parsed version of user command input initillay read in my Parse object.
 */
Param::Param(std::vector<std::string> inputCommand){

	//intial value is NULL
	this->inputRedirect = NULL;
	this->outputRedirect = NULL;

	//calls private function to intialize all private variables
	ParseCommandLine(inputCommand);
	
}

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
void Param::ParseCommandLine(std::vector<std::string> inputCommand){

	int numOfArgs = 0;
	
	/* cycles through each word in inputCommand */
	for(unsigned int i = 0; i < inputCommand.size(); i++){

		/* checks for input file symbol and verifies there is no space after the arrow */
		if(inputCommand.at(i).at(0) == '<' && inputCommand.at(i).size() == 1){
			std::cout << "ERROR: specify input name" << std::endl << "PROGRAM TERMINATED" << std::endl;
			exit(1);
		}
		/*checks for output file symbol and verifies there is no space after the arrow */
		else if(inputCommand.at(i).at(0) == '>' && inputCommand.at(i).size() == 1){
			std::cout << "ERROR: specify output name" << std::endl << "PROGRAM TERMINATED" << std::endl;
			exit(1);
		}
		/* checks for input file symbol and assigns word fallowing symbol to inputRedirect */
		else if(inputCommand.at(i).at(0) == '<' && inputCommand.at(i).size() > 1){
			this->inputRedirect = &inputCommand.at(i).at(1);
		}
		/* checks for output file symbol and assigns word fallowing arrow to outputRedirect */
		else if(inputCommand.at(i).at(0) == '>' && inputCommand.at(i).size() > 1){
			this->outputRedirect = &inputCommand.at(i).at(1);
		}
		/* assigns all other words to arguemntVector and increases number for argumentCount */
		else{
			this->argumentVector[numOfArgs] = &inputCommand.at(i).at(0);
			numOfArgs++;
		}
	}
	
	this->argumentCount = numOfArgs;
}

/* @brief prints summary of class variables
 *
 * This functions makes a visual output of all the class variables and what their
 * value was assigned to.
 *
 * @return void
 */
void Param::PrintParams(){

	std::cout << "InputRedirect: [" << ((inputRedirect != NULL) ? inputRedirect : "NULL") << "]" << std::endl 
		<< "OutputRedirect: [" << ((outputRedirect != NULL) ? outputRedirect : "NULL") << "]" << std::endl 
		<< "ArgumentCount: [" << argumentCount << "]" << std::endl;
	
	for (int i = 0; i < argumentCount; i++){
		std::cout << "ArgumentVector[" << i << "]: [" <<
		argumentVector[i] << "]" << std::endl;
	}
}

/* @brief Does error checking and checks for keyword exit to terminate program
 *
 * This function checks for keyword exit in any part of the command line entered.
 * It also ensures that the second argument from the command is a number.
 *
 * @return void
 */
void Param::CheckArguments(){

	/* string to search for */
	std::string toExit = "exit";
	/*string to comapre to */
	std::string toCompare;

	/* cycles through argumentVector to compare strings, looks for exit string */
	for(int i = 0; i < argumentCount; i++){
		toCompare = this->argumentVector[i];
	
		if(toCompare == toExit){
			std::cout << "PROGRAM TERMINATED" << std::endl;
			exit(0);
		}
	}

	/* if assignment returns a zero, then the input for the second argument is not a number and is invalid */
	int argumentTwo = atoi(this->argumentVector[1]);
	
	if(argumentTwo == 0){
		std::cout << "ERROR: second argument must be integer" << std::endl << "PROGRAM TERMINATED" << std::endl;
		exit(1);
	}
}

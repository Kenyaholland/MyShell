/* @file myshell.cpp
 * @brief This file contains the shells main function.
 *
 * This class reads in a user command and creates a Parse object to parse the users command
 * Then a Param object is made to error check the parsed command. This class then checks for 
 * keyword Debug to run a  print statement through the  Params object.
 *
 * @author Kenya Holland (kmh99)
 * @authot Thati Vang (tv20)
 */

/* Includes */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "parse.hpp"
#include "param.hpp"

int main(int argc, char *argv[]){
	/* local variables */
	std::string command;
	std::vector<std::string> parsedCommand;

	/* read in user command input */
	std::cout << "$$$ ";
	std::getline(std::cin, command);

	/* create Psrse object to tokenize command input */
	Parse toParse;
	parsedCommand = toParse.Parsing(command); 

	/* create Param object for error checking tokenized command input */
	Param param(parsedCommand);
	param.CheckArguments();

	/*check for Debug keyword to print the Debug version of Param object */
	std::string debug = "-Debug";
	std::string toCompare;
	
	for(int i = 0; i < argc; i++){
		toCompare = *(argv+i);	
		
		if(toCompare == debug){
			param.PrintParams();
			break;
		}
	}
}

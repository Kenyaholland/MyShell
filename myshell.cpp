/** @file myshell.cpp
 *  @brief This file contains the shells main function.
 *
 *  This class reads in a user command and creates a Parse object to parse the user's command.
 *  A vector is returned with all the parsed words and passed into a Param object.
 *  The Param object initializes its variables and performs error checking, terminating if an
 *  error is found in the user's input. The Param object also checks for exit from user input.
 *  myshell then checks for keyword -Debug and, if found, calls param.PrintParams() to print its
 *  contents.
 *
 *  @author Kenya Holland (kmh99)
 *  @author Thati Vang (tv20)
 */

/*  Includes  */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "parse.hpp"
#include "param.hpp"

int main(int argc, char *argv[]){
	/*  loops until exit entered by user or error in command line  */
	while(1){
		/*  local variables  */
		std::string command;
		std::vector<std::string> parsedCommand;

		/*  read in user command input  */
		std::cout << "$$$ ";
		std::getline(std::cin, command);

		/*  create Parse object to tokenize command input  */
		Parse toParse;
		parsedCommand = toParse.Parsing(command); 

		/*  create Param object and intialized variables with tokens
		 *  check for errors within the tokenized command input 
		 */
		Param param(parsedCommand);
		param.CheckArguments();

		/*  check for Debug keyword to print the Debug version of Param object  */
		std::string debug = "-Debug";
		std::string toCompare;
		
		for(int i = 0; i < argc; i++){
			toCompare = *(argv+i);	
			
			if(toCompare == debug){
				param.PrintParams();
				break;
			}
		}
		
		int processes = atoi(param.getNumProcesses());
		
		for(int i = 0; i < processes; i++){
			int pid = fork();
			if(pid == 0){
				std::string tempSegment = std::to_string(i);
				const char* segment = tempSegment.c_str();
				execlp(param.getFileName(),param.getFileName(),param.getNumProcesses(),segment,param.getInputRedirect(),NULL);
			}
			/*
			else{
				wait(NULL);
			}
			*/
		}
		wait(NULL);
	}
}

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
	bool proceed = true;
	/*  loops until exit entered by user or error in command line  */
	while(proceed == true){
		/*  local variables  */
		
		std::string command;
		Parse toParse;
		Param param;
		/*  read in user command input  */
		do{
			std::cout << "\n$$$ ";
			std::getline(std::cin, command);

			if(!command.empty()){
				std::string *commandPtr = &command;		

				/*  create Parse object to tokenize command input  */
				char** tokenizedCommand = toParse.Tokenize(commandPtr); 

				/*  create Param object and intialized variables with tokens
				 *  check for errors within the tokenized command input 
				 */
				proceed = param.Initialize(tokenizedCommand, toParse.GetMaxTokens());
				param.CheckExit();
				
				if(proceed == true){
					proceed = param.CheckArgumentTwo();
				}
			}
		}while(command.empty());
		
		if(proceed == true){
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
			
			int processes = atoi(param.GetNumProcesses());
			int failed = 0;
			
			for(int i = 0; i < processes; i++){
				int pid = fork();
				if(pid == 0){
					if(param.GetOutputRedirect() != nullptr){
						std::string outputName(param.GetOutputRedirect());
						std::string txt = ".txt";
						std::string num = std::to_string(i);
						outputName.append(num);
						outputName.append(txt);
						outputName.erase(0,1);
						char* fileName = const_cast<char*>(outputName.c_str());
						freopen(fileName,"w",stdout);
					}
					
					std::string tempSegment = std::to_string(i);
					const char* segment = tempSegment.c_str();
					
					if(param.GetInputRedirect() == nullptr){
						failed = execlp(param.GetFileName(),param.GetFileName(),
							param.GetNumProcesses(),segment,
							param.GetRange(),NULL);
						
						if(failed == -1){
							std::cout << "ERROR: file not found" << std::endl;
							exit(1);
						}
					}
					else{
						std::string tempInput(param.GetInputRedirect());
						tempInput.erase(0,1);
						const char* inputRange = const_cast<const char*>(tempInput.c_str());
						
						failed = execlp(param.GetFileName(),param.GetFileName(),
							param.GetNumProcesses(),segment,
							inputRange,NULL);
						
						if(failed == -1){
							std::cout << "ERROR: file not found" << std::endl;
							exit(1);
						}
					}
					
				}
				else{
					int status;
					wait(&status);
					if(status == 256){
						std::cout << "PROGRAM TERMINATED" << std::endl;
						exit(1);
					}

				}
			}	
		}
		//param.FreeMemory();
		//toParse.FreeMemory();
		proceed = true;	
	}
}

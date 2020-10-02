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
	//a bool that controls the loop until user exits or error
	bool proceed = true;
	
	while(proceed == true){
		std::string command;
		Parse toParse;
		Param param;

		//loops if string is empty
		do{
			std::cout << "\n$$$ ";
			std::getline(std::cin, command);

			//will not execute if there was no user input
			if(!command.empty()){
				//get the address of user input
				std::string *commandPtr = &command;		
				
				//create a char** to hold the address of the tokens when parsed
				char** tokenizedCommand = toParse.Tokenize(commandPtr); 

				//initialized the tokens to an param object
				//returns false if there were errors with < and >
				//and will loop back to user input
				proceed = param.Initialize(tokenizedCommand, toParse.GetMaxTokens());
				
				//if user entered "exit", program will terminate
				param.CheckExit();
				
				//if there were no errors with < or >, then argument two is checked
				//will loop back to user input if there were less than 2 user inputs
				//or if argumentVector[1] in the param object was not a number
				if(proceed == true){
					proceed = param.CheckArgumentTwo();
				}
			}
		}while(command.empty());
		
		//skips if errors were found in previous function
		if(proceed == true){
			//checks for "-Debug" and if ture, will print parameter values
			std::string debug = "-Debug";
			std::string toCompare;
			
			for(int i = 0; i < argc; i++){
				toCompare = *(argv+i);	
				
				if(toCompare == debug){
					param.PrintParams();
					break;
				}
			}
			
			//get the number of processes and convert it to an int
			int processes = atoi(param.GetNumProcesses());
			
			//controls the exit status of a child process
			int failed = 0;
			
			//loops and create x amount of processes specified by users
			for(int i = 0; i < processes; i++){
				int pid = fork();
				
				//if current process is the child
				if(pid == 0){
					//converts the int i to a char* to use as the index
					std::string indexStr = std::to_string(i);					
					char *indexChar = const_cast<char*>(indexStr.c_str());
					
					//holds the value of the range to be passed in exec()
					char *valueChar = nullptr;
					
					//to hold the value from input redirect
					int valueInt;
					
					//if user specified an input redirect with <
					if(param.GetInputRedirect() != nullptr){
						//return the file name from param and append
						//".txt" to the end of the file,
						//also delete the "<" at the front of the name
						std::string inputFileName(param.GetInputRedirect());
						std::string txt = ".txt";
						inputFileName.erase(0,1);
						inputFileName.append(txt);

						//open the file
						FILE *fileIn = freopen(inputFileName.c_str(),"r",stdin);
						
						//if file failed, exit
						if(fileIn == NULL){
							std::cout << "ERROR: input file not found" << std::endl;
							exit(1);
						}
						
						//read in the value in the file
						std::cin >> valueInt;
						fclose(fileIn);
					}
					
					//convert the read in value to a char*
					std::string valueStr = std::to_string(valueInt);
					valueChar = const_cast<char*>(valueStr.c_str());
					
					//if user did not specify an input redirect,
					//then a number entered by the user will be useds
					if(param.GetInputRedirect() == nullptr){
						valueChar = const_cast<char*>(param.GetRange());
					}
					
					//initialized char* args[] to be passed into execvp()
					//values initialized were return from param object or
					//from values calculated above
					char* args[] = {
						param.GetFileName(),
						param.GetNumProcesses(),
						indexChar,
						valueChar,
						NULL
					};
					
					//if an output redirect was specified
					if(param.GetOutputRedirect() != nullptr){
						//return the file name from param object
						std::string outputFileName(param.GetOutputRedirect());
						std::string txt = ".txt";
						
						//append the index and ".txt" and delete ">"
						outputFileName.append(indexStr);
						outputFileName.append(txt);
						outputFileName.erase(0,1);
						
						//create and open the file
						FILE *fileOut = freopen(outputFileName.c_str(),"w",stdout);
						
						//exit if error occurred
						if(fileOut == NULL){
							std::cout << "ERROR: cannot create file" << std::endl;
							exit(1);
						}
						
						//fclose(fileOut);
					}
					
					//execute the program
					failed = execvp(args[0], args);
					
					//if failed, then will exit(1) which will led the
					//parent know to terminate the program
					if(failed == -1){
						exit(1);
					}
				}
			}
			//wait for how many times the program created a new processes
			for(int i = 0; i < processes; i++){
				//returns the exit status of the child
				int status;
				wait(&status);
				
				//if status was an error, terminate the program
				if(status == 256){
					std::cout << "ERROR: file not found" << std::endl;
					std::cout << "PROGRAM TERMINATED" << std::endl;
					exit(1);
				}
			
			}
		}
		//toParse.FreeMemory();
		
		//set to true to loop until error or user exit
		proceed = true;	
	}
}

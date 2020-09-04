#ifndef PARAM_HPP
#define PARAM_HPP
#define MAXARGS 32
#include <string>
#include <vector>
#include <iostream>

class Param{
	private:
		char *inputRedirect; /* file name or NULL */
		char *outputRedirect; /* file name or NULL */
		int argumentCount; /* number of tokens in argument vector */
		char *argumentVector[MAXARGS]; /* array of strings */
	public:
		Param(std::vector<std::string>);
		void PrintParams();
		void ParseCommandLine(std::vector<std::string>);
};

#endif

#ifndef PARAM_HPP
#define PARAM_HPP

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
		void ParseCommandLine(std::vector<std::string>);
	public:
		Param(std::vector<std::string>);
		void PrintParams();
		void CheckArguments();
};

#endif

#ifndef PARSE_HPP
#define PARSE_HPP

#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>

class Parse{
	private:
		//vector that stores the parsed commands
		std::vector<std::string> parsed; 
	public:
		//returns the vector to main()
		std::vector<std::string> Parsing(std::string); 
};

#endif

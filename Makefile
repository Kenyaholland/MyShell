CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJECTS = parse.o param.o

myshell: myshell.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

in: $(eval SHELL:=/bin/bash)
	@touch input.txt
	@echo "100" >> input.txt

clean:
	$(RM) *.o *.txt myshell
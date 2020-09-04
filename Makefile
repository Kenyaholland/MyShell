CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJECTS = param.o

myshell: myshell.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) *.o myshell
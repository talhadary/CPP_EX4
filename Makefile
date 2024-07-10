# Compiler
CXX = clang++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -O2 -I$(SFML_INCLUDE)

# Header files
HEADERS = node.hpp tree.hpp iterators.hpp doctest.h gui.hpp

# SFML paths
SFML_INCLUDE = /usr/include
SFML_LIB = /usr/lib/x86_64-linux-gnu

LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# default target
all: demo test

# run the executable
run: demo
	./demo

# Link object files to create the executable
demo: Demo.o
	$(CXX) $(CXXFLAGS) -o $@ $^ -L$(SFML_LIB) $(LIBS)

# Link object files to create the test
test: test.o TestCounter.o
	$(CXX) $(CXXFLAGS) -o $@ $^ -L$(SFML_LIB) $(LIBS)

# Compile source files into object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f *.o demo test

# Phony targets
.PHONY: all clean demo run test

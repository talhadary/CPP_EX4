# Compiler
CXX = clang++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -O2

# Header files
HEADERS = node.hpp tree.hpp iterators.hpp doctest.h

# default target
all: demo test

# run the executable
run: demo
	./demo

# Link object files to create the executable
demo: Demo.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Link object files to create the test
test: test.o TestCounter.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f Demo.o demo test.o TestCounter.o test

# Phony targets
.PHONY: all clean demo run

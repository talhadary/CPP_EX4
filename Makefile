# Compiler
CXX = clang++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -O2

# Executable name
EXEC = demo

# Source files
SRCS = Demo.cpp tree.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files
HEADERS = node.hpp tree.hpp iterators.hpp

# run the executable
run: $(EXEC)
	./$(EXEC)

# make the executable
demo: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(EXEC)

# Phony targets
.PHONY: all clean demo run

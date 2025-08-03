# Makefile for Project Euler Solutions
# Located in the project root: ~/developer/project_euler

# Compiler and flags
CXX = g++
CXXFLAGS = -g -Wall -Wextra -std=c++26

# Directory Definitions
SRC_DIR = src
LIB_DIR = lib
OUT_DIR = out

# Problem Selection
# Set PROBLEM_NUM when calling make, e.g. make PROBLEM_NUM=001
# Default to 001 if not specified, or leave blank to require it
PROBLEM_NUM ?= 001

PROBLEM_SRC = $(SRC_DIR)/problem$(PROBLEM_NUM).cpp
PROBLEM_OBJ = $(OUT_DIR)/problem$(PROBLEM_NUM).o
PROBLEM_TARGET = $(OUT_DIR)/problem$(PROBLEM_NUM)

# Shared Library Object File
LIB_OBJ = $(LIB_DIR)/tools.o

# Include paths
# Tell compiler where to find header (e. g. tools.h)
INCLUDE_PATHS = -I$(LIB_DIR)

# All Object Files for Linking
ALL_OBJS = $(PROBLEM_OBJ) $(LIB_OBJ)

# Main Build Target
# The 'all' target builds the selected problem's executable
all: $(PROBLEM_TARGET)

# Rule to link the final executable
$(PROBLEM_TARGET): $(ALL_OBJS)
	$(CXX) $(CXXFLAGS) $(ALL_OBJS) -o $@

# Rule to compile the problem-specific source file into an object file
# The object file goes to OUT_DIR
$(PROBLEM_OBJ): $(PROBLEM_SRC) $(LIB_DIR)/tools.h
	$(CXX) $(CXXFLAGS) $(INCLUDE_PATHS) -c $< -o $@

# Rule to compile the shared library source file into an object file
# The object file goes into LIB_DIR
$(LIB_OBJ): $(LIB_DIR)/tools.cpp $(LIB_DIR)/tools.h
	$(CXX) $(CXXFLAGS) $(INCLUDE_PATHS) -c $< -o $@

# Run Target
# Runs the compiled executable for the selected problem
run: $(PROBLEM_TARGET)
	./$(PROBLEM_TARGET)

# Clean Target
# Removes all compiled executables and object files
clean:
	rm -f $(OUT_DIR)/*.o $(LIB_DIR)/*.o $(OUT_DIR)/*


# New Problem Helper Target
# Creaes a new problem directory and basic source file
# Usage: make new_problem PROBLEM_NUM=xxx
new_problem:
	@echo "Creating new problem $(PROBLEM_NUM)..."
	@mkdir -p $(SRC_DIR)
	@echo '// problem$(PROBLEM_NUM).cpp' > $(SRC_DIR)/problem$(PROBLEM_NUM).cpp
	@echo '#include <iostream>' >> $(SRC_DIR)/problem$(PROBLEM_NUM).cpp
	@echo '#include <tools.h>' >> $(SRC_DIR)/problem$(PROBLEM_NUM).cpp
	@echo '' >> $(SRC_DIR)/problem$(PROBLEM_NUM).cpp
	@echo 'int main() {' >> $(SRC_DIR)/problem$(PROBLEM_NUM).cpp
	@echo '    std::cout << "Solving Project Euler Problem $(PROBLEM_NUM)" << std::endl;' >> $(SRC_DIR)/problem$(PROBLEM_NUM).cpp
	@echo '' >> $(SRC_DIR)/problem$(PROBLEM_NUM).cpp
	@echo '    return 0;' >> $(SRC_DIR)/problem$(PROBLEM_NUM).cpp
	@echo '}' >> $(SRC_DIR)/problem$(PROBLEM_NUM).cpp
	@echo "Created $(SRC_DIR)/problem$(PROBLEM_NUM).cpp"


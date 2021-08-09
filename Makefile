CXX			= g++
CXXFLAGS	= -std=c++17 -Wall -Wextra -O2
LNKFLAGS	= -std=c++17 -O2

OBJ_DIR		= ./build
I_DIR		= ./include
BIN_DIR		= ./bin

all: test

test: test/test.cc ./include/pdmatrix.hh dir_guard 
	$(CXX) -c $(CXXFLAGS) -I$(I_DIR) -o $(OBJ_DIR)/$@.o $<
	$(CXX) -o $(BIN_DIR)/$@ $(OBJ_DIR)/$@.o $(LNKFLAGS)

dir_guard:
	mkdir -p $(OBJ_DIR) $(BIN_DIR)

clean_bin:
	rm -rv $(BIN_DIR)

clean_obj:
	rm -rv $(OBJ_DIR)

clean: clean_bin clean_obj

.PHONY: clean

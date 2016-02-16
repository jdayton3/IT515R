all: solver grid2pgm

CXX ?= g++
CXXFLAGS += -Wall -Wextra -std=c++14

solver: Project.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

grid2pgm: Grid2PGM.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: clean

clean:
	$(RM) solver
	$(RM) grid2pgm

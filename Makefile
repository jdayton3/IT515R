CXX ?= g++
CXXFLAGS += -Wall -Wextra -std=c++14

Project: Project.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: clean

clean:
	$(RM) Project

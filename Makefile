CXX ?= g++
CXXFLAGS += -Wall -Wextra -std=c++14

/fslhome/jdayton3/IT515R/Project: /fslhome/jdayton3/IT515R/Project.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: clean

clean:
	$(RM) /fslhome/jdayton3/IT515R/Project

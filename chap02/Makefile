
RM = rm -f
CXX = g++
CXXFLAGS = -Wall -g -std=c++11 #-DUSE_DENSE_GRAPH
INCLUDES = -I../include -I../test
LDFLAGS = -lgraph_algo
LDPATH = -L../src -L../lib

SOURCES = $(shell ls *.cpp)
PROGS = $(SOURCES:%.cpp=%)

all: $(PROGS)
	@echo "PROGS = $(PROGS)" 

clean:
	$(RM) $(PROGS)

%: %.cpp
	$(CXX) -o $@ $(CXXFLAGS) $(INCLUDES) $^ $(LDFLAGS) $(LDPATH)

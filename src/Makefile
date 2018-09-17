
RM = rm -f
AR = ar rcs
CXX = g++
CXXFLAGS = -Wall -g -std=c++11 #-DNDEBUG 
INCLUDES = -I../include -I../include/json11
LDFLAGS = 
LDPATH =
VPATH = 

SOURCES = $(shell ls *.cpp */*.cpp)
OBJECTS = $(SOURCES:%.cpp=%.o)
STATICLIB = libgraph_algo.a

all: $(STATICLIB)
	@echo "STATICLIB = $(STATICLIB)" 

.PHONY: clean
clean:
	$(RM) $(STATICLIB) $(OBJECTS)

$(OBJECTS): %.o: %.cpp
	$(CXX) -o $@ -c $(CXXFLAGS) $(INCLUDES) $<

$(STATICLIB): $(OBJECTS)
	$(AR) $(STATICLIB) $(OBJECTS)


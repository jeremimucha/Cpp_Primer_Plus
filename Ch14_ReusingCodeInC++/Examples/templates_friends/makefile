CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

SRC = $(wildcard *.cpp)
BINS = $(patsubst %.cpp, %.exe, $(SRC))
OBJS = 


all: $(BINS)


%.exe: %.cpp
	$(CXX) -o $@ $< $(CFLAGS)


clean:
	rm -f $(BINS) $(OBJS)


.PHONY: all

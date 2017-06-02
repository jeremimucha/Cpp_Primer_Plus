CFLAGS = -O2 -Wall -Wextra -std=c++11
CXX = g++

SRC = $(wildcard *.cpp)
BINS = $(patsubst %.cpp, %.exe, $(SRC))
DEPS = exc_mean.h


all : $(BINS)


%.exe: %.cpp $(DEPS)
	$(CXX) -o $@ $^ $(CFLAGS)


clean:
	rm -f $(BINS)

.PHONY: all

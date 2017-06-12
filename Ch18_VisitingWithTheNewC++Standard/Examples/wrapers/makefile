CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

SRC = $(wildcard *.cpp)
BINS = $(patsubst %.cpp, %.exe, $(SRC))
DEPS = somedefs.h


all : $(BINS)


%.exe: %.cpp $(DEPS)
	$(CXX) -o $@ $^ $(CFLAGS)


clean:
	rm -f $(BINS)

.PHONY: all

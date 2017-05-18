CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = sayings1.exe
OBJS = string1.o

all: $(BINS)

string1.o: string1.cpp string1.h
	$(CXX) -c -o $@ $< $(CFLAGS)

sayings1.exe: sayings1.cpp $(OBJS)
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

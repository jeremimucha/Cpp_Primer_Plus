CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = sayings1.exe
OBJS = string2.o

all: $(BINS)

string2.o: string2.cpp string2.h
	$(CXX) -c -o $@ $< $(CFLAGS)

sayings2.exe: sayings2.cpp $(OBJS)
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

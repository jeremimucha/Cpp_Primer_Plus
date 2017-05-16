CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = stone.exe
OBJS = stonewt.o

all: $(BINS)

stonewt.o: stonewt.cpp stonewt.h
	$(CXX) -c -o $@ $< $(CFLAGS)

stone.exe: stone.cpp $(OBJS)
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

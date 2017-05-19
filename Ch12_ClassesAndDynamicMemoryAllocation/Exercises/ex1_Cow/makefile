CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = barn.exe
OBJS = cow.o

all: $(BINS)

cow.o: cow.cpp cow.h
	$(CXX) -c -o $@ $< $(CFLAGS)

barn.exe: barn.cpp $(OBJS)
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

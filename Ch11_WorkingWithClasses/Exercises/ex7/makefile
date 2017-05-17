CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = ex7.exe
OBJS = complex0.o

all: $(BINS)

complex0.o: complex0.cpp complex0.h
	$(CXX) -c -o $@ $< $(CFLAGS)

ex7.exe: ex7.cpp $(OBJS)
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

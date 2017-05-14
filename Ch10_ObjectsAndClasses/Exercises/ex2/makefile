CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = ex2.exe
OBJS = person.o

all: $(BINS)

person.o: person.cpp person.h
	$(CXX) -c -o $@ $< $(CFLAGS)

ex2.exe: ex2.cpp person.o
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

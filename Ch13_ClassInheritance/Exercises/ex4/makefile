CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = usebop.exe 
OBJS = bop.o

all: $(BINS)

bop.o: bop.cpp bop.h
	$(CXX) -c -o $@ $< $(CFLAGS)


usebop.exe: usebop.cpp bop.o
	$(CXX) -o $@ $^ $(CFLAGS)


clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

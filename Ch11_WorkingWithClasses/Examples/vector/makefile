CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = randwalk.exe
OBJS = vect.o

all: $(BINS)

vect.o: vect.cpp vect.h
	$(CXX) -c -o $@ $< $(CFLAGS)

randwalk.exe: randwalk.cpp $(OBJS)
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++


BINS = persontest.exe
OBJ = personmi.o

all: $(BINS)

personmi.o: personmi.cpp personmi.h
	$(CXX) -c -o $@ $< $(CFLAGS)

persontest.exe: persontest.cpp personmi.o
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJ)

.PHONY: all, clean

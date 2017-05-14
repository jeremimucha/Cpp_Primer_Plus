CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = ex1.exe
OBJS = account.o

all: $(BINS)

account.o: account.cpp account.h
	$(CXX) -c -o $@ $< $(CFLAGS)

ex1.exe: ex1.cpp account.o
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

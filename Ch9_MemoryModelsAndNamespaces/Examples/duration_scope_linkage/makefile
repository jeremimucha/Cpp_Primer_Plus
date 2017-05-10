CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = external.exe
OBJS = support.o

all: $(BINS)

support.o: support.cpp+
	$(CXX) -c -o $@ $< $(CFLAGS)

external.exe: external.cpp support.o
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
		rm -f $(BINS) $(OBJS)

.PHONY: all

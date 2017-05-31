CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = use_tv.exe
OBJS = tv.o


all: $(BINS)


tv.o: tv.cpp tv.h
	$(CXX) -c -o $@ $< $(CFLAGS)

use_tv.exe: use_tv.cpp tv.o
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

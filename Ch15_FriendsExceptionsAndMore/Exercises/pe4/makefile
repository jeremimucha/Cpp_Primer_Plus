CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = use_sales.exe
OBJS = sales.o


all: $(BINS)


sales.o: sales.cpp sales.h
	$(CXX) -c -o $@ $< $(CFLAGS)

use_sales.exe: use_sales.cpp sales.o
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

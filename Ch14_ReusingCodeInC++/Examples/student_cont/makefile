CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = use_stuc.exe
OBJS = studentc.o


all: $(BINS)


studentc.o: studentc.cpp studentc.h
	$(CXX) -c -o $@ $< $(CFLAGS)

use_stuc.exe: use_stuc.cpp studentc.o
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

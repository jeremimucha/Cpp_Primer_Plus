CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = twod.exe

all: $(BINS)

twod.exe: twod.cpp arraytp.h
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

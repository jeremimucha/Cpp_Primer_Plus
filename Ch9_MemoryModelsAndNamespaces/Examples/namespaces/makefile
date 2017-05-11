CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = usenmsp.exe
OBJS = namesp.o

all: $(BINS)

namesp.o: namesp.cpp namesp.h
	$(CXX) -c -o $@ $< $(CFLAGS)

usenmsp.exe: usenmsp.cpp namesp.o
	$(CXX) -o $@ $^ $(CFLAGS)


clean:
		rm -f $(BINS) $(OBJS)

.PHONY: all

CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = useclassic.exe
OBJS = classic.o

all: $(BINS)

classic.o: classic.cpp classic.h
	$(CXX) -c -o $@ $< $(CFLAGS)


useclassic.exe: useclassic.cpp classic.o
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

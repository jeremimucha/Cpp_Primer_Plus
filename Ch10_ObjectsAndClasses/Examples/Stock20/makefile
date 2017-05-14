CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = usestok2.exe
OBJS = stock20.o

all: $(BINS)

stock20.o: stock20.cpp stock20.h
	$(CXX) -c -o $@ $< $(CFLAGS)

usestok2.exe: usestok2.cpp stock20.o
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

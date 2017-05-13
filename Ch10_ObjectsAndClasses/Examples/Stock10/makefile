CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = usestok1.exe
SRC  = stock10.cpp
OBJS = stock10.o

all: $(BINS)

stock10.o: stock10.cpp stock10.h
	$(CXX) -c -o $@ $< $(CFLAGS)

$(BINS): $(OBJS) usestok1.cpp
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f  $(BINS) $(OBJS)

.PHONY: all

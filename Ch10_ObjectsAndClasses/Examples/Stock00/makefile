CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = usestck0.exe
SRC  = stock00.cpp
OBJS = stock00.o

all: $(BINS)

stock00.o: stock00.cpp stock00.h
	$(CXX) -c -o $@ $< $(CFLAGS)

$(BINS): $(OBJS) usestck0.cpp
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f  $(BINS) $(OBJS)

.PHONY: all

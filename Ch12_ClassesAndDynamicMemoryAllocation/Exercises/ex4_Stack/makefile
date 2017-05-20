CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = stacker.exe
OBJS = stack.o

all: $(BINS)

stack.o: stack.cpp stack.h
	$(CXX) -c -o $@ $< $(CFLAGS)

stacker.exe: stacker.cpp $(OBJS)
	$(CXX) -o $@ $^ $(CFLAGS)


clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

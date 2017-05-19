CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = bank.exe
OBJS = queue.o

all: $(BINS)

queue.o: queue.cpp queue.h
	$(CXX) -c -o $@ $< $(CFLAGS)

bank.exe: bank.cpp $(OBJS)
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

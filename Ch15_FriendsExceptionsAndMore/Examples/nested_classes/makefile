CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = nested.exe


all: $(BINS)

nested.exe: nested.cpp queuetp.h
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

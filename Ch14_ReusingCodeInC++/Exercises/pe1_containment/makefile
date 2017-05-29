CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = usewine.exe
OBJS = winec.o


all: $(BINS)


winec.o: winec.cpp winec.h
	$(CXX) -c -o $@ $< $(CFLAGS)

usewine.exe: usewine.cpp winec.o
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

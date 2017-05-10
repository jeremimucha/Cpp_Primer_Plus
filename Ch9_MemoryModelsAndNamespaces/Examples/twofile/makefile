CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = twofile1.exe
OBJS = twofile2.o

all: $(BINS)

twofile2.o: twofile2.cpp
	$(CXX) -c -o $@ $< $(CFLAGS)

twofile1.exe: twofile1.cpp twofile2.o
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
		rm -f $(BINS) $(OBJS)

.PHONY: all

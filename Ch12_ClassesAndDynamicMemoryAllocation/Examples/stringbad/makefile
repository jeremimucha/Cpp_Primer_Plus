CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = vegnews.exe
OBJS = stringbad.o

all: $(BINS)

stringbad.o: stringbad.cpp stringbad.h
	$(CXX) -c -o $@ $< $(CFLAGS)

vegnews.exe: vegnews.cpp $(OBJS)
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = main.exe
OBJS = golf.o

all: $(BINS)

golf.o: golf.cpp golf.h
	$(CXX) -c -o $@ $< $(CFLAGS)

main.exe: main.cpp golf.o
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

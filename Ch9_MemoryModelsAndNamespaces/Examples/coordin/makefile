CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = coordin_main.exe
OBJS = coordin.o

all: $(BINS)

coordin.o: coordin.cpp coordin.h
	$(CXX)	-c -o $@ $< $(CFLAGS)

coordin_main.exe:	main.cpp coordin.o
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
		rm -f $(BINS) $(OBJS)

.PHONY: all

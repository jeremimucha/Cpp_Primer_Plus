CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = use_stui.exe
OBJS = studenti.o


all: $(BINS)


studenti.o: studenti.cpp studenti.h
	$(CXX) -c -o $@ $< $(CFLAGS)

use_stui.exe: use_stui.cpp studenti.o
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

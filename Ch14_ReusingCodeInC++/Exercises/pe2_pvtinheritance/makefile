CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = usewinei.exe
OBJS = winei.o


all: $(BINS)


winei.o: winei.cpp winei.h
	$(CXX) -c -o $@ $< $(CFLAGS)

usewinei.exe: usewinei.cpp winei.o
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

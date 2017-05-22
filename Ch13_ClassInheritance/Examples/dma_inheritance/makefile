CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = usedma.exe
OBJS = dma.o

all: $(BINS)

dma.o: dma.cpp dma.h
	$(CXX) -c -o $@ $< $(CFLAGS)


usedma.exe: usedma.cpp dma.o
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

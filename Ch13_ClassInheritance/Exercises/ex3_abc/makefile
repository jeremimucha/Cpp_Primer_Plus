CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = use_dma_abc.exe 
OBJS = dma_abc.o

all: $(BINS)

dma_abc.o: dma_abc.cpp dma_abc.h
	$(CXX) -c -o $@ $< $(CFLAGS)


use_dma_abc.exe: use_dma_abc.cpp dma_abc.o
	$(CXX) -o $@ $^ $(CFLAGS)


clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

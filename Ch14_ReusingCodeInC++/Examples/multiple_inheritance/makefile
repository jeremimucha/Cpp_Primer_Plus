CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = worktest.exe workmi.exe
OBJS = worker0.o workermi.o


all: $(BINS)


worker0.o: worker0.cpp worker0.h
	$(CXX) -c -o $@ $< $(CFLAGS)

workermi.o: workermi.cpp workermi.h
	$(CXX) -c -o $@ $< $(CFLAGS)

worktest.exe: worktest.cpp worker0.o
	$(CXX) -o $@ $^ $(CFLAGS)

workmi.exe: workmi.cpp workermi.o
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

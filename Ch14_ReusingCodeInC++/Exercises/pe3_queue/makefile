CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = queuetest.exe
OBJS = workermi.o

all: $(BINS)


workermi.o: workermi.cpp workermi.h
	$(CXX) -c -o $@ $< $(CFLAGS)

queuetest.exe: queuetest.cpp workermi.o queuetp.h workermi.h
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all, clean

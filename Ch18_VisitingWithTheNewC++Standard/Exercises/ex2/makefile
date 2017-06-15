CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

SRC = cpmv.cpp
BINS = ex2.exe
DEPS = cpmv.h


all : $(BINS)

cpmv.o: cpmv.cpp cpmv.h
	$(CXX) -c -o $@ $< $(CFLAGS)

ex2.exe: ex2.cpp cpmv.o $(DEPS)
	$(CXX) -o $@ $^ $(CFLAGS)


clean:
	rm -f $(BINS)

.PHONY: all

CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = string2_test.exe pe12_2.exe
OBJS = string2.o

all: $(BINS)

string2.o: string2.cpp string2.h
	$(CXX) -c -o $@ $< $(CFLAGS)

string2_test.exe: string2_test.cpp $(OBJS)
	$(CXX) -o $@ $^ $(CFLAGS)

pe12_2.exe: pe12_2.cpp $(OBJS)
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = usebrass3.exe 
OBJS = acctabc.o

all: $(BINS)

acctabc.o: acctabc.cpp acctabc.h
	$(CXX) -c -o $@ $< $(CFLAGS)


usebrass3.exe: usebrass3.cpp acctabc.o
	$(CXX) -o $@ $^ $(CFLAGS)


clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

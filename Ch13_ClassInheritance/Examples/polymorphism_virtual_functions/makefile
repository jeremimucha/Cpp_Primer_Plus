CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = usebrass1.exe usebrass2.exe
OBJS = brass.o

all: $(BINS)

brass.o: brass.cpp brass.h
	$(CXX) -c -o $@ $< $(CFLAGS)


usebrass1.exe: usebrass1.cpp brass.o
	$(CXX) -o $@ $^ $(CFLAGS)

usebrass2.exe: usebrass2.cpp brass.o
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

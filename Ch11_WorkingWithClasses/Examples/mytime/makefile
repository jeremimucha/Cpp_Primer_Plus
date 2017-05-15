CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = usetime0.exe
OBJS = mytime0.o

all: $(BINS)

mytime0.o: mytime0.cpp mytime0.h
	$(CXX) -c -o $@ $< $(CFLAGS)

usetime0.exe: usetime0.cpp $(OBJS)
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = stacktem.exe stack_of_pointers1.exe


all: $(BINS)


stacktem.exe: stacktem.cpp stacktp.h
	$(CXX) -o $@ $^ $(CFLAGS)

stack_of_pointers1.exe: stack_of_pointers1.cpp stacktp1.h
	$(CXX) -o $@  $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

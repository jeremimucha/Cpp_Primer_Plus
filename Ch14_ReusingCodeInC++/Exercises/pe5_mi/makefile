CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++


BINS = useemp1.exe
OBJ = emp.o

all: $(BINS)

emp.o: emp.cpp emp.h
	$(CXX) -c -o $@ $< $(CFLAGS)

useemp1.exe: useemp1.cpp emp.o
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJ)

.PHONY: all, clean

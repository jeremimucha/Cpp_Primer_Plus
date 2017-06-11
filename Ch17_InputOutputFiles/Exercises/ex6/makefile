CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++


BINS = useemp.exe
OBJ = emp.o

all: $(BINS)

emp.o: emp.cpp emp.h
	$(CXX) -c -o $@ $< $(CFLAGS)

useemp.exe: useemp.cpp emp.o
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJ)

.PHONY: all, clean

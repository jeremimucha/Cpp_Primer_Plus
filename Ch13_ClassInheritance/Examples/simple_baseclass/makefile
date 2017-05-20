CFLAGS = -O2 -Wall -Wextra -std=c++0x
CXX = g++

BINS = usett0.exe usett1.exe
OBJS = tabtenn0.o tabtenn1.o

all: $(BINS)

tabtenn0.o: tabtenn0.cpp tabtenn0.h
	$(CXX) -c -o $@ $< $(CFLAGS)

tabtenn1.o: tabtenn1.cpp tabtenn1.h
	$(CXX) -c -o $@ $< $(CFLAGS)

usett0.exe: usett0.cpp tabtenn0.o
	$(CXX) -o $@ $^ $(CFLAGS)

usett1.exe: usett1.cpp tabtenn1.o
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all

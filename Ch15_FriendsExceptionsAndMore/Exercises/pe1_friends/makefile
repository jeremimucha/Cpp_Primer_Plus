CFLAGS = -O2 -Wall -Wextra -std=c++11
CXX = g++

SRC = tv.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRC))
BINS = use_tv.exe
DEPS = 


all : $(BINS)

%.o: $(SRC) $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

use_tv.exe: use_tv.cpp $(OBJS) $(DEPS)
	$(CXX) -o $@ $^ $(CFLAGS)


clean:
	rm -f $(BINS)

.PHONY: all

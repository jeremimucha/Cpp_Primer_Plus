# augment via OPTFLAGS
CFLAGS=-g -O2 -Wall -Wextra -std=c++0x
CC=g++
# augment linking options via OPTLIBS
LDLIBS=

# all .c files in source and below
SOURCES=$(wildcard *.cpp)
DEPS = $(wildcard *.h)
OBJ = $(SOURCES: .cpp=.o)


TARGET=number_tests


all: $(TARGET)

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDLIBS)

clean:
	rm $(TARGET)
	rm $(TESTS)
	rm tests/*.o

.PHONY: target all tests

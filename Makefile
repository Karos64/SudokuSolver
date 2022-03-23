CC = g++
CFLAGS = -std=c++11 -pedantic -Wall

example = solver.o

.PHONY: all clean

all: $(example)

$(example):
	$(CC) $(CFLAGS) example/solver.cpp -o solver.o

clean:
	find . -name '*.o' -delete
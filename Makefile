CC = g++
CFLAGS = -std=c++11 -pedantic -Wall

input = example/solver.cpp lib/SudokuSolver.cpp

example = solver.o

.PHONY: all clean

all: $(example)

$(example): $(input)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	find . -name '*.o' -delete
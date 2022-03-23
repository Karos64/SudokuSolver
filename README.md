<h1 align="center"> SudokuSolver</p>

<h3 align="center"> App that allows you to solve any 9x9 Sudoku! <p>

<h4 align="center"> made by Seweryn Jarco</p>

## Features
+ You can set any board to a *SudokuSolver* by `SetBoard` method and passing it 2D 9x9 int array.
+ It allows you to use `Valid` method to check if raw sudoku **looks** solvable. It will check if there are any numbers occuring twice (or more times) in any column and any row.
+ You can print the board to console using `PrintBoard`
+ You can check if sudoku is properly solved via `Check` method.
+ And lastly but not at least you can of course solve any **solvable** sudoku thanks to `Solve` method. It will return **true** or **false** depending if the sudoku can be solved or not.
+ SudokuSolver also comes with helper-methods: `CheckColumn`, `CheckRow`, `CheckBox` and `TrySolving` which are not available publicly but are used in `Solve` method

## Requirements
- None, it runs completely on its own!

## Technologies
- Whole project is build on C++

## Setup
To compile the example program simply run the **Makefile**
```
$ make
```
File **solver.o** will appear, then you can run it with
```
$ ./solver.o
```
The source code of SudokuSolver class can be found in **lib** folder.

## To be added...
+ For now "valid" sudoku here means that it does not have any repeated numbers in columns & rows but in the future validness of sudoku will also mean that it has only one solution.
+ Maybe some better look of the app, printing info in colors and "live mode" that will allow user to watch as the program tries to solve the sudoku in real time.

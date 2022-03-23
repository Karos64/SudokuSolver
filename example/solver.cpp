#include <iostream>
#include "../lib/SudokuSolver.h"

using namespace std;

int main() {
    int game[MAX_SUDOKU_SIZE][MAX_SUDOKU_SIZE] = {
        {0, 0, 0, 0, 0, 0, 7, 0, 0},
        {6, 7, 9, 2, 8, 0, 4, 0, 5},
        {0, 1, 3, 7, 0, 0, 8, 0, 0},
        {7, 6, 2, 0, 4, 0, 1, 9, 3},
        {0, 3, 0, 9, 2, 6, 5, 7, 4},
        {0, 0, 4, 0, 0, 1, 6, 0, 2},
        {0, 9, 0, 0, 0, 0, 0, 0, 7},
        {0, 8, 0, 0, 3, 2, 9, 0, 0},
        {3, 4, 1, 0, 9, 7, 0, 6, 0}
    };

    SudokuSolver solver;
    if( solver.SetBoard(game) ) {
        cout << "Board set successfuly!" << endl;
    }
    solver.PrintBoard();
    return 0;
}
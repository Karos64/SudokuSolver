#include <iostream>
#include "../lib/SudokuSolver.h"

using namespace std;

int sudokus[][MAX_SUDOKU_SIZE][MAX_SUDOKU_SIZE] = {
    { // this one does not have solutions!
        {0,9,0,8,6,5,2,0,0},
        {0,0,5,0,1,2,0,6,8},
        {0,0,0,0,0,0,0,4,0},
        {0,0,0,0,0,8,0,5,6},
        {0,0,8,0,0,0,4,0,0},
        {4,5,0,9,0,0,0,0,0},
        {0,8,0,0,0,0,0,0,0},
        {2,4,0,1,7,0,5,0,0},
        {0,0,7,2,8,3,0,9,0}
    },
    {
        {0,0,0,0,0,0,7,0,0},
        {6,7,9,2,8,0,4,0,5},
        {0,1,3,7,0,0,8,0,0},
        {7,6,2,0,4,0,1,9,3},
        {0,3,0,9,2,6,5,7,4},
        {0,0,4,0,0,1,6,0,2},
        {0,9,0,0,0,0,0,0,7},
        {0,8,0,0,3,2,9,0,0},
        {3,4,1,0,9,7,0,6,0}
    },
    {
        {0,9,5,0,0,0,0,0,0},
        {0,6,0,0,9,0,0,0,0},
        {1,8,0,7,2,3,5,0,0},
        {0,0,0,3,0,0,0,1,7},
        {0,1,3,0,0,0,8,4,0},
        {6,7,0,0,0,1,0,0,0},
        {0,0,6,9,5,8,0,7,1},
        {0,0,0,0,1,0,0,6,0},
        {0,0,0,0,0,0,9,5,0}
    }
};

int main(int argc, char * argv[]) {
    // get sudoku id to run from execution argument
    int sudokuID = 0;
    if(argc == 2) sudokuID = atoi(argv[1]);
    if(sudokuID < 0 || sudokuID > 2) sudokuID = 0;

    SudokuSolver solver;

    cout << "[" << (sudokuID+1) << "] Sudoku" << endl << endl;
    if(solver.SetBoard(sudokus[sudokuID])) {
        cout << "Board set successfuly!" << endl;
    } else {
        cout << "Unfortunately there was a problem with setting up a board!" << endl;
    }
    solver.PrintBoard();

    if(solver.Valid()) {
        cout << "This sudoku board is valid and SudokuSolver can try to solve it!" << endl;
    } else {
        cout << "This sudoku is invalid and SudokuSolver can't solve it!" << endl;
    }

    cout << "Solving..." << endl;
    bool success = false;
    if((success = solver.Solve())) {
        cout << "Sudoku was solved successfuly!" << endl;
    } else {
        cout << "Unfortunately SudokuSolver was not able to solve this sudoku :(" << endl;
    }
    solver.PrintBoard();

    if(success) {
        cout << "Validating..." << endl;
        if(solver.Check()) {
            cout << "Sudoku was checked and it is correctly solved!" << endl;
        } else {
            cout << "Oh no! There is a mistake in this solved sudoku!" << endl;
        }
    }
    return 0;
}
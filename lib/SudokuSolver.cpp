#include <iostream>
#include "../lib/SudokuSolver.h"

using namespace std;

SudokuSolver::SudokuSolver() {
    for(int i=0; i < MAX_SUDOKU_SIZE; i++) {
        for(int j=0; j < MAX_SUDOKU_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

bool SudokuSolver::SetBoard(int game[][MAX_SUDOKU_SIZE]) {
    for(int i=0; i < MAX_SUDOKU_SIZE; i++) {
        for(int j=0; j < MAX_SUDOKU_SIZE; j++) {
            int x = game[i][j];
            if(x < 0 || x > 9) return false;
            board[i][j] = x;
        }
    }
    return true;
}

void SudokuSolver::PrintBoard() {
    for(int i=0; i < MAX_SUDOKU_SIZE; i++) {
        for(int j=0; j < MAX_SUDOKU_SIZE; j++) {
            int x = board[i][j];
            cout << x << " ";
            if( (j+1) % 3 == 0) cout << "\t"; // horizontal separator
        }
        cout << endl;
        if( (i+1) % 3 == 0) cout << endl; // vertical separator
    }
}
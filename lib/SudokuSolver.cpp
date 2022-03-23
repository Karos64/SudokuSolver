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
    // Counter to counts numbers in rows and columns
    int counter[MAX_SUDOKU_SIZE][MAX_SUDOKU_SIZE][9] = {0};

    for(int i=0; i < MAX_SUDOKU_SIZE; i++) {
        for(int j=0; j < MAX_SUDOKU_SIZE; j++) {
            int x = game[i][j];
            if(x < 0 || x > 9) {
                isValid = false;
                return false;
            }
            if(x != 0) counter[i][j][x]++;
            board[i][j] = x;
        }
    }
    
    for(int i=0; i < MAX_SUDOKU_SIZE; i++) {
        for(int j=0; j < MAX_SUDOKU_SIZE; j++) {
            for(int k=0; k < 9; k++) {
                if(counter[i][j][k] > 1) {
                    isValid = false;
                    return false;
                }
            }
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
#include <iostream>
#include <vector>
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
            if(x < 0 || x > 9) {
                isValid = false;
                return false;
            }
            board[i][j] = x;
        }
    }

    // check for repeat numbers
    for(int i=0; i < MAX_SUDOKU_SIZE; i++) {
        // occurance of numbers 1-9 in row & columns
        bool occuredRow[9] = {false},
            occuredCol[9] = {false};

        for(int j=0; j < MAX_SUDOKU_SIZE; j++) {
            int x = game[i][j], y = game[j][i];
            if(x != 0) {
                if(occuredRow[x-1]) {
                    isValid = false;
                    return false;
                }
                occuredRow[x-1] = true;
            }
            if(y != 0) {
                if(occuredCol[y-1]) {
                    isValid = false;
                    return false;
                }
                occuredCol[y-1] = true;
            }
        }
    }
    
    return true;
}

void SudokuSolver::PrintBoard() {
    //if(!isValid) return;
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
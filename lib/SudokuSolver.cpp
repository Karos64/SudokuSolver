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
    for(int i=0; i < MAX_SUDOKU_SIZE && isValid; i++) {
        for(int j=0; j < MAX_SUDOKU_SIZE && isValid; j++) {
            int x = game[i][j];
            if(x < 0 || x > 9) isValid = false;
            board[i][j] = x;
        }
    }

    // check for repeat numbers
    for(int i=0; i < MAX_SUDOKU_SIZE && isValid; i++) {
        // occurance of numbers 1-9 in row & columns
        bool occuredRow[9] = {false},
            occuredCol[9] = {false};

        for(int j=0; j < MAX_SUDOKU_SIZE && isValid; j++) {
            int x = game[i][j], y = game[j][i];
            if(x != 0) { // row detection
                if(occuredRow[x-1]) isValid = false;
                occuredRow[x-1] = true;
            }
            if(y != 0) { // col detection
                if(occuredCol[y-1]) isValid = false;
                occuredCol[y-1] = true;
            }
        }
    }
    
    return isValid;
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

bool SudokuSolver::CheckColumn(int index) {
    bool occured[9] = {false};
    if(index > 8) return false;
    for(int i=0; i < MAX_SUDOKU_SIZE; i++) {
        int x = board[i][index];
        if(x == 0) continue;
        if(occured[x-1]) return false;
        occured[x-1] = true;
    }
    return true;
}

bool SudokuSolver::CheckRow(int index) {
    bool occured[9] = {false};
    if(index > 8) return false;
    for(int i=0; i < MAX_SUDOKU_SIZE; i++) {
        int x = board[index][i];
        if(x == 0) continue;
        if(occured[x-1]) return false;
        occured[x-1] = true;
    }
    return true;
}

bool SudokuSolver::CheckBox(int index) {
    bool occured[9] = {false};
    if(index > 8) return false;
    int x = ((index%3)*3), y = (index/3)*3;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            int el = board[x+i][y+j];
            if(el == 0) continue;
            if(occured[el-1]) return false;
            occured[el-1] = true;
        }
    }
    return true;
}

bool SudokuSolver::Solve(int solveType) {
    switch(solveType) {
        case SUDOKU_SOLVE_BRUTEFORCE:
            return SolveBruteforce();
        default:
            return SolveBruteforce();
    }
}

bool SudokuSolver::TrySolving(int idx) {
    if(!isValid) return false;
    int x = idx/9, y = idx-(x*9);
    if(board[x][y] == 9) return false;
    board[x][y]++;

    int box = x/3 + (y/3)*3;
    if(CheckRow(x) && CheckColumn(y) && CheckBox(box)) {
        if(x == 8 && y == 8) return true;
        int newIdx = idx;
        while(board[x][y] != 0) {
            newIdx++;
            x = newIdx/9, y = newIdx-(x*9);
        }
        if(!TrySolving(newIdx)) {
            return TrySolving(idx);
        } else return true;
    } else {
        if(board[x][y] == 9) {
            board[x][y] = 0;
            return false;
        }
        return TrySolving(idx);
    }
}

bool SudokuSolver::Check() {
    for(int i=0; i < MAX_SUDOKU_SIZE; i++) {
        if(!CheckColumn(i) || !CheckRow(i) || !CheckBox(i)) return false;
    }
    return true;
}

bool SudokuSolver::SolveBruteforce() {
    // find first 0 in grid
    for(int i=0; i < MAX_SUDOKU_SIZE; i++) {
        for(int j=0; j < MAX_SUDOKU_SIZE; j++) {
            if(board[i][j] == 0) return TrySolving((i*9)+j);
        }
    }
    return true;
}
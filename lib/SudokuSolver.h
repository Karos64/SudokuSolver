#define MAX_SUDOKU_SIZE     9

class SudokuSolver {
    private:
    int board[MAX_SUDOKU_SIZE][MAX_SUDOKU_SIZE];

    public:

    SudokuSolver();

    bool SetBoard(int [][MAX_SUDOKU_SIZE]);
    bool Solvable();
    bool Solve();
    void PrintBoard();
};
#define MAX_SUDOKU_SIZE     9

class SudokuSolver {
    private:
    int board[MAX_SUDOKU_SIZE][MAX_SUDOKU_SIZE];
    bool isValid = true;
    public:

    SudokuSolver();

    bool SetBoard(int [][MAX_SUDOKU_SIZE]);
    bool Valid() const {
        return isValid; 
    };
    bool Solve();
    void PrintBoard();
};
#define MAX_SUDOKU_SIZE     9

#define SUDOKU_SOLVE_BRUTEFORCE     0

class SudokuSolver {
    private:
    int board[MAX_SUDOKU_SIZE][MAX_SUDOKU_SIZE];
    bool isValid = true;

    bool CheckColumn(int);
    bool CheckRow(int);
    bool CheckBox(int);
    bool TrySolving(int);

    bool SolveBruteforce();

    public:

    SudokuSolver();

    bool SetBoard(int [][MAX_SUDOKU_SIZE]);
    bool Valid() const {
        return isValid; 
    };

    bool Solve(int solveType = 0);
    void PrintBoard();
    bool Check();
};
#include <iostream>
#include <vector>

using namespace std;

class NQBacktracking {
public:
    vector<int> ld, rd, cl;  // Left diagonal, right diagonal, and column trackers
    int x, y;  // Position of the first queen (x - row, y - column)

    NQBacktracking(int x_, int y_) {
        ld = vector<int>(30, 0);  // Initializing diagonals and columns as 0
        rd = vector<int>(30, 0);
        cl = vector<int>(30, 0);
        x = x_;  // Row for the first queen
        y = y_;  // Column for the first queen
    }

    // Function to print the board solution
    void printSolution(vector<vector<int>>& board) {
        cout << "N Queen Backtracking Solution:" << endl;
        cout << "Given initial position of 1st queen at row: " << x
             << " column: " << y << "\n" << endl;
        for (auto& row : board) {
            for (auto& cell : row) {
                cout << cell << " ";  // Print each cell in the row
            }
            cout << endl;
        }
    }

    // Backtracking utility function to place queens
    bool solveNQUtil(vector<vector<int>>& board, int col) {
        if (col >= N) {
            return true;  // All queens are placed
        }
        if (col == y) {
            return solveNQUtil(board, col + 1);  // Skip the given column for the first queen
        }

        for (int i = 0; i < N; ++i) {
            if (i == x) {
                continue;  // Skip the row of the first queen
            }
            // Check if current position is safe for the queen
            if (ld[i - col + N - 1] != 1 && rd[i + col] != 1 && cl[i] != 1) {
                board[i][col] = 1;
                ld[i - col + N - 1] = rd[i + col] = cl[i] = 1;  // Mark diagonals and column as attacked
                if (solveNQUtil(board, col + 1)) {
                    return true;
                }
                // Backtrack if placing queen doesn't lead to a solution
                board[i][col] = 0;
                ld[i - col + N - 1] = rd[i + col] = cl[i] = 0;  // Unmark the attack
            }
        }
        return false;
    }

    // Main function to solve the N-Queens problem
    bool solveNQ() {
        vector<vector<int>> board(N, vector<int>(N, 0));  // Initialize an empty board
        board[x][y] = 1;  // Place the first queen at the given position
        ld[x - y + N - 1] = rd[x + y] = cl[x] = 1;  // Mark the diagonals and column as attacked

        if (!solveNQUtil(board, 0)) {
            cout << "Solution does not exist" << endl;
            return false;
        }
        printSolution(board);  // Print the solution
        return true;
    }

private:
    const int N = 4;  // Size of the chessboard (4x4)
};

int main() {
    int x = 1, y = 3;  // Initial position of the first queen (row 1, column 3)
    NQBacktracking NQBt(x, y);
    NQBt.solveNQ();
    return 0;
}

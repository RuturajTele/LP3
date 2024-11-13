class NQBacktracking:
    def __init__(self, x_, y_):
        self.ld = [0] * 30  # Left diagonal
        self.rd = [0] * 30  # Right diagonal
        self.cl = [0] * 30  # Column
        self.x = x_  # Row of the first queen
        self.y = y_  # Column of the first queen

    def printSolution(self, board):
        print("N Queen Backtracking Solution:")
        print(f"Given initial position of 1st queen at row: {self.x} column: {self.y}\n")
        for line in board:
            print(" ".join(map(str, line)))

    def solveNQUtil(self, board, col):
        if col >= N:
            return True
        if col == self.y:
            return self.solveNQUtil(board, col + 1)

        for i in range(N):
            if i == self.x:
                continue
            # Check if the queen can be placed in the current position
            if (self.ld[i - col + N - 1] != 1 and self.rd[i + col] != 1) and self.cl[i] != 1:
                board[i][col] = 1
                self.ld[i - col + N - 1] = self.rd[i + col] = self.cl[i] = 1
                if self.solveNQUtil(board, col + 1):
                    return True
                # Backtrack if placing queen doesn't lead to a solution
                board[i][col] = 0
                self.ld[i - col + N - 1] = self.rd[i + col] = self.cl[i] = 0
        return False

    def solveNQ(self):
        board = [[0 for _ in range(N)] for _ in range(N)]
        # Place the first queen at the given position
        board[self.x][self.y] = 1
        self.ld[self.x - self.y + N - 1] = self.rd[self.x + self.y] = self.cl[self.x] = 1

        if not self.solveNQUtil(board, 0):
            print("Solution does not exist")
            return False
        self.printSolution(board)
        return True


if __name__ == "__main__":
    N = 4  # Size of the chessboard (4x4)
    x, y = 1, 3  # Initial position of the first queen (row, column)
    NQBt = NQBacktracking(x, y)
    NQBt.solveNQ()

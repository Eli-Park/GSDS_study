class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        self.output = []
        self.puzzle_helper(n, [], 0)
        return self.output

    def puzzle_helper(self, n, queens_positions, row):
        if row == n:
            self.output.append(self.generate_board(queens_positions, n))
            return
        
        for col in range(n):
            if self.is_safe(queens_positions, row, col):
                queens_positions.append(col)
                self.puzzle_helper(n, queens_positions, row + 1)
                queens_positions.pop()

    def is_safe(self, queens_positions, row, col):
        for r, c in enumerate(queens_positions):
            if c == col or abs(row - r) == abs(col - c):
                return False
        return True

    def generate_board(self, queens_positions, n):
        board = []
        for r in range(n):
            row_str = '.' * queens_positions[r] + 'Q' + '.' * (n - queens_positions[r] - 1)
            board.append(row_str)
        return board

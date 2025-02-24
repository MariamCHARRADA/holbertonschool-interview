#!/usr/bin/python3
""" 
N queens backtracing
"""

import sys


def could_place(board, row, col):
    """Check if a queen can be placed on the board"""
    for i in range(row):
        if board[i] == col or board[i] - i == col - row or board[i] + i == col + row:
            return False
    return True


def solve_nqueens(board, row, n):
    """Solve N queens recursively and print each solution"""
    if row == n:
        result = [[i, board[i]] for i in range(n)]
        print(result)
        return
    for col in range(n):
        if could_place(board, row, col):
            board[row] = col
            solve_nqueens(board, row + 1, n)


if __name__ == "__main__":
    """Main function to validate input and initiate solving"""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    board = [0] * n
    solve_nqueens(board, 0, n)

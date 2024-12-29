#!/usr/bin/python3
"""
Solves the N-Queens puzzle using backtracking
"""

import sys

if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)
try:
    n = int(sys.argv[1])
except ValueError:
    print("N must be a number")
    exit(1)
if n < 4:
    print("N must be at least 4")
    exit(1)
if not isinstance(n, int):
    print("N must be a number")
    exit(1)


def is_valid_state(state, n):
    """Check if a state is valid"""
    return len(state) == n


def get_candidates(state, n):
    """Generate valid positions for the next queen"""
    if not state:
        return range(n)

    position = len(state)
    candidates = set(range(n))
    for row, col in enumerate(state):
        candidates.discard(col)
        dist = position - row
        candidates.discard(col + dist)
        candidates.discard(col - dist)
    return candidates


def search(state, solutions, n):
    """Recursive backtracking search for solutions"""
    if is_valid_state(state, n):
        solutions.append(format_solution(state))
        return

    for candidate in get_candidates(state, n):
        state.append(candidate)
        search(state, solutions, n)
        state.pop()


def solve_nqueens(n):
    """Find all solutions to the N-Queens problem"""
    solutions = []
    state = []
    search(state, solutions, n)
    return solutions


def format_solution(state):
    """Format the solution as a list of [row, col] pairs"""
    return [[row, col] for row, col in enumerate(state)]


for solution in solve_nqueens(n):
    print(solution)

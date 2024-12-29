#!/usr/bin/python3
"""
N queens backtracking
"""

import sys

if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)

try:
    int(sys.argv[1])
except Exception:
    print("N must be a number")
    exit(1)

if int(sys.argv[1]) < 4:
    print("N must be at least 4")
    exit(1)
if not isinstance(int(sys.argv[1]), int):
    print("N must be an integer")
    exit(1)

n = int(sys.argv[1])


def is_valid_state(state, n):
    """Check if the state is a valid solution"""
    return len(state) == n


def get_candidates(state, n):
    """Get valid candidate positions for the next queen"""
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
    """Backtrack to find all solutions"""
    if is_valid_state(state, n):
        solutions.append(state_to_string(state))
        return

    for candidate in get_candidates(state, n):
        state.append(candidate)
        search(state, solutions, n)
        state.pop()


def solve_nqueens(n):
    """Solve the problem"""
    solutions = []
    state = []
    search(state, solutions, n)
    return solutions


def state_to_string(state):
    """Format the state as a list of [row, col]"""
    return [[row, col] for row, col in enumerate(state)]


for solution in solve_nqueens(n):
    print(solution)

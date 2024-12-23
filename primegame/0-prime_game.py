#!/usr/bin/python3
""" Prime Game """


def isWinner(x, nums):
    if not nums or x < 1:
        return None

    def count_primes(n):
        primes = [True] * (n + 1)
        primes[0] = primes[1] = False

        for i in range(2, int(n**0.5) + 1):
            if primes[i]:
                for multiple in range(i * i, n + 1, i):
                    primes[multiple] = False

        return sum(primes)

    maria_wins = 0
    ben_wins = 0

    for n in nums:
        if n < 2:
            continue

        primes = count_primes(n)

        if primes % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    return None

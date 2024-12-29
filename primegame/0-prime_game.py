#!/usr/bin/python3
"""
Prime Game
"""


def sieve_of_eratosthenes(n):
    """Generate a list of primes up to n"""
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(n**0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
    return is_prime


def count_primes_up_to(n, primes):
    """Count the number of primes up to n"""
    return sum(primes[: n + 1])


def isWinner(x, nums):
    """Determine the winner"""
    if not nums or x < 1:
        return None

    max_num = max(nums)
    primes = sieve_of_eratosthenes(max_num)
    maria_wins = 0
    ben_wins = 0

    for n in nums:
        prime_count = count_primes_up_to(n, primes)
        if prime_count % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None

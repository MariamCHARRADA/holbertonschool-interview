#!/usr/bin/python3
""" making the change """


def makeChange(coins, total):
    """
    Determine the fewest number of coins needed to meet a given amount total.

    Args:
        coins (list): List of coin values.
        total (int): Total amount to reach.

    Returns:
        int: Fewest number of coins needed, or -1 if it cannot be achieved.
    """
    if total <= 0:
        return 0

    coins.sort(reverse=True)  # Sort coins in descending order for efficiency
    count = 0

    for coin in coins:
        if total == 0:
            break
        if coin <= total:
            count += total // coin
            total %= coin

    return count if total == 0 else -1

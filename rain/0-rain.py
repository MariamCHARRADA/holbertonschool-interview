#!/usr/bin/python3
"""Calculate how many square units of water will be retained after it rains."""


def rain(walls):
    """Return the total amount of rainwater retained"""
    if not walls:
        return 0

    n = len(walls)
    left_max = walls[0]
    right_max = walls[-1]

    left, right = 1, n - 2
    total_water = 0

    while left <= right:
        if left_max <= right_max:
            if walls[left] < left_max:
                total_water += left_max - walls[left]
            else:
                left_max = walls[left]
            left += 1
        else:
            if walls[right] < right_max:
                total_water += right_max - walls[right]
            else:
                right_max = walls[right]
            right -= 1

    return total_water

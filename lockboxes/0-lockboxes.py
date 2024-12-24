#!/usr/bin/python3
"""function that determines if all the boxes can be opened """


def canUnlockAll(boxes):
    """determines if all the boxes can be opened"""

    if not isinstance(boxes, list) or len(boxes) == 0:
        return False

    n = len(boxes)
    opened = [False] * n
    opened[0] = True
    keys = [0]

    while keys:
        current_key = keys.pop()
        for key in boxes[current_key]:
            if 0 <= key < n and not opened[key]:
                opened[key] = True
                keys.append(key)

    return all(opened)

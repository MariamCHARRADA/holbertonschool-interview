#!/usr/bin/python3
"""
process log input
"""
import sys


def print_stats(file_size, status_counts):
    """
    Prints the current file size and status code counts
    """
    print("File size: {}".format(file_size))
    for key, value in sorted(status_counts.items()):
        if value > 0:
            print("{}: {}".format(key, value))


def main():
    """
    Reads stdin line by line and computes metrics
    """
    line_count = 0
    total_file_size = 0
    status_counts = {
        "200": 0,
        "301": 0,
        "400": 0,
        "401": 0,
        "403": 0,
        "404": 0,
        "405": 0,
        "500": 0,
    }

    try:
        for line in sys.stdin:
            line_count += 1
            parts = line.split()

            if len(parts) >= 2:
                try:
                    total_file_size += int(parts[-1])
                    if parts[-2] in status_counts:
                        status_counts[parts[-2]] += 1
                except (ValueError, IndexError):
                    pass
            if line_count % 10 == 0:
                print_stats(total_file_size, status_counts)

    except KeyboardInterrupt:
        print_stats(total_file_size, status_counts)
        raise

    print_stats(total_file_size, status_counts)


if __name__ == "__main__":
    main()

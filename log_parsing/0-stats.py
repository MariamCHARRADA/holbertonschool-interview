#!/usr/bin/python3
""" parse input """
import sys

if __name__ == "__main__":
    status_codes = {
        "200": 0,
        "301": 0,
        "400": 0,
        "401": 0,
        "403": 0,
        "404": 0,
        "405": 0,
        "500": 0,
    }
    total_lines = 0
    total_size = 0

    def print_statistics():
        """Prints the accumulated statistics"""
        print(f"File size: {total_size}")
        for code, count in sorted(status_codes.items()):
            if count > 0:
                print(f"{code}: {count}")

    try:
        for line in sys.stdin:
            total_lines += 1
            parts = line.split(" ")
            if len(parts) > 2:
                size = int(parts[-1])
                total_size += size
            code = parts[-2]
            if code in status_codes:
                status_codes[code] += 1
            if total_lines % 10 == 0:
                print_statistics()

    finally:
        print_statistics()

#!/usr/bin/python3
"""
Count words in the titles of hot posts on a subreddit using the Reddit API
"""

import requests


def count_words(subreddit, word_list, after=None, counts=None):
    """
    Count words in the titles of hot posts on a subreddit using the Reddit API
    """
    if counts is None:
        counts = {}
        word_list = [word.lower() for word in word_list]

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {"User-Agent": "0-count-words-bot"}
    params = {"after": after, "limit": 100}

    try:
        response = requests.get(
            url, headers=headers, params=params, allow_redirects=False
        )
        if response.status_code != 200:
            return

        data = response.json().get("data", {})
        after = data.get("after")
        posts = data.get("children", [])

        for post in posts:
            title = post["data"]["title"].lower().split()
            for word in word_list:
                counts[word] = counts.get(word, 0) + title.count(word)

        if after is not None:
            count_words(subreddit, word_list, after, counts)
        else:
            sorted_counts = sorted(
                [(word, count) for word, count in counts.items() if count > 0],
                key=lambda x: (-x[1], x[0]),
            )
            for word, count in sorted_counts:
                print(f"{word}: {count}")

    except Exception:
        return

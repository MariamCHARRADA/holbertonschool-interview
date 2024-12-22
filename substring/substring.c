#include "substring.h"

/**
 * find_substring - finds substrings made by concatenating given words
 * @s: the string to search in
 * @words: the words to match in the string
 * @nb_words: number of words in the array
 * @n: pointer to store the count of matching substrings
 * Return: array of starting indices of matching substrings, or NULL
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    int str_len, word_len, total_len, *res, i, j, k, found, match_count = 0;
    int *used;

    if (!s || !words || nb_words == 0 || !n)
        return (NULL);

    str_len = strlen(s);
    word_len = strlen(words[0]);
    total_len = word_len * nb_words;

    if (str_len < total_len)
    {
        *n = 0;
        return (NULL);
    }

    res = malloc(str_len * sizeof(int));
    if (!res)
    {
        *n = 0;
        return (NULL);
    }

    used = malloc(nb_words * sizeof(int));
    if (!used)
    {
        free(res);
        *n = 0;
        return (NULL);
    }

    for (i = 0; i <= str_len - total_len; i++)
    {
        memset(used, 0, nb_words * sizeof(int));
        for (j = 0; j < nb_words; j++)
        {
            const char *sub = s + i + j * word_len;
            found = 0;

            for (k = 0; k < nb_words; k++)
            {
                if (!used[k] && strncmp(sub, words[k], word_len) == 0)
                {
                    used[k] = 1;
                    found = 1;
                    break;
                }
            }
            if (!found)
                break;
        }
        if (j == nb_words)
            res[match_count++] = i;
    }

    free(used);

    if (match_count == 0)
    {
        free(res);
        *n = 0;
        return (NULL);
    }

    *n = match_count;
    return (res);
}

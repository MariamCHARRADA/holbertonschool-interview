#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *find_substring(char const *s, char const **words, int nb_words, int *n);
int *allocate_memory(int str_len);
int *allocate_used_memory(int nb_words);
int find_matching_substrings(char const *s, char const **words, int nb_words,
							 int str_len, int total_len, int *res, int *used);

/**
  *find_substring - finds substrings made by concatenating given words
  *@s: the string to search in
  *@words: the words to match in the string
  *@nb_words: number of words in the array
  *@n: pointer to store the count of matching substrings
 *
  *Return: array of starting indices of matching substrings, or NULL
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int str_len, word_len, total_len, *res, match_count = 0;
	int *used;

	if (!s || !words || nb_words == 0 || !n)
		return (NULL);

	str_len	  = strlen(s);
	word_len  = strlen(words[0]);
	total_len = word_len  * nb_words;

	if (str_len < total_len)
	{
		*n = 0;
		return (NULL);
	}

	res = allocate_memory(str_len);
	if (!res)
	{
		*n = 0;
		return (NULL);
	}

	used = allocate_used_memory(nb_words);
	if (!used)
	{
		free(res);
		*n = 0;
		return (NULL);
	}

	match_count = find_matching_substrings(s, words, nb_words, str_len,
										   total_len, res, used);

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

/**
  *allocate_memory - Allocates memory for the result array
  *@str_len: the length of the string
 *
  *Return: pointer to the allocated memory
 */
int *allocate_memory(int str_len) { return (malloc(str_len  * sizeof(int))); }

/**
  *allocate_used_memory - Allocates memory for the used array
  *@nb_words: the number of words
 *
  *Return: pointer to the allocated memory
 */
int *allocate_used_memory(int nb_words)
{
	return (malloc(nb_words  * sizeof(int)));
}

/**
  *find_matching_substrings - Finds the matching substrings
  *@s: the string to search in
  *@words: the words to match in the string
  *@nb_words: number of words
  *@str_len: the length of the string
  *@total_len: the total length of all words combined
  *@res: the array to store matching indices
  *@used: the array to keep track of used words
 *
  *Return: the count of matching substrings
 */
int find_matching_substrings(char const *s, char const **words, int nb_words,
							 int str_len, int total_len, int *res, int *used)
{
	int i, j, k, found, match_count = 0;

	for (i = 0; i <= str_len - total_len; i++)
	{
		memset(used, 0, nb_words  * sizeof(int));
		for (j = 0; j < nb_words; j++)
		{
			const char *sub = s + i + j  * strlen(words[0]);

			found = 0;

			for (k = 0; k < nb_words; k++)
			{
				if (!used[k] && strncmp(sub, words[k], strlen(words[0])) == 0)
				{
					used[k] = 1;
					found	= 1;
					break;
				}
			}
			if (!found)
				break;
		}
		if (j == nb_words)
			res[match_count++] = i;
	}

	return (match_count);
}

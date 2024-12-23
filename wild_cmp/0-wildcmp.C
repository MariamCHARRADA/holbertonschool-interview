#include "holberton.h"

/**
 * wildcmp - Compares two strings, considering '*' as a wildcard.
 * @s1: The first string.
 * @s2: The second string, which may contain the wildcard '*'.
 * Return: 1 if the strings match, 0 otherwise.
 */
int wildcmp(char *s1, char *s2) 
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s2 == '*')
	{
		if (*(s2 + 1) == '\0' || wildcmp(s1, s2 + 1))
			return (1);
		if (*s1 != '\0' && wildcmp(s1 + 1, s2))
			return (1);
	}

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}

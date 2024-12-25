#include "slide_line.h"

/**
 * slide_left - Slides and merges an array of integers to the left
 * @line: Line to be updated
 * @size: Size of the line
 */
void slide_left(int *line, size_t size)
{
	size_t i, j = 0;

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
			line[j++] = line[i];
	}
	while (j < size)
		line[j++] = 0;

	for (i = 0; i < size - 1; i++)
	{
		if (line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
		}
	}

	j = 0;
	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
			line[j++] = line[i];
	}
	while (j < size)
		line[j++] = 0;
}

/**
 * slide_right - Slides and merges an array of integers to the right
 * @line: Line to be updated
 * @size: Size of the line
 */
void slide_right(int *line, size_t size)
{
	size_t i, j = size - 1;

	for (i = size; i > 0; i--)
	{
		if (line[i - 1] != 0)
			line[j--] = line[i - 1];
	}
	while ((int) j >= 0)
		line[j--] = 0;

	for (i = size - 1; i > 0; i--)
	{
		if (line[i] == line[i - 1])
		{
			line[i] *= 2;
			line[i - 1] = 0;
		}
	}

	j = size - 1;
	for (i = size; i > 0; i--)
	{
		if (line[i - 1] != 0)
			line[j--] = line[i - 1];
	}
	while ((int) j >= 0)
		line[j--] = 0;
}

/**
 * slide_line - Slides and merges an array of integers
 * @line: Line to be updated
 * @size: Size of the line
 * @direction: Direction to slide (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL || size == 0)
		return (0);

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (direction == SLIDE_LEFT)
		slide_left(line, size);
	else
		slide_right(line, size);

	return (1);
}

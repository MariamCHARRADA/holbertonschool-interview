#include "lists.h"
#include <stdlib.h>

/**
 * recurse_list - Compares the left and right nodes of the linked list
 * recursively
 * @left: Pointer to the left side of the list
 * @right: Pointer to the current right node in recursion
 * Return: 1 if the list is a palindrome, 0 otherwise
 */
int recurse_list(listint_t **left, listint_t *right)
{
	if (!right)
		return (1);

	if (!recurse_list(left, right->next))
		return (0);

	if ((*left)->n != right->n)
		return (0);

	*left = (*left)->next;
	return (1);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Double pointer to the head of the list
 * Return: 1 if the list is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	if (!head || !*head)
		return (1);

	return (recurse_list(head, *head));
}

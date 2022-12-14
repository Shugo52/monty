#include "monty.h"

/**
 * push - Pushes op_arg unto the stack.
 *
 * @head: Pointer to List beginning.
 * @line_number: Line of code in Monty bytecode.
 *
 * Return: 0 if successful, 1 otherwise.
 */
void push(stack_t **head, u_int line_number)
{
	stack_t *node, *current = *head;
	(void) line_number;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = op_arg;
	node->next = NULL;

	if (!current)
	{
		node->prev = NULL;
		*head = node;
		return;
	}

	while (current->next)
		current = current->next;

	current->next = node;
	node->prev = current;
}

/**
 * pall - Prints all the values on the stack form the top
 *
 * @head: Pointer to bottom value in stack.
 * @line_number: Line of code in Monty bytecode.
 *
 * Return: 0 if successful, 1 otherwise.
 */
void pall(stack_t **head, u_int line_number)
{
	if (!head || !(*head))
		return;

	if ((*head)->next)
		pall(&((*head)->next), line_number);

	printf("%d\n", (*head)->n);
}

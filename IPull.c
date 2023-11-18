#include "monty.h"
/**
 * pull - prints the stack
 * @stack: the stack to deal with
 * @line_number: the line number in the file that readed
 * Return: No Thing
 */
void pull(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	(void)line_number;

	if (stack == NULL)
		return;

	node = *stack;

	if (node == NULL)
		return;

	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}

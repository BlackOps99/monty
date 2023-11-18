#include "monty.h"
/**
 * IPint - prints the value at the top of the stack.
 * @stack: the stack to deal with
 * @line_number: the line number in the file that readed
 * Return: No Thing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	(void)line_number;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty %s\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = *stack;

	printf("%d\n", node->n);
}

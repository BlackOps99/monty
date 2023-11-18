#include "monty.h"
/**
 * push - add node to the stack
 * @stack: the stack to deal with
 * @line_number: the line number in the file that readed
 * Return: No Thing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node_du;
	(void)line_number;

	new_node_du = malloc(sizeof(stack_t));

	if (new_node_du == NULL)
		fprintf(stderr, "Error: malloc failed\n");

	new_node_du->n = myData.value;
	new_node_du->next = *stack;
	new_node_du->prev = NULL;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node_du;
	}

	*stack = new_node_du;
}

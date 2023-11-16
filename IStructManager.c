#include "monty.h"

int createStack(stack_t **stack)
{
	stack_t *head;

	head = malloc(sizeof(stack_t));
	if (head == NULL)
	{
		return (-1);
	}

	head->n = 1;
	head->prev = NULL;
	head->next = NULL;

	*stack = head;

	return (1);
}

void freeStack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

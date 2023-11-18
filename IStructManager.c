#include "monty.h"
/**
 * freeStack - free to the stack
 * @stack: the stack to deal with
 * Return: No Thing
 */
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

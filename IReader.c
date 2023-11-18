#include "monty.h"
/**
 * readLine - Start read each line
 * @stack: point for the stack
 * @line: line to deal with it
 * @ln: line number
 * Return: 0 Success, 1 Failed
 */
int readLine(stack_t **stack, char line[1024], int ln)
{
	char *opcode;
	void (*func)(stack_t **, unsigned int);
	char arg[128] = "";
	char *value = arg;

	opcode = strtok(line, " \t\r\n\v\f");
	value = strtok(NULL, " \t\r\n\v\f");

	func = run_opt(opcode);
	if (func == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", ln, opcode);
		return (EXIT_FAILURE);
	}
	if (strcmp(opcode, "pall") != 0 && value == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		return (EXIT_FAILURE);
	}
	if (value != NULL)
		myData.value = atoi(value);
	func(stack, ln);

	return (EXIT_SUCCESS);
}

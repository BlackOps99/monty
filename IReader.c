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
	char *token, *opcode, *value;
	void (*func)(stack_t **, unsigned int);

	token = strtok(line, "\n\t\a\b");
	while (token != NULL)
	{
		opcode = strtok(token, " ");
		if (opcode != NULL)
		{
			value = strtok(NULL, " \t\n\a\b");
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
			if (strcmp(opcode, "pall") && value != NULL)
				myData.value = atoi(value);
			func(stack, ln);
		}
		token = strtok(NULL, "\n\t\a\b");
	}

	return (EXIT_SUCCESS);
}

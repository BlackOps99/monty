#include "monty.h"

myData_n myData = {0, 0};

/**
 * main - Start LIFO, FILO program
 * @argc: Count of arguments
 * @argv: Pointer that containing arguments that passed to program
 * Return: 0 Success, 1 Failed
 */
int main(int argc, char *argv[])
{
	FILE *fileReader;
	char line[1024];
	int ln = 0, res = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	fileReader = fopen(argv[1], "r");
	if (fileReader == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), fileReader) != NULL)
	{
		ln++;
		res = readLine(&stack, line, ln);
		if (res != EXIT_SUCCESS)
		{
			freeStack(&stack);
			fclose(fileReader);
			return (res);
		}
	}

	freeStack(&stack);
	fclose(fileReader);
	return (EXIT_SUCCESS);
}
/**
 * run_opt - Start LIFO, FILO program
 * @opcode: for start run the program
 * Return: No Thing
 */
void (*run_opt(char *opcode))(stack_t **, unsigned int)
{
	instruction_t op_funcs[] = {
	    {"push", push},
	    {"pall", pull},
	    {NULL, NULL}};

	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

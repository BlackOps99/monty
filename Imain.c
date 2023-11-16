#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *fileReader;
	char line[1024];
	int ln = 0;
	char *token, *opcode, *value;
	void (*func)(stack_t **, unsigned int);
	stack_t *stack = NULL;
	myData_n *data = NULL;

	if (argc < 2)
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

	if (createStack(&stack) != 1)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), fileReader) != NULL)
	{
		ln++;
		token = strtok(line, " \t\n");
		while (token != NULL)
		{
			opcode = strtok(token, " ");
			printf("%s %s\n", opcode, value); // atoi(token);

			token = strtok(NULL, " \t\n");
		}
	}

	freeStack(&stack);

	fclose(fileReader);
	return (EXIT_SUCCESS);
}

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

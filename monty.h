#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct myDataInfo - program representation
 * @mode: FIFO OR LIFO
 * @value: the number to deal with
 *
 * Description: struct to save data to process program
 * for stack, queues, LIFO, FIFO
 */
typedef struct myDataInfo
{
	int mode;
	int value;
} myData_n;

extern myData_n myData;
int readLine(stack_t **stack, char line[1024], int ln);
void freeStack(stack_t **stack);
void (*run_opt(char *opcode))(stack_t **, unsigned int);

void push(stack_t **stack, unsigned int line_number);
void pull(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);

#endif

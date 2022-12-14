#include "monty.h"

/**
 * get_op_func - Gets opcode per line in monty bytecode file
 * @buffer: Filename of monty bytecode.
 *
 * Return: Pointer to appropriate opcode.
 */
void (*get_op_func(char *buffer))(stack_t **, u_int)
{
	char *temp;
	instruction_t ops[] = {
	    {"push", push},
	    {"pall", pall},
	    {NULL, NULL}};
	int i = 0;

	op_code = strtok(buffer, " ");
	temp = strtok(NULL, " ");
	if (temp)
		op_arg = atoi(temp);

	while (ops[i].opcode)
	{
		if (!strcmp(op_code, ops[i].opcode))
			return (ops[i].f);
		i++;
	}

	return (NULL);
}

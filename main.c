#include "monty.h"

/* Global variable declaration */
int op_arg = 0;
char *op_code;

/**
 * main - Program entry point
 *
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	char *buffer;
	stack_t *stack = NULL;
	ssize_t monty_file;
	FILE *fd;
	size_t len = 0, line_number = 0;
	void (*func)(stack_t **, u_int);

	if (argc != 2)
	{
		dprintf(2, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	monty_file = open(argv[1], O_RDONLY);
	if (monty_file == -1)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	fd = fdopen(monty_file, "r");

	while (getline(&buffer, &len, fd) != -1)
	{
		buffer = strtok(buffer, "\n");
		line_number++;
		func = get_op_func(buffer);
		if (func == NULL)
		{
			dprintf(2, "L%ld: unknown instruction %s\n", line_number, op_code);
			exit(EXIT_FAILURE);
		}
		func(&stack, line_number);
	}

	free(buffer);
	fclose(fd);
	close(monty_file);
	return (0);
}

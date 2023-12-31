#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
* main - main
* @argc: argc
* @argv: argv
* Return: int
*/

int main(int argc, char *argv[])
{
	char *ln;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		ln = NULL;
		read_line = getline(&ln, &size, file);
		bus.ln = ln;
		counter++;
		if (read_line > 0)
		{
			execute(ln, &stack, counter, file);
		}
		free(ln);
	}
	free_stack(stack);
	fclose(file);
return (0);
}

#include "monty.h"
/**
* execute - executes
* @stack: stack
* @counter: line_counter
* @file: file
* @ln: line number
*/

int execute(char *ln, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", push_item}, {"pall", print_all}, {"pint", print_int},
				{"pop", pop_item},
				{"swap", swap_item},
				{"add", func_add_item},
				{"nop", func_no_op},
				{"sub", sub_item},
				{"div", div_item},
				{"mul", multiply_item},
				{"mod", mode_item},
				{"pchar", print_char},
				{"pstr", print_str},
				{"rotl", rotates_func_top},
				{"rotr", rotates_func_bottom},
				{"queue", print_queue},
				{"stack", print_top_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *operation;

	operation = strtok(ln, " \n\t");
	if (operation && operation[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && operation)
	{
		if (strcmp(operation, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (operation && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, operation);
		fclose(file);
		free(ln);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

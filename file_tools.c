#include "monty.h"

/**
 * filePath - file path
 * @path: file path
 * Return: void
 */

void filePath(char *path)
{
	FILE *file_d = fopen(path, "r");

	if (path == NULL || file_d == NULL)
		err(2, path);

	read_file(file_d);
	fclose(file_d);
}


/**
 * read_file - reads file
 * @file_d: file descriptor
 */

void read_file(FILE *file_d)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, file_d) != -1; line_number++)
	{
		format = parse_line(buffer, line_number, format);
	}
	free(buffer);
}


/**
 * parse_line - parse line
 * @buffer: buffer
 * @line_number: line number
 * @format: format
 */

int parse_line(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, value, line_number, format);
	return (format);
}

/**
 * find_func - find function
 * @opcode: opcode
 * @value: value
 * @format:  format
 * @ln: line number
 */

void find_func(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_item_to_stack},
		{"pall", print_stack_items},
		{"pint", print_top_item},
		{"pop", pop_top_item},
		{"nop", nop},
		{"swap", swap_items},
		{"add", add_items},
		{"sub", sub_items},
		{"div", div_items},
		{"mul", multiply_items},
		{"mod", mode_items},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, ln, opcode);
}


/**
 * call_fun - Calls function.
 * @func: function
 * @op: opcode
 * @val: value
 * @ln: line numeber
 * @format: Format
 */

void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}

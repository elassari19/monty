#include "monty.h"

/**
 * error - error
 * @error: error code
 * Return: void
 */

void error(int error, ...)
{
	va_list argrg;
	int munber;
	char *str_char;

	va_start(argrg, error);
	switch (error)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(argrg, char *));
			break;
		case 3:
			munber = va_arg(argrg, int);
			str_char = va_arg(argrg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", munber, str_char);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(argrg, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * expand_errors - handles errors.
 * @error: error codes
 * Return: void
 */

void expand_errors(int error, ...)
{
	va_list argrg;
	int munber;
	char *str_char;

	va_start(argrg, error);
	switch (error)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(argrg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(argrg, int));
			break;
		case 8:
			munber = va_arg(argrg, unsigned int);
			str_char = va_arg(argrg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", munber, str_char);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(argrg, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * errors_name - handles errors.
 * @error: The error codes are the following:
 * Return: void
 */

void errors_name(int error, ...)
{
	va_list argrg;
	int munber;

	va_start(argrg, error);
	munber = va_arg(argrg, int);
	switch (error)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", munber);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", munber);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

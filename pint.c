#include "monty.h"
/**
 * print_int - prints int
 * @head: head
 * @ln: line number
*/

void print_int(stack_t **head, unsigned int ln)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", ln);
		fclose(bus.file);
		free(bus.ln);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

#include "monty.h"

/**
 * func_add_item - func add item
 * @head: head
 * @ln: line_number
 * Return: void
*/

void func_add_item(stack_t **head, unsigned int ln)
{
	stack_t *headStack;
	int len = 0, node;

	headStack = *head;
	while (headStack)
	{
		headStack = headStack->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", ln);
		fclose(bus.file);
		free(bus.ln);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	headStack = *head;
	node = headStack->n + headStack->next->n;
	headStack->next->n = node;
	*head = headStack->next;
	free(headStack);
}

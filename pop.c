#include "monty.h"

/**
 * pop_item - pop item
 * @head: head
 * @ln: line number
*/

void pop_item(stack_t **head, unsigned int ln)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
		fclose(bus.file);
		free(bus.ln);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}

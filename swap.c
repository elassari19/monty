#include "monty.h"

/**
 * swap_item - swap item
 * @head: head
 * @ln: line number
*/

void swap_item(stack_t **head, unsigned int ln)
{
	stack_t *h;
	int len = 0, node;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		fclose(bus.file);
		free(bus.ln);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	node = h->n;
	h->n = h->next->n;
	h->next->n = node;
}

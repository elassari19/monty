#include "monty.h"

/**
 * div_item - divides item
 * @head: head
 * @nl: line_number
*/

void div_item(stack_t **head, unsigned int nl)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", nl);
		fclose(bus.file);
		free(bus.ln);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", nl);
		fclose(bus.file);
		free(bus.ln);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	node = h->next->n / h->n;
	h->next->n = node;
	*head = h->next;
	free(h);
}

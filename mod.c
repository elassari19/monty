#include "monty.h"

/**
 * mode_item - mode item
 * @head: head
 * @ln: line number
*/

void mode_item(stack_t **head, unsigned int ln)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", ln);
		fclose(bus.file);
		free(bus.ln);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln);
		fclose(bus.file);
		free(bus.ln);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	node = h->next->n % h->n;
	h->next->n = node;
	*head = h->next;
	free(h);
}

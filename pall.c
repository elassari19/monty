#include "monty.h"
/**
 * print_all - prints all items
 * @head: head
 * @ln: line number
*/

void print_all(stack_t **head, unsigned int ln)
{
	stack_t *h;
	(void)ln;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

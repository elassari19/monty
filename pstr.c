#include "monty.h"
/**
 * print_str - prints string
 * @head: head
 * @ln: line number
 * Return: no return
*/
void print_str(stack_t **head, unsigned int ln)
{
	stack_t *h;
	(void)ln;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}

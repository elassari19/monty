#include "monty.h"

/**
* free_stack - free stack
* @head: head
*/

void free_stack(stack_t *head)
{
	stack_t *node;

	node = head;
	while (head)
	{
		node = head->next;
		free(head);
		head = node;
	}
}

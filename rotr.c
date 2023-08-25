#include "monty.h"

/**
  *rotates_func_bottom- rotates function to bottom
  *@head: head
  *@ln: line number
 */

void rotates_func_bottom(stack_t **head, __attribute__((unused)) unsigned int ln)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}

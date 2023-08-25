#include "monty.h"

/**
  *rotates_func_top- rotates function to top
  *@head: head
  *@ln: line number
 */

void rotates_func_top(stack_t **head,  __attribute__((unused)) unsigned int ln)
{
	stack_t *tmp = *head, *node;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	node = (*head)->next;
	node->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = node;
}

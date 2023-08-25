#include "monty.h"

/**
 * add_item - add item
 * @head: head
 * @n: n
*/
void add_item(stack_t **head, int n)
{

	stack_t *new_node, *node;

	node = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (node)
		node->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

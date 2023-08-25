#include "monty.h"
/**
 * print_queue - prints queue
 * @head: head
 * @ln: line number
 * Return: no return
*/
void print_queue(stack_t **head, unsigned int ln)
{
	(void)head;
	(void)ln;
	bus.lifi = 1;
}

/**
 * add_item_to_queue - add item to queue
 * @n: n
 * @head: head
*/

void add_item_to_queue(stack_t **head, int n)
{
	stack_t *new_node, *node;

	node = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (node)
	{
		while (node->next)
			node = node->next;
	}
	if (!node)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		node->next = new_node;
		new_node->prev = node;
	}
}

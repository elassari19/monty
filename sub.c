#include "monty.h"

/**
  *sub_item- sustration
  *@head: stack head
  *@ln: line number
 */

void sub_item(stack_t **head, unsigned int ln)
{
	stack_t *node;
	int sus, nodes;

	node = *head;
	for (nodes = 0; node != NULL; nodes++)
		node = node->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln);
		fclose(bus.file);
		free(bus.ln);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	node = *head;
	sus = node->next->n - node->n;
	node->next->n = sus;
	*head = node->next;
	free(node);
}

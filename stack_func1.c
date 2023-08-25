#include "monty.h"


/**
 * add_item_to_stack - Adds a item to the stack.
 * @new_item: Pointer to the new item.
 * @ln: line number
 */

void add_item_to_stack(stack_t **new_item, __attribute__((unused))unsigned int ln)
{
	stack_t *stack;

	if (new_item == NULL || *new_item == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_item;
		return;
	}
	stack = head;
	head = *new_item;
	head->next = stack;
	stack->prev = head;
}


/**
 * print_stack_items_items - print stack items
 * @stack: stack
 * @line_number: line number
 */

void print_stack_items(stack_t **stack, unsigned int line_number)
{
	stack_t *tmpStack;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmpStack = *stack;
	while (tmpStack != NULL)
	{
		printf("%d\n", tmpStack->n);
		stack = tmpStack->next;
	}
}

/**
 * pop_top_item_item - pop item from stack
 * @stack: stack
 * @line_number: line number
 */

void pop_top_item(stack_t **stack, unsigned int line_number)
{
	stack_t *tmpStack;

	if (stack == NULL || *stack == NULL)
		expand_errors(7, line_number);

	tmpStack = *stack;
	*stack = tmpStack->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmpStack);
}

/**
 * print_top_item_item - Prints the top item
 * @stack: stack
 * @line_number: line number
 */

void print_top_item(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		expand_errors(6, line_number);
	printf("%d\n", (*stack)->n);
}

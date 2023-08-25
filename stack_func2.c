#include "monty.h"

/**
 * nop - nop
 * @stack: stack
 * @line_number: line number
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * swap_items - Swaps items
 * @stack: stack
 * @line_number: line number
 */

void swap_items(stack_t **stack, unsigned int line_number)
{
	stack_t *_stack_t;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		expand_errors(8, line_number, "swap");
	_stack_t = (*stack)->next;
	(*stack)->next = _stack_t->next;
	if (_stack_t->next != NULL)
		_stack_t->next->prev = *stack;
	_stack_t->next = *stack;
	(*stack)->prev = _stack_t;
	_stack_t->prev = NULL;
	*stack = _stack_t;
}

/**
 * add_items - add item
 * @stack: stack
 * @line_number: line number
 */

void add_items(stack_t **stack, unsigned int line_number)
{
	int number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		expand_errors(8, line_number, "add");

	(*stack) = (*stack)->next;
	number = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = number;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_items - substrack items
 * @stack: stack
 * @line_number: line number
 */

void sub_items(stack_t **stack, unsigned int line_number)
{
	int number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		expand_errors(8, line_number, "sub");


	(*stack) = (*stack)->next;
	number = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = number;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_items - divide items
 * @stack: stack
 * @line_number: line number
 */

void div_items(stack_t **stack, unsigned int line_number)
{
	int number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		expand_errors(8, line_number, "div");

	if ((*stack)->n == 0)
		expand_errors(9, line_number);
	(*stack) = (*stack)->next;
	number = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = number;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

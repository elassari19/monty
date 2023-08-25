#include "monty.h"

/**
 * multiply_items - multiply items
 * @stack: stack
 * @line_number: line number
 */
void multiply_items(stack_t **stack, unsigned int line_number)
{
	int number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		expand_errors(8, line_number, "mul");

	(*stack) = (*stack)->next;
	number = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = number;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mode_items - mode items
 * @stack: stack
 * @line_number: line number
 */

void mode_items(stack_t **stack, unsigned int line_number)
{
	int number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		expand_errors(8, line_number, "mod");


	if ((*stack)->n == 0)
		expand_errors(9, line_number);
	(*stack) = (*stack)->next;
	number = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = number;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

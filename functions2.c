#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @stack: the stack
 * @line_number: instruction line number
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = (*stack)->next;
	if (!temp)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	temp->n += (*stack)->n;
	free(*stack);
	*stack = temp;
}
/**
 * swap - swaps the top two elements of the stack
 * @stack: the stack
 * @line_number: instruction line number
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	temp = (*stack)->n;
	if (!temp)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

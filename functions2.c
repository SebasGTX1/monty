#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @stack: the stack
 * @line_number: instruction line number
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (*stack)
		temp = (*stack)->next;
	if (!temp)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short", line_number);
		argument = "FAIL";
		return;
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

	if (*stack)
		temp = (*stack)->n;
	else
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short", line_number);
		argument = "FAIL";
		return;
	}
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

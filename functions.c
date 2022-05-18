#include "monty.h"
/**
 * push - pushes an element to the stack
 * @stack: the stack
 * @line_number: instruction line number
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int number;

	if (strcmp(argument, "0") != 0 && atoi(argument) == 0)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	number = atoi(argument);

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = number;
	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}
/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack
 * @stack: the stack
 * @line_number: instruction line number
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	UNUSED(line_number);
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	temp = NULL;
}
/**
 * pint - prints the value at the top of the stack
 * @stack: the stack
 * @line_number: instruction line number
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop - removes the top element of the stack
 * @stack: the stack
 * @line_number: instruction line number
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *save;

	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	save = (*stack)->next;
	free(*stack);
	*stack = save;
}
/**
 * nop - doesn’t do anything
 * @stack: the stack
 * @line_number: instruction line number
 * Return: nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
	UNUSED(line_number);
	UNUSED(stack);
}

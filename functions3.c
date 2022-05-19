#include "monty.h"
/**
 * mod - computes the rest of the division of the
 * second top element of the stack by the top element of the stack
 * @stack: the stack
 * @line_number: instruction line number
 * Return: nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (*stack && (*stack)->next)
		temp = (*stack)->next;
	if (!temp)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		argument = "FAIL";
		return;
	}
	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		argument = "FAIL";
		return;
	}
	temp->n %= (*stack)->n;
	free(*stack);
	*stack = temp;
}
/**
 * pchar - prints the char at the top of the stack
 * @stack: the stack
 * @line: instruction line number
 * Return: nothing
 */
void pchar(stack_t **stack, unsigned int line)
{
	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", line);
		argument = "FAIL";
		return;
	}
	if ((*stack)->n <= 0 || (*stack)->n >= 127)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n", line);
		argument = "FAIL";
		return;
	}
	printf("%c\n", (*stack)->n);
}
/**
 * pstr - prints the string starting at the top of the stack
 * @stack: the stack
 * @line_number: instruction line number
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	UNUSED(line_number);
	while (temp)
	{
		if (temp->n <= 0 || temp->n >= 127)
			break;
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
/**
 * rotl - rotates the stack to the top
 * @stack: the stack
 * @line_number: instruction line number
 * Return: nothing
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *new, *aux = *stack;

	UNUSED(line_number);
	if (*stack)
	{
		new = malloc(sizeof(stack_t));
		new->n = (*stack)->n;
		new->next = NULL;
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		new->prev = temp;
		temp->next = new;
		*stack = (*stack)->next;
		free(aux);
	}
}

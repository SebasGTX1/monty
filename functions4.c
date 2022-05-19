#include "monty.h"
/**
 * _stack - set's the stack mode
 * @stack: the stack
 * @line_number: instruction line number
 * Return: nothing
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
	argument[1] = "stack";
}
/**
 * queue - set's the queue mode
 * @stack: the stack
 * @line_number: instruction line number
 * Return: nothing
 */
void queue(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
	argument[1] = "queue";
}
/**
 * _isalpha - checks for alphabetic character
 * @c: is a character
 * Return: 0 (Success) 1 (Fail)
*/
int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	return (0);
}

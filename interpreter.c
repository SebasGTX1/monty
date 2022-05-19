#include "monty.h"
/**
 * free_stack - frees a stack
 * @stack: stack to be freed
 * Return: no return
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	if (stack)
	{
		while ((temp = stack))
		{
			stack = stack->next;
			free(temp);
		}
	}
}
/**
 * interpreter - interprets and excecute
 * each intruction line
 * @instruction: instruction to be interpreted
 * @stack: stack
 * @line: line number
 * Return: Nothing
 */
void interpreter(char *instruction, unsigned int line, stack_t **stack)
{
	instruction_t array[] = INSTRUCTIONS;
	int i = 0, bol = 0;
	void (*func)(stack_t **stack, unsigned int line_number);
	char *opcode, *arg;

	if (instruction)
	{
		opcode = strtok(instruction, " \n\t");
		if (opcode && opcode[0] != '#')
		{
			arg = strtok(NULL, " \n\t#");
			while (i < 14)
			{
				if (strcmp(opcode, array[i].opcode) == 0)
				{
					if (strcmp(opcode, array[0].opcode) == 0 && arg)
						argument = arg;
					func = array[i].f;
					bol = 1;
				}
				if (bol)
					break;
				i++;
			}
			if (bol)
			{
				func(stack, line);
				if (strcmp(argument, "FAIL") == 0)
					return;
				argument = "reset"; }
			else
			{
				dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line, opcode);
				argument = "FAIL";
				return; }
		}
	}
}

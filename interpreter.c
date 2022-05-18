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
 * @instructions: array of instructions
 * Return: Nothing
 */
void interpreter(char **instructions)
{
	instruction_t array[] = INSTRUCTIONS;
	int i = 0, j = 0, bol = 0;
	unsigned int line = 1;
	void (*func)(stack_t **stack, unsigned int line_number);
	stack_t *stack = NULL;
	char *opcode, *arg;

	while (instructions[j])
	{
		opcode = strtok(instructions[j], " #\t");
		if (opcode)
		{
			arg = strtok(NULL, " \t#");
			while (i < 7)
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
				func(&stack, line);
				if (strcmp(argument, "FAIL") == 0)
					return;
			}
			else
			{
				dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line, opcode);
				free_stack(stack), argument = "FAIL";
				return;
			}
		} j++, line++, i = 0, bol = 0;
	} free_stack(stack);
}

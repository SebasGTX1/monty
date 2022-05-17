#include "monty.h"
/**
 * main - starts the monty interpreter
 * @ac: number of arguments
 * @av: arguments vector
 * Return: Always 0
 */

int main(int ac, char *av[])
{
	char **tokens;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	tokens = tokenizer(av[1]);
	interpreter(tokens);
	return (0);
}

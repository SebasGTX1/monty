#include "monty.h"
/**
 * main - starts the monty interpreter
 * @ac: number of arguments
 * @av: arguments vector
 * Return: Always 0
 */

int main(int ac, char *av[])
{
	char **tokens = NULL;
	int i = 0;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	tokens = tokenizer(av[1]);
	interpreter(tokens);
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
	return (0);
}

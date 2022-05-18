#include "monty.h"
/**
 * main - starts the monty interpreter
 * @ac: number of arguments
 * @av: arguments vector
 * Return: Always 0
 */

int main(int ac, char *av[])
{
	int fd, buffsize = 1024, i = 0;
	ssize_t read_val;
	char *buffer = NULL, *token = NULL, **tokens = NULL;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	buffer = _calloc(buffsize, 1);
	tokens = malloc(buffsize * sizeof(char *));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		free(buffer), free(tokens);
		exit(EXIT_FAILURE);
	}
	while ((read_val = read(fd, buffer, buffsize)) > 0)
	{
		token = strtok(buffer, "\n");
		while (token)
		{
			if (i >= buffsize)
			{
				dprintf(STDERR_FILENO, "Error: malloc failed\n");
				exit(EXIT_FAILURE);
			}
			tokens[i] = token;
			token = strtok(NULL, "\n");
			i++;
		}
		tokens[i] = NULL;
	}
	close(fd);
	interpreter(tokens);
	free(tokens), free(buffer);
	if (strcmp(argument, "FAIL") == 0)
		exit(EXIT_FAILURE);
	return (0);
}

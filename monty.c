#include "monty.h"
/**
 * _free - frees the tokens
 * @tokens: array of tokens
 * Return: no return
 */
void _free(char **tokens)
{
	int i = 0;

	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

/**
 * main - starts the monty interpreter
 * @ac: number of arguments
 * @av: arguments vector
 * Return: Always 0
 */

int main(int ac, char *av[])
{
	int buffsize = 10024, i = 0;
	ssize_t read_val = 0;
	size_t bytes = 1;
	char *buffer = NULL, **tokens = NULL;
	FILE *fd;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	tokens = malloc(buffsize * sizeof(char *));
	fd = fopen(av[1], "r");
	if (!fd)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		free(buffer), free(tokens);
		exit(EXIT_FAILURE); }
	while (read_val != EOF)
	{
		buffer = NULL;
		read_val = getline(&buffer, &bytes, fd);
		if (read_val == -1)
		{
			free(buffer);
			break; }
		tokens[i] = _calloc(1024, 1);
		tokens[i] = strcpy(tokens[i], buffer);
		i++;
		free(buffer); }
	tokens[i] = NULL;
	interpreter(tokens);
	_free(tokens);
	if (strcmp(argument, "FAIL") == 0)
	{
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	fclose(fd);
	return (0);
}

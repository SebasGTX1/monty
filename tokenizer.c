#include "monty.h"
/**
 * tokenizer - tokenize each intructions line in a
 * .m file
 * @filename: name of the instructions file
 * Return: an array with all the instruction lines
 */

char **tokenizer(const char *filename)
{
	int fd, buffsize = 1024, i = 0;
	ssize_t read_val;
	char *buffer = malloc(buffsize), *token, **tokens;

	tokens = malloc(buffsize * sizeof(char *));
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
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
	}
	return (tokens);
}

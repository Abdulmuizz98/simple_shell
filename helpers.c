#include "main.h"
/**
 * putprompt - uses write to print the $ prompt for shell
 *
 * Return: the number of characters written, 2 if success.
 */
int putprompt(void)
{
	char *prompt = "$ ";
	if (isatty(STDIN_FILENO))
		return (write(STDOUT_FILENO, prompt, 4));
	else
		return (-1);
}

/**
 * _strcpy - copies the string pointed to by src
 * @dest: A pointer to a char that will be changed
 * @src: A pointer to a char that will be changed
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * commandline - gets getline content to be command ready
 * @nline: getline content
 * @nread: the length of getline content
 *
 * Return: pointer to the command ready line;
 */
char *commandline(char *nline, ssize_t nread)
{
	char *line;

	line = malloc(sizeof(char) * nread);
	_strcpy(line, nline);
	line[nread - 1] = '\0';
	return (line);
}

/**
 * _strlen - to return length of string
 * @s: the string
 *
 * Return: 0
 */
int _strlen(char *s)
{
	int u;

	u = 0;
	while (s[u] != '\0')
	{
		u++;
	}
	return (u);
}

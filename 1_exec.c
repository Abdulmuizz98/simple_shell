#include "main.h"
/**
 * main - a shell program
 * @ac: the number of arguments passed.
 * @av: array of arguments.
 *
 * Return: 0 if successful, 1 on EOF, Otherwise 1.
 */
int main(int ac, char **av)
{
	ssize_t nread;
	size_t len = 0;
	char **argv;
	char *line, *nline;
	pid_t child_pid;
	int i;

	for (i = 0; ; i++)
	{
		putprompt();
		nread = getline(&nline, &len, stdin);
		if (nread == -1)
			break;
		line = commandline(nline, nread);
		argv = split_string_words(line);
		child_pid = fork();
		if (child_pid == -1)
		{
			perror(av[0]);
			exit(1);
		}
		if (child_pid == 0)
		{
			if (_strlen(line) == 0)
				exit(1);
			if (execve(argv[0], argv, NULL) == -1)
				perror(av[0]);
			free(line);
			free(nline);
			free(argv);
			exit(1);
		}
		else
		{
			wait(NULL);
		}
	}
	exit(1);
}

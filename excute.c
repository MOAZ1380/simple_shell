#include "main.h"
/**
 * execute - mo
 * @argv: m
 * Return: moaz
*/
void execute(char **argv)
{
	char *command = NULL, *actual_command = NULL;

	if (argv)
	{
		pid_t pid = fork();

		command = argv[0];

		actual_command = location(command);
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execve(actual_command, argv, NULL) == -1)
			{
				perror("Error:");
				exit(EXIT_FAILURE);
			}

		}
		else
		{
			int status;

			wait(&status);
		}
	}
}

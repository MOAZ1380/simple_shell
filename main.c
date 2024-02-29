#include "main.h"
/**
 * tokenize_input - mo
 * @buff_prompt: m
 * @num_tokens: mo
 * Return: mo
*/
char **tokenize_input(char *buff_prompt, int *num_tokens);
/**
 * main - moaz
 * @argc: mo
 * @argv: mo
 * Return: mo
*/
int main(int argc, char **argv)
{
	char *prompt = "#cisfun$ ";
	char *buff_prompt = NULL;
	char *buffcopy_prompt = NULL;
	int num_tokens = 0;
	int i;
	size_t n = 0;
	ssize_t nchars_read;

	(void)argc;

	while (1)
	{
	printf("%s", prompt);
	nchars_read = getline(&buff_prompt, &n, stdin);
		if (nchars_read == -1)
		{
			exit(EXIT_FAILURE);
		}
			buffcopy_prompt = malloc(sizeof(char) * nchars_read);
			if (buffcopy_prompt == NULL)
			{
				perror("malloc  error");
				return (-1);
			}
		strcpy(buffcopy_prompt, buff_prompt);
		argv = tokenize_input(buff_prompt, &num_tokens);
		if (strcmp(argv[0], "exit") == 0)
		{
			exit(EXIT_FAILURE);
		}
		else if (strcmp(argv[0], "env") == 0)
		{
			print_environment();
		}

		execute(argv);
		for (i = 0; i < num_tokens; i++)
			free(argv[i]);
		free(argv);
			free(buffcopy_prompt);
	}
	free(buff_prompt);
	return (0);
}
/**
 * tokenize_input - moa
 * @buff_prompt: mo
 * @num_tokens: mo
 * Return: mo
*/
char **tokenize_input(char *buff_prompt, int *num_tokens)
{
	const char *delim = " \n";
	char *token;
	int i;
	char **argv;

	token = strtok(buff_prompt, delim);
	*num_tokens = 0;
	while (token != NULL)
	{
		(*num_tokens)++;
		token = strtok(NULL, delim);
	}
	argv = malloc(sizeof(char *) * (*num_tokens + 1));
	if (argv == NULL)
	{
		perror("malloc  error");
		exit(EXIT_FAILURE);
	}
	token = strtok(buff_prompt, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (argv[i] == NULL)
		{
			perror("malloc  error");
			exit(EXIT_FAILURE);
		}
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	return (argv);
}

#include "main.h"
/**
 * main - moaz
 * @argc: moaz
 * @argv: moa
 * Return: mo
*/

int main(int argc, char **argv)
{

	char* prompt = "(Eshell) $ ";
	char* buff_prompt = NULL;
	char* buffcopy_prompt = NULL;
	const char* delim = " \n";
	char* token;
	int num_tokens = 0;
	int i;
	size_t n = 0;
	ssize_t nchars_read;
	(void)argc;
	/* char **argv = NULL;**/
	while(1)
	{
	printf("%s", prompt);
	nchars_read = getline(&buff_prompt, &n, stdin);
		if (nchars_read == -1)
		{
			printf("Exiting shell....\n");
			break;
		}
			buffcopy_prompt = malloc(sizeof(char) * nchars_read);
			if (buffcopy_prompt == NULL)
			{
				perror("malloc  error");
				return (-1);
			}
		strcpy(buffcopy_prompt, buff_prompt);
		token = strtok(buff_prompt, delim);
		while(token != NULL)
		{
		num_tokens++;
		token = strtok(NULL, delim);
		}
		num_tokens++;
		argv = malloc(sizeof(char*) * num_tokens);
		token = strtok(buffcopy_prompt, delim);
		for(i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token + 1));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		if(strcmp(argv[0], "exit") == 0)
		{
			printf("Exiting shell....\n");
			break;
		}
		else if(strcmp(argv[0], "env") == 0)
		{
			for (char **env = environ; *env != NULL; env++)
			{
				printf("%s\n", *env);
			}
		}

		execute(argv);
		for(i = 0; i < num_tokens; i++)
			free(argv[i]);
		free(argv);
			free(buffcopy_prompt);
	}
	free(buff_prompt);
	return (0);
}

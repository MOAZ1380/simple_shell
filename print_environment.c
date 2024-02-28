#include "main.h"
#include <unistd.h>
/**
 * print_environment -mo
*/

void print_environment(void)
{
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
}

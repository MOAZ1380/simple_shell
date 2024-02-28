#include "main.h"
#include <unistd.h>
/**
 * print_environment -mo
*/

void print_environment(void)
{
	for (char **env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
}

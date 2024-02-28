#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * _getenv - mo
 * @name: mo
 * Return: mo
*/
char *_getenv(const char *name)
{
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		char *equal_pos = strchr(*env, '=');

		if (equal_pos != NULL)
		{
			size_t name_length = equal_pos - *env;

			if (strncmp(*env, name, name_length) == 0 && name[name_length] == '\0')
				return (equal_pos + 1);
		}
	}
	return (NULL);
}

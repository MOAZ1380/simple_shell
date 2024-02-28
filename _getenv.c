#include "main.h"
/**
 * _getenv - mo
 * @name: mo
 * Return: mo
*/
extern char **environ;
char *_getenv(const char *name)
{
	for (char **env = environ; *env != NULL; env++)
	{
		char *equal_pos = strchr(*env, '=');

		if (equal_pos != NULL)
		{
			size_t name_length = equal_pos - *env;

			if (strncmp(*env, name, name_length) == 0 && name[name_length] == '\0')
				return (qual_pos + 1)
		}
	}
}
return (NULL);
}

#include "main.h"

/**
 * _strcmp - mo
 * @s1: mo
 * @s2: mo
 * Return: mo
*/
int _strcmp(char *s1, char *s2)
{
		while (*s1 && *s2)
				{
							if (*s1 != *s2)
											return (*s1 - *s2);

									s1++;
											s2++;
												}
			return (0);
}
/**
 * _strcpy - mo
 * @dest: mo
 * @src: ,
 * Return: moa
*/
char *_strcpy(char *dest, char *src)
{
		char *c = dest;

			while (*src != '\0')
					{
								*dest = *src;
										dest++;
												src++;
													}
				*dest = '\0';
					return (c);
}
/**
 * _strcat - moaz
 * @dest: mo
 * @src: mo
 * Return: mo
*/
char *_strcat(char *dest, char *src)
{
		int a, b;

			for (a = 0; dest[a] != '\0'; a += 1)
					{}

				for (b = 0; src[b] != '\0'; b += 1)
						{
									dest[a] = src[b];
											a++;
												}
					dest[a] = '\0';
						return (dest);
}

/**
 * _strlen - mo
 * @s: mo
 * Return: mo
*/
int _strlen(char *s)
{
		int i = 0;

			while (s[i] != '\0')
					i++;

	return (i);
}

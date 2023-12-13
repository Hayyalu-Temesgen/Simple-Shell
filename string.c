#include "shell.h"

/**
 * _strlen - this function will return the length of a string
 * @s: the string
 * Return: will return the integer length of string
 */

int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - this function will perform comparison of two strangs.
 * @s1: the first strang
 * @s2: the second strang
 * Return: will return -ve if s1 < s2, +ve if s1 > s2, 0 if s1 == s2
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
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - this function will check if needle starts with haystack
 * @haystack: the string to search
 * @needle: the substring to find
 * Return: will return the address of next char of haystack or NULL
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - this function will concatenate two strings
 * @dest: the destination buffer
 * @src: the source buffer
 * Return: will return the pointer to destination buffer
 */

char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}


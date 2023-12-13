#include "shell.h"

/**
 *_errputs - this function will print an input string
 * @str: the string
 * Return: will return nothing
 */

void _errputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_errputchar(str[i]);
		i++;
	}
}

/**
 * _errputchar - this function will write the character c to stderr
 * @c: The character
 * Return: will return 1 on success, -1 on error
 */

int _errputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfdesc - this function will write the character c to given fd
 * @c: The character
 * @fd: The filedescriptor to write to
 * Return: will return 1 on success, -1 on error
 */

int _putfdesc(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 *_putsfdesc - this function will print an input string
 * @str: the string
 * @fd: the filedescriptor to write to
 * Return: will return the number
 */

int _putsfdesc(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}


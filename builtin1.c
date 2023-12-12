#include "shell.h"

/**
 * my_history - this function displays the history list
 * @info: Structure containing potential arguments
 *  Return: will always return 0
 */

int my_history(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * alias_unset - this function sets alias
 * @info: the parameter
 * @str: the string
 * Return: will always return 0
 */

int alias_unset(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
	get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * alias_set - this function sets alias to string
 * @info: the parameter
 * @str: the string
 * Return: will always return 0
 */

int alias_set(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (alias_unset(info, str));

	alias_unset(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - this function will print an alias
 * @node: the node
 * Return: will always return 0
 */

int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * my_alias - this functio will mimic the man alias
 * @info: Structure containing potential arguments
 *  Return: will always return 0
 */

int my_alias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}
	return (0);
}


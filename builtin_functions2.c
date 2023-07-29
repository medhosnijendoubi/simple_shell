#include "shell.h"

/**
 * _myhistory - function that displays the history list, one command by line,
 *              with line numbers, starting at 0.
 * @info: structure containing potential arguments.that used to maintain
 *        constant function prototype.
 * Return: Always zero
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - function that sets alias to string
 * @info: is a parameter struct
 * @str: he is a string alias
 *
 * Return: Always zero on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *p, k;
	int test;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	k = *p;
	*p = 0;
	test = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = k;
	return (test);
}

/**
 * set_alias - function that sets alias to string
 * @info: is a parameter struct
 * @str: is an string alias
 *
 * Return: Always 0 on success, or 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - function that prints an alias string
 * @node: is an alias node
 *
 * Return: Always zero on success, 1 on error
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
 * _myalias - function used to mimics the alias builtin (man alias)
 * @info: is a structure containing potential arguments. that used to maintain
 *          constant function prototype.
 * Return: Always zero
 */
int _myalias(info_t *info)
{
	int j = 0;
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
	for (j = 1; info->argv[j]; j++)
	{
		p = _strchr(info->argv[j], '=');
		if (p)
			set_alias(info, info->argv[j]);
		else
			print_alias(node_starts_with(info->alias, info->argv[j], '='));
	}

	return (0);
}


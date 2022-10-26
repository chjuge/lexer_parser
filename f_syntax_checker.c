/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_syntax_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:31:57 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/26 19:21:42 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

char	*to_str(int i)
{
	if (i == REDLINT)
		return ("<");
	if (i == REDLLINT)
		return ("<<");
	if (i == REDGINT)
		return (">");
	if (i == REDGGINT)
		return (">>");
	return ("|");
}

void	print_parse_error(char *s)
{
	printf("parse error near `%s'\n", s);
}

int	check_last(t_token *t)
{
	if (!(t->next) && t->type != WORDINT)
	{
		print_parse_error(to_str(t->type));
		return (ERR);
	}
	return (OK);
}

int	check_current(t_token *prev, t_token *curr)
{
	if (prev->type == WORDINT)
		return (OK);
	if (prev->type == PIPEINT)
	{
		if (curr->type == PIPEINT)
		{
			print_parse_error(to_str(PIPEINT));
			return (ERR);
		}
	}
	if (curr->type != WORDINT)
	{
		print_parse_error(to_str(curr->type));
		return (ERR);
	}
	return (OK);
}

int	syntax_checker(t_token *t)
{
	t_token	*prev;

	if (!t)
		return (OK);
	if (t->type == PIPEINT)
	{
		print_parse_error(to_str(PIPEINT));
		return (ERR);
	}
	prev = t;
	t = t->next;
	while (t)
	{
		if (check_current(prev, t) == ERR)
			return (ERR);
		prev = t;
		t = t->next;
	}
	if (check_last(prev) == ERR)
		return (ERR);
	return (OK);
}

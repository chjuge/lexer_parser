/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_syntax_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:31:57 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/11 19:14:36 by mproveme         ###   ########.fr       */
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
	exit(1);
}

void	check_last(t_token *t)
{
	if (!(t->next) && t->type != WORDINT)
		print_parse_error(to_str(t->type));
}

void	check_current(t_token *prev, t_token *curr)
{
	if (prev->type == WORDINT)
		return ;
	if (prev->type == PIPEINT)
	{
		if (curr->type == PIPEINT)
			print_parse_error(to_str(PIPEINT));
	}
	else
	{
		if (curr->type != WORDINT)
			print_parse_error(to_str(curr->type));
	}
}

void	syntax_checker(t_token *t)
{
	t_token	*prev;

	if (!t)
		return ;
	if (t->type == PIPEINT)
		print_parse_error(to_str(PIPEINT));
	prev = t;
	t = t->next;
	while (t)
	{
		check_current(prev, t);
		prev = t;
		t = t->next;
	}
	check_last(prev);
}

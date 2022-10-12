/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_token_by_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:13:05 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/12 16:07:59 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

void	token_word(t_token *t, int *i)
{
	int	type;

	type = check_sp_ch((t->ptr)[0]);
	while (type == WORDINT)
	{
		(t->len)++;
		(*i)++;
		type = check_sp_ch(t->ptr[t->len]);
	}
}

void	token_quo(t_token *t, int *i, char ch)
{
	char	*ptr;

	(*i)++;
	(t->ptr)++;
	ptr = t->ptr;
	while (ptr[0] != ch && ptr[0] != ENDL)
	{
		(*i)++;
		(t->len)++;
		ptr++;
	}
	if (ptr[0] == ENDL)
	{
		printf("Input error. There are no second quote.\n");
		exit(1);
	}
	(*i)++;
}

void	token_red(t_token *t, int *i)
{
	(*i)++;
	if (t->type == REDGINT)
	{
		if (t->ptr[1] == REDG)
		{
			(*i)++;
			t->type = REDGGINT;
		}
	}
	else if (t->type == REDLINT)
	{
		if (t->ptr[1] == REDL)
		{
			(*i)++;
			t->type = REDLLINT;
		}
	}
}

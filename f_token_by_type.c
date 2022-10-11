/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_token_by_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:13:05 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/11 19:16:10 by mproveme         ###   ########.fr       */
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

void	token_del(t_token *t, int *i)
{
	(t->len)++;
	(*i)++;
}

void	token_pipe(t_token *t, int *i)
{
	(t->len)++;
	(*i)++;	
}

void	token_quo(t_token *t, int *i)
{
	char	*ptr;

	(*i)++;
	(t->ptr)++;
	ptr = t->ptr;
	while (ptr[0] != QUO && ptr[0] != ENDL)
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

void	token_dquo(t_token *t, int *i)
{
	char	*ptr;

	(*i)++;
	(t->ptr)++;
	ptr = t->ptr;
	while (ptr[0] != DQUO && ptr[0] != ENDL)
	{
		(*i)++;
		(t->len)++;
		ptr++;
	}
	if (ptr[0] == ENDL)
	{
		printf("Input error. There are no second double quote.\n");
		exit(1);
	}
	(*i)++;
}

void	token_redg(t_token *t, int *i)
{
	(*i)++;
	(t->len)++;
	if (t->ptr[t->len] == REDG)
	{
		(*i)++;
		(t->len)++;
		t->type = REDGGINT;
	}
}

void	token_redl(t_token *t, int *i)
{
	(*i)++;
	(t->len)++;
	if (t->ptr[t->len] == REDL)
	{
		(*i)++;
		(t->len)++;
		t->type = REDLLINT;
	}
}

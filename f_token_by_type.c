/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_by_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:13:05 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/09 17:48:08 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

void	token_word(t_token *t, int *i)
{
	// printf("--> in token_word\n");
	int	type;

	// (t->len)++;
	// (*i)++;
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
	// printf("--> in token_del\n");
	(t->len)++;
	(*i)++;
}

void	token_pipe(t_token *t, int *i)
{
	// printf("--> in token_pipe\n");
	(t->len)++;
	(*i)++;	
}

void	token_quo(t_token *t, int *i)
{
	char	*ptr;

	// printf("--> in token_quo\n");
	(*i)++;
	(t->ptr)++;
	// printf("drop before if for while\n");
	ptr = t->ptr;
	while (ptr[0] != QUO && ptr[0] != ENDL)
	{
		(*i)++;
		(t->len)++;
		// printf ("len	%d	ptr	%p	char	%c\n", t->len, t->ptr, ptr[0]);
		ptr++;
		// usleep(100000*3);
	}
	// printf("drop before if for ENDL\n");
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

	// printf("--> in token_dquo\n");
	(*i)++;
	(t->ptr)++;
	ptr = t->ptr;
	while (ptr[0] != DQUO && ptr[0] != ENDL)
	{
		(*i)++;
		(t->len)++;
		// printf ("len	%d	ptr	%p	char	%c\n", t->len, t->ptr, ptr[0]);
		ptr++;
		// usleep(100000*3);
	}
	// printf("drop before if for ENDL\n");
	if (ptr[0] == ENDL)
	{
		printf("Input error. There are no second double quote.\n");
		exit(1);
	}
	(*i)++;
}

void	token_redg(t_token *t, int *i)
{
	// printf("--> in token_redg\n");
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
	// printf("--> in token_redl\n");
	(*i)++;
	(t->len)++;
	if (t->ptr[t->len] == REDL)
	{
		(*i)++;
		(t->len)++;
		t->type = REDLLINT;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_create_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:50:05 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/11 18:55:45 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

int	check_sp_ch(char c)
{
	if (c == QUO)
		return (QUOINT);
	else if (c == DQUO)
		return (DQUOINT);
	else if (c == PIPE)
		return (PIPEINT);
	else if (c == DEL)
		return (DELINT);
	else if (c == REDG)
		return (REDGINT);
	else if (c == REDL)
		return (REDLINT);
	else if (c == ENDL)
		return (-1);
	return (WORDINT);
}

void	token_by_type(t_token *t, int *i)
{
	if (t->type == WORDINT)
		token_word(t, i);
	else if (t->type == DELINT)
		token_del(t, i);
	else if (t->type == PIPEINT)
		token_pipe(t, i);
	else if (t->type == QUOINT)
		token_quo(t, i);
	else if (t->type == DQUOINT)
		token_dquo(t, i);
	else if (t->type == REDGINT)
		token_redg(t, i);
	else if (t->type == REDLINT)
		token_redl(t, i);
	else
	{
		printf("Something got wrong! No right token\n");
		exit(1);
	}
}

t_token	*create_token(char *ptr, int *i)
{
	t_token	*new_token;

	new_token = init_token();
	new_token->ptr = ptr;
	new_token->type = check_sp_ch(ptr[0]);
	token_by_type(new_token, i);
	return (new_token);
}

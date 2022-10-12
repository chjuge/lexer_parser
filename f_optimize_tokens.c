/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_optimize_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:11:26 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/12 17:58:20 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

void	delite_next_token(t_token *curr, t_token *next)
{
	curr->next = next->next;
	free_token(next);
}

void	delite_curr_token(t_token *curr, t_token *prev)
{
	prev->next = curr->next;
	free_token(curr);
}

t_token	*skip_to_delims(t_token *tmp, t_token **prev)
{
	while (tmp && tmp->type != DELINT)
	{
		*prev = tmp;
		tmp = tmp->next;
	}
	return (tmp);
}

void	delete_delims(t_token **tmp, t_token *prev, t_token **t)
{
	t_token *curr;
	t_token	*ti;

	ti = *tmp;
	while (ti && ti->type == DELINT)
	{
		curr = ti;
		ti = ti->next;
		if (prev)
			delite_curr_token(curr, prev);
		else
		{
			*tmp = ti;
			*t = *tmp;
			free_token(curr);
		}
	}
	*tmp = ti;
}

void	optimize_delims(t_token **t)
{
	t_token	*tmp;
	t_token	*prev;

	tmp = *t;
	prev = NULL;
	while (tmp)
	{
		tmp = skip_to_delims(tmp, &prev);
		if (!tmp)
			break ;
		delete_delims(&tmp, prev, t);
		if (tmp)
		{
			prev = tmp;
			tmp = tmp->next;
		}
	}
}

void	token_cat(t_token *curr, t_token *next)
{
	char	*new_s;
	int		len;

	len = curr->len + next->len;
	if (next->len > 0)
	{
		new_s = malloc (len + 1);
		new_s[len] = ENDL;
		ft_strcpy(new_s, curr->content, curr->len);
		ft_strcpy(new_s + curr->len, next->content, next->len);
		free(curr->content);
		curr->content = new_s;
		curr->len = len;
	}
}

void	optimize_words(t_token *t)
{
	while (t)
	{
		while (t && t->type != WORDINT)
			t = t->next;
		if (!t)
			break ;
		while (t->next && t->next->type == WORDINT)
		{
			token_cat(t, t->next);
			delite_next_token(t, t->next);
		}
		t = t->next;
	}
}

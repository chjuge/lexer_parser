/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:11:26 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/08 19:01:08 by mproveme         ###   ########.fr       */
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

void	optimize_delims(t_token **t)
{
	t_token	*tmp;
	t_token	*prev;
	t_token	*curr;

	tmp = *t;
	prev = NULL;
	while (tmp)
	{
		while (tmp && tmp->type != DELINT)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (!t)
			break ;
		while (tmp && tmp->type == DELINT)
		{
			curr = tmp;
			tmp = tmp->next;
			if (prev)
				delite_curr_token(curr, prev);
			else
			{
				*t = tmp;
				free_token(curr);
			}
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

void	token_cat(t_token *curr, t_token *next)
{
	char	*new_s;

	if (next->len > 0)
	{
		new_s = malloc (curr->len + next->len + 1);
		ft_strlcat(new_s, curr->content, curr->len + 1);
		ft_strlcat(new_s, next->content, next->len);
		free(curr->content);
		curr->content = new_s;
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
		while (t && t->next->type == WORDINT)
		{
			token_cat(t, t->next);
			delite__next_token(t, t->next);
		}
		t = t->next;
	}
}
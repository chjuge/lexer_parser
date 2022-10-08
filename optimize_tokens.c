/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:11:26 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/08 16:24:40 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

void	delite_token(t_token *curr, t_token *next)
{
	curr->next = next->next;
	free_token(next);
}

void	optimize_delims(t_token *t)
{
	while (t)
	{
		while (t && t->type != DELINT)
			t = t->next;
		if (!t)
			break ;
		while (t && t->next->type == DELINT)
			delite_token(t, t->next);
		t = t->next;
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
			delite_token(t, t->next);
		}
		t = t->next;
	}
}
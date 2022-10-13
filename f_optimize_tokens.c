/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_optimize_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:11:26 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/13 14:44:41 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

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

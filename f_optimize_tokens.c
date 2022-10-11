/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_optimize_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:11:26 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/11 15:52:37 by mproveme         ###   ########.fr       */
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
			tmp = tmp->next; //null
			if (prev)
				delite_curr_token(curr, prev);
			else
			{
				*t = tmp;
				free_token(curr);
			}
		}
		// printf("padaet\n");
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
		// ft_strlcat(new_s, curr->content, len + 1);
		// printf("curr, len	%d	%s\n", curr->len, curr->content);
		// printf("next, len	%d	%s\n", next->len, next->content);
		ft_strcpy(new_s, curr->content, curr->len);
		// printf("novaya stroka (1)---> %s\n", new_s);
		// ft_strlcat(new_s, next->content, len + 1);
		ft_strcpy(new_s + curr->len, next->content, next->len);
		printf("novaya stroka ---> %s\n", new_s);
		free(curr->content);
		curr->content = new_s;
		curr->len = len;
	}
}

void	optimize_words(t_token *t)
{
	// int i = 0;
	while (t)
	{
		while (t && t->type != WORDINT)
			t = t->next;
		if (!t)
			break ;
		while (t->next && t->next->type == WORDINT)
		{
			// printf("in cycle %d\n", ++i);
			token_cat(t, t->next);
			delite_next_token(t, t->next);
		}
		t = t->next;
	}
}

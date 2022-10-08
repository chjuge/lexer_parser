/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:11:26 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/08 15:27:52 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

void	delit_del(t_token *curr, t_token *next)
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
			delite_del(t, t->next);
		t = t->next;
	}
}

void	optimize_words(t_token *t)
{
	
}
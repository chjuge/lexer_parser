/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_word.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:02:07 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/12 16:59:46 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

t_word	*init_word(char	*content)
{
	t_word	*res;

	res = malloc(sizeof(t_word));
	res->next = NULL;
	res->word = ft_strdup(content);
	return (res);
}

t_word *word_last(t_word *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_back_word(t_word **lst, t_word *new)
{
	t_word	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	if (!tmp)
	{
		*lst = new;
		return ;
	}
	tmp = word_last(tmp);
	tmp->next = new;
}

void	free_word(t_word *t)
{
	if (t->word)
		free(t->word);
	free(t);
}

void	free_words_all(t_word *t)
{
	t_word	*tmp;

	if (t == NULL)
		return ;
	tmp = t;
	while (t)
	{
		tmp = t;
		t = t->next;
		free_word(tmp);
	}
}

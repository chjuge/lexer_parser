/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_red.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:02:07 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/11 19:22:16 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

t_red	*init_red(char	*content)
{
	t_red	*res;

	res = malloc(sizeof(t_red));
	res->next = NULL;
	res->word = ft_strdup(content);
	return (res);
}

t_red *red_last(t_red *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_back_red(t_red **lst, t_red *new)
{
	t_red	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	if (!tmp)
	{
		*lst = new;
		return ;
	}
	tmp = red_last(tmp);
	tmp->next = new;
}

void	free_red(t_red *t)
{
	if (t->word)
		free(t->word);
	free(t);
}

void	free_reds_all(t_red *t)
{
	t_red	*tmp;

	tmp = t;
	while (t)
	{
		tmp = t;
		t = t->next;
		free_red(tmp);
	}
}

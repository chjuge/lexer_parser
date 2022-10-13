/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_keysearch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:18:02 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/13 14:29:58 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

t_ks	*keysearch_last(t_ks *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_back_keysearch(t_ks **lst, t_ks *new)
{
	t_ks	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	if (!tmp)
	{
		*lst = new;
		return ;
	}
	tmp = keysearch_last(tmp);
	tmp->next = new;
}

t_ks	*init_keysearch(void)
{
	t_ks	*new_el;

	new_el = malloc(sizeof(t_ks));
	new_el->ptr = NULL;
	new_el->next = NULL;
	new_el->key = NULL;
	new_el->value = NULL;
	new_el->len = 0;
	return (new_el);
}

void	free_keysearch(t_ks *t)
{
	t_ks	*tmp;

	while (t)
	{
		if (t->key)
			free(t->key);
		if (t->value)
			free(t->value);
		tmp = t;
		t = t->next;
		free(tmp);
	}
}

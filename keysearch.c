/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keysearch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:18:02 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/06 14:20:02 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

t_keysearch	*keysearch_last(t_keysearch *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_back_keysearch(t_keysearch **lst, t_keysearch *new)
{
	t_keysearch	*tmp;

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

t_keysearch	*init_keysearch(void)
{
	t_keysearch	*new_el;

	new_el = malloc(sizeof(t_keysearch));
	new_el->ptr = NULL;
	new_el->next = NULL;
	new_el->key = NULL;
	new_el->value = NULL;
	new_el->len = 0;
	return (new_el);
}

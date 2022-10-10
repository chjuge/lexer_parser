/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:15:36 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/06 14:17:58 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

t_group	*group_last(t_group *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_back_group(t_group **lst, t_group *new)
{
	t_group	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	if (!tmp)
	{
		*lst = new;
		return ;
	}
	tmp = group_last(tmp);
	tmp->next = new;
}

t_group	*init_group(void)
{
	t_group	*new_el;

	new_el = malloc(sizeof(t_group));
	new_el->g = NULL;
	new_el->next = NULL;
	return (new_el);
}

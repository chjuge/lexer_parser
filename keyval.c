/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyval.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:33:52 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/06 13:26:04 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

t_keyval	*init_keyval(void)
{
	t_keyval	*new_el;

	new_el = malloc(sizeof(t_keyval));
	new_el->next = NULL;
	new_el->key = NULL;
	new_el->val = NULL;
	new_el->len_k = 0;
	new_el->len_v = 0;
	return(new_el);
}

t_keyval	*ft_lstlast(t_keyval *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_back_keyval(t_keyval **lst, t_keyval *new)
{
	t_keyval	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	if (!tmp)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(tmp);
	tmp->next = new;
}

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyval.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:33:52 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/05 19:00:47 by mproveme         ###   ########.fr       */
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
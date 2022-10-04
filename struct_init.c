/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:16:46 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/04 13:44:16 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

t_token	*init_token(void)
{
	t_token	*res;

	res = malloc(sizeof(t_token));
	res->next = NULL;
	res->type = 0;
	res->len = 0;
	res->ptr = NULL;
	res->str = NULL;
	return (res);
}

t_token	*ft_lstlast(t_token *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_token **lst, t_token *new)
{
	t_token	*tmp;

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
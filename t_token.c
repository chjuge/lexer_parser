/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:16:46 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/08 15:31:19 by mproveme         ###   ########.fr       */
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
	res->content = NULL;
	return (res);
}

t_token	*token_last(t_token *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_back_token(t_token **lst, t_token *new)
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
	tmp = token_last(tmp);
	tmp->next = new;
}

void	free_token(t_token *t)
{
	if (t->content)
		free(t->content);
	free(t);
}

void	free_tokens_all(t_token *t)
{
	t_token	*tmp;

	tmp = t;
	while (t)
	{
		tmp = t;
		t = t->next;
		free_token(tmp);
	}
}

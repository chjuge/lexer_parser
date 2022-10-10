/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_param.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:06:49 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/10 16:13:16 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

t_param	*init_param(char *s)
{
	t_param	*res;

	res = malloc(sizeof(t_param));
	res->next = NULL;
	res->content = ft_strdup(s);
	return (res);
}

t_param *param_last(t_param *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_back_param(t_param **lst, t_param *new)
{
	t_param	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	if (!tmp)
	{
		*lst = new;
		return ;
	}
	tmp = param_last(tmp);
	tmp->next = new;
}

void	free_param(t_param *t)
{
	if (t->content)
		free(t->content);
	free(t);
}

void	free_params_all(t_param *t)
{
	t_param	*tmp;

	tmp = t;
	while (t)
	{
		tmp = t;
		t = t->next;
		free_param(tmp);
	}
}

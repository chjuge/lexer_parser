/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:08:18 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/10 16:27:32 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

t_cmd	*init_cmd(void)
{
	t_cmd	*res;

	res = malloc(sizeof(t_cmd));
	res->cmd = NULL;
	res->red_g = NULL;
	res->red_gg = NULL;
	res->red_l = NULL;
	res->red_ll = NULL;
	res->next = NULL;
	return (res);
}

t_cmd	*cmd_last(t_cmd *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_back_cmd(t_cmd **lst, t_cmd *new)
{
	t_cmd	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	if (!tmp)
	{
		*lst = new;
		return ;
	}
	tmp = cmd_last(tmp);
	tmp->next = new;
}

void	free_cmd(t_cmd *t)
{
	(void)t;
	// TODO
}

void	free_cmds_all(t_cmd *t)
{
	t_cmd	*tmp;

	tmp = t;
	while (t)
	{
		tmp = t;
		t = t->next;
		free_cmd(tmp);
	}
}

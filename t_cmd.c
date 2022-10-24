/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:08:18 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/21 18:23:22 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

t_cmd	*init_cmd(void)
{
	t_cmd	*res;

	res = malloc(sizeof(t_cmd));
	res->cmd = NULL;
	res->red = NULL;
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

void	free_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	if (cmd->cmd)
		free(cmd->cmd);
	free_reds_all(cmd->red);
	free_array((cmd->args));
	free(cmd);
}

void	free_cmds_all(t_cmd *t)
{
	t_cmd	*tmp;
	t_cmd	*prev;

	tmp = t;
	while (tmp)
	{
		prev = tmp;
		tmp = tmp->next;
		free_cmd(prev);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:08:18 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/12 14:32:55 by mproveme         ###   ########.fr       */
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

void	free_cmd(t_cmd *cmd)
{
	while (cmd)
	{
		if (cmd->cmd)
			free(cmd->cmd);
		free_reds_all(cmd->red_g);
		free_reds_all(cmd->red_gg);
		free_reds_all(cmd->red_l);
		free_reds_all(cmd->red_ll);
		free_array((cmd->args));
		cmd = cmd->next;
	}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:08:18 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/11 17:24:35 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

t_cmd	*init_cmd(void)
{
	t_cmd	*res;

	res = malloc(sizeof(t_cmd));
	res->cmd = NULL;
	// res->params = NULL;
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

void	print_all_red(t_red *r)
{
	if (!r)
		printf("%s\n", (char*)NULL);
	else
	{
		while (r)
		{
			printf("%s\n", r->word);
			r = r->next;
		}
	}
}

void	read_cmd(t_cmd *cmd)
{
	printf("the command:	%s\n", cmd->cmd);
	printf("args array:\n");
	while (*(cmd->args))
	{
		usleep(10000);
		printf("%s\n", *(cmd->args));
		(cmd->args)++;
	}
	printf("------\n");
	printf("red_g: \n");
	print_all_red(cmd->red_g);
	printf("red_gg: \n");
	print_all_red(cmd->red_gg);
	printf("red_l: \n");
	print_all_red(cmd->red_l);
	printf("red_ll: \n");
	print_all_red(cmd->red_ll);
}

void	read_cmds_all(t_cmd *cmd)
{
	while (cmd)
	{
		usleep(10000);
		read_cmd(cmd);
		cmd = cmd->next;
	}
}
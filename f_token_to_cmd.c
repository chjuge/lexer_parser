/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_token_to_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:34:48 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/10 19:15:29 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

void	rewrite_red(char **old, char *new)
{
	if (*old)
		free(*old);
	(*old) = ft_strdup(new);	
}

void	add_red_to_cmd(t_cmd *cmd, int flag, char *content)
{
	if (flag == REDGINT)
		// cmd->red_g = str;
		rewrite_red(&(cmd->red_g), content);
	else if (flag == REDGGINT)
		// cmd->red_gg = str;
		rewrite_red(&(cmd->red_gg), content);
	else if (flag == REDLINT)
		// cmd->red_l = str;
		rewrite_red(&(cmd->red_l), content);
	else
		// cmd->red_ll = str;
		rewrite_red(&(cmd->red_ll), content);
}

t_cmd	*token_to_cmd(t_token *t)
{
	t_cmd	*cmd;
	t_cmd	*tmp;
	t_param	*tmp_p;
	int		flag_cmd;
	int		flag_red;

	flag_cmd = 0;
	flag_red = 0;
	cmd = NULL;
	tmp = init_cmd();
	while (t)
	{
		if (t->type == WORDINT)
		{
			if (flag_red == 0)
			{
				if (flag_cmd == 0)
				{
					flag_cmd = 1;
					tmp->cmd = ft_strdup(t->content);
				}
				else
				{
					tmp_p = init_param(t->content);
					add_back_param(&(cmd->params), tmp_p);
				}
			}
			else
			{
				add_red_to_cmd(tmp, flag_red, t->content);
				flag_red = 0;
			}
		}
		else if (t->type == PIPEINT)
		{
			//todo
			add_back_cmd(&cmd, tmp);
			tmp = init_cmd();
			flag_cmd = 0;
		}
		else
			flag_red = t->type;
		t = t->next;
	}
	add_back_cmd(&cmd, tmp);
	return (cmd);
}

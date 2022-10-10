/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_token_to_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:34:48 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/10 16:16:01 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

void	add_red_to_cmd(t_cmd *cmd, int flag)
{
	
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
				add_red_to_cmd(tmp, flag_red); //TODO
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

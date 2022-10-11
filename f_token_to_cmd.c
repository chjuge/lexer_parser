/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_token_to_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:34:48 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/11 19:17:56 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

void	rewrite_red(char **old, char *new)
{
	if (*old)
		free(*old);
	(*old) = ft_strdup(new);	
}

char	**parse_args(t_param	*p)
{
	int 	count;
	int		i;
	t_param	*tmp;
	char	**arr;

	tmp = p;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	arr = malloc(sizeof(char*) * (count + 1));
	i = 0;
	while (i < count)
	{
		arr[i] = ft_strdup(p->content);
		p = p->next;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

void	add_red_to_cmd(t_cmd *cmd, int flag, char *content)
{
	t_red	*tmp;

	tmp = init_red(content);
	if (flag == REDGINT)
		add_back_red(&(cmd->red_g), tmp);
	else if (flag == REDGGINT)
		add_back_red(&(cmd->red_gg), tmp);
	else if (flag == REDLINT)
		add_back_red(&(cmd->red_l), tmp);
	else
		add_back_red(&(cmd->red_ll), tmp);
}

t_cmd	*token_to_cmd(t_token *t)
{
	t_cmd	*cmd;
	t_cmd	*tmp;
	t_param	*tmp_p;
	t_param	*param;
	int		flag_red;

	flag_red = 0;
	cmd = NULL;
	tmp = init_cmd();
	param = NULL;
	while (t)
	{
		if (t->type == WORDINT)
		{
			if (flag_red == 0)
			{
				tmp_p = init_param(t->content);
				add_back_param(&param, tmp_p);
			}
			else
			{
				add_red_to_cmd(tmp, flag_red, t->content);
				flag_red = 0;
			}
		}
		else if (t->type == PIPEINT)
		{
			tmp->cmd = ft_strdup(param->content);
			tmp->args = parse_args(param);
			free_params_all(param);
			param = NULL;
			add_back_cmd(&cmd, tmp);
			tmp = init_cmd();
		}
		else
			flag_red = t->type;
		t = t->next;
	}
	tmp->cmd = ft_strdup(param->content);
	tmp->args = parse_args(param);
	add_back_cmd(&cmd, tmp);
	free_params_all(param);
	return (cmd);
}

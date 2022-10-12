/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_token_to_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:34:48 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/12 17:32:18 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

void	rewrite_red(char **old, char *new)
{
	if (*old)
		free(*old);
	(*old) = ft_strdup(new);	
}

int	find_count(t_word *tmp)
{
	int	count;

	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

char	**parse_args(t_word	*p)
{
	int 	count;
	int		i;
	char	**arr;

	count = find_count(p);
	arr = malloc(sizeof(char *) * (count + 1));
	arr[count] = NULL;
	i = 0;
	while (i < count)
	{
		arr[i] = ft_strdup(p->word);
		p = p->next;
		i++;
	}
	return (arr);
}

void	add_red_to_cmd(t_cmd *cmd, int flag, char *content)
{
	t_word	*tmp;

	tmp = init_word(content);
	if (flag == REDGINT)
		add_back_word(&(cmd->red_g), tmp);
	else if (flag == REDGGINT)
		add_back_word(&(cmd->red_gg), tmp);
	else if (flag == REDLINT)
		add_back_word(&(cmd->red_l), tmp);
	else
		add_back_word(&(cmd->red_ll), tmp);
}

t_cmd	*token_to_cmd(t_token *t)
{
	t_cmd	*cmd;
	t_cmd	*tmp;
	t_word	*tmp_p;
	t_word	*param;
	int		flag_red;

	if (!t)
		return (NULL);
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
				tmp_p = init_word(t->content);
				add_back_word(&param, tmp_p);
			}
			else
			{
				add_red_to_cmd(tmp, flag_red, t->content);
				flag_red = 0;
			}
		}
		else if (t->type == PIPEINT)
		{
			tmp->cmd = ft_strdup(param->word);
			tmp->args = parse_args(param);
			free_words_all(param);
			param = NULL;
			add_back_cmd(&cmd, tmp);
			tmp = init_cmd();
		}
		else
			flag_red = t->type;
		t = t->next;
	}
	tmp->cmd = ft_strdup(param->word);
	tmp->args = parse_args(param);
	add_back_cmd(&cmd, tmp);
	free_words_all(param);
	return (cmd);
}

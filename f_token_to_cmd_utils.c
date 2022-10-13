/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_token_to_cmd_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:34:48 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/13 14:38:28 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

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

void	add_red_to_cmd(t_cmd *cmd, int *flag, char *content)
{
	t_word	*tmp;

	tmp = init_word(content);
	if (*flag == REDGINT)
		add_back_word(&(cmd->red_g), tmp);
	else if (*flag == REDGGINT)
		add_back_word(&(cmd->red_gg), tmp);
	else if (*flag == REDLINT)
		add_back_word(&(cmd->red_l), tmp);
	else
		add_back_word(&(cmd->red_ll), tmp);
	*flag = 0;
}

void	init_and_add_back_word(t_word **head, char *str)
{
	t_word	*tmp;

	tmp = init_word(str);
	add_back_word(head, tmp);
}

void	end_of_cmd(t_cmd **cmd, t_cmd **tmp, t_word **param, t_token *t)
{
	(*tmp)->cmd = ft_strdup((*param)->word);
	(*tmp)->args = parse_args(*param);
	free_words_all(*param);
	*param = NULL;
	add_back_cmd(cmd, *tmp);
	if (t)
		(*tmp) = init_cmd();
}

void	init_base(t_cmd **cmd, t_cmd **tmp, int *flag, t_word **param)
{
	*flag = 0;
	*cmd = NULL;
	*tmp = init_cmd();
	*param = NULL;
}

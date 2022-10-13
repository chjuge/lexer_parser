/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_token_to_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:34:48 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/13 14:13:17 by mproveme         ###   ########.fr       */
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

void	init_and_add_back_word(t_word **head,char *str)
{
	t_word	*tmp;

	tmp = init_word(str);
	add_back_word(head, tmp);
}

void	end_of_cmd(t_cmd **cmd, t_cmd *tmp, t_word **param)
{
	tmp->cmd = ft_strdup((*param)->word);
	tmp->args = parse_args(*param);
	free_words_all(*param);
	*param = NULL;
	add_back_cmd(cmd, tmp);
}

void	init_base(t_cmd **cmd, t_cmd **tmp, int *flag, t_word **param)
{
	*flag = 0;
	*cmd = NULL;
	*tmp = init_cmd();
	*param = NULL;
}

// void	case_word(int flag, t_word **param, t_token *t, t_cmd *tmp)
// {
// 	if (flag == 0)
// 		init_and_add_back_word(param, t->content);
// 	else
// 		add_red_to_cmd(tmp, &flag, t->content);
// }

t_cmd	*token_to_cmd(t_token *t)
{
	t_cmd	*cmd;
	t_cmd	*tmp;
	t_word	*param;
	int		flag;

	if (!t)
		return (NULL);
	init_base(&cmd, &tmp, &flag, &param);
	while (t)
	{
		if (t->type == WORDINT)
		{
			if (flag == 0)
				init_and_add_back_word(&param, t->content);
			else
				add_red_to_cmd(tmp, &flag, t->content);
		}
		else if (t->type == PIPEINT)
		{
			end_of_cmd(&cmd, tmp, &param);
			tmp = init_cmd();
		}
		else
			flag = t->type;
		t = t->next;
	}
	end_of_cmd(&cmd, tmp, &param);
	return (cmd);
}

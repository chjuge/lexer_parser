/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_token_to_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:34:48 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/13 14:41:31 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

char	**parse_args(t_word	*p)
{
	int		count;
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
			end_of_cmd(&cmd, &tmp, &param, t);
		else
			flag = t->type;
		t = t->next;
	}
	end_of_cmd(&cmd, &tmp, &param, t);
	return (cmd);
}

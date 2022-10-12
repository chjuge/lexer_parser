/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_readers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:09:30 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/12 16:54:32 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

void	read_tokens(t_token *t)
{
	while (t)
	{
		printf("type	%d	len	%d	ptr	%p	content	'%s'	\n", t->type, t->len, t->ptr, t->content);
		t = t->next;
	}
}

void	read_env(t_env *env)
{
	while (env)
	{
		printf("key:	%s,	content:	%s\n", env->key, env->val);
		env = env->next;
	}
}

void	read_ks(t_keysearch *ks)
{
	while(ks)
	{
		printf("key:	%s,		value:	%s\n", ks->key, ks->value);
		ks = ks->next;
	}
}

void	read_red_all(t_word *r)
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
	int	i;

	i = 0;
	printf("the command:	%s\n", cmd->cmd);
	printf("args array:\n");
	while ((cmd->args)[i])
	{
		printf("%s\n", (cmd->args)[i]);
		i++;
	}
	printf("------\n");
	printf("red_g: \n");
	read_red_all(cmd->red_g);
	printf("red_gg: \n");
	read_red_all(cmd->red_gg);
	printf("red_l: \n");
	read_red_all(cmd->red_l);
	printf("red_ll: \n");
	read_red_all(cmd->red_ll);
}

void	read_cmds_all(t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp)
	{
		read_cmd(tmp);
		tmp = tmp->next;
	}
}

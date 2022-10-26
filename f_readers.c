/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_readers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:09:30 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/26 19:25:48 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

void	read_tokens(t_token *t)
{
	if (!t)
		printf("There are no tokens!\n");
	while (t)
	{
		printf("type	%d	len	%d	ptr	%p	content	'%s'	\n",
			t->type, t->len, t->ptr, t->content);
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

void	read_ks(t_ks *ks)
{
	while (ks)
	{
		printf("key:	%s,		value:	%s\n", ks->key, ks->value);
		ks = ks->next;
	}
}

void	read_red_all(t_red *r)
{
	if (!r)
		printf("%s\n", "NULL");
	else
	{
		while (r)
		{
			printf("%d	%s\n", r->type, r->word);
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
	printf("red: \n");
	read_red_all(cmd->red);
}

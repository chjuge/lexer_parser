/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_parser_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:37:58 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/13 14:56:05 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

void	get_kv(t_env *env, char *str)
{
	int	i;

	i = 0;
	i += get_substr(str, &(env->key), &(env->len_k), '=');
	i++;
	i += get_substr(str + i, &(env->val), &(env->len_v), ENDL);
}

t_env	*get_env(char **envp)
{
	t_env	*env;
	t_env	*tmp;

	env = NULL;
	while (envp && envp[0])
	{
		tmp = init_env();
		get_kv(tmp, *envp);
		add_back_env(&env, tmp);
		envp++;
	}
	return (env);
}

int	check_redefine(t_token *t)
{
	int		res;
	int		i;
	char	*str;

	res = 0;
	i = 0;
	str = t->content;
	while (str[i] != '$' && str[i] != ENDL)
		i++;
	if (str[i] == '$')
		res = 1;
	return (res);
}

void	redefine_dollar(t_token *t, char **envp)
{
	t_env	*env;

	env = get_env(envp);
	while (t != NULL)
	{
		if (t->type == WORDINT && check_redefine(t))
			redefine_full(t, env);
		t = t->next;
	}
	free_envs_all(env);
}

void	redefine_quo(t_token *t, int type)
{
	while (t)
	{
		if (t->type == type)
			t->type = WORDINT;
		t = t->next;
	}
}


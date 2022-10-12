/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:37:58 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/12 13:30:17 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

void	get_kv(t_env *kv, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=')
	{
		(kv->len_k)++;
		i++;
	}
	i++;
	while (str[i] != ENDL)
	{
		(kv->len_v)++;
		i++;
	}
	i = 0;
	kv->key = malloc(kv->len_k + 1);
	kv->val = malloc(kv->len_v + 1);
	kv->key[kv->len_k] = ENDL;
	kv->val[kv->len_v] = ENDL;
	while (str[i] != '=')
	{
		kv->key[i] = str[i];
		i++;
	}
	i++;
	while (str[i] != ENDL)
	{
		kv->val[i - 1 - kv->len_k] = str[i];
		i++;
	}
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

void	redefine_$(t_token *t, char **envp)
{
	t_env	*env;

	env = get_env(envp);
	while (t != NULL)
	{
		if (t->type == WORDINT && check_redefine(t))
			redefine_full(t, env);
		t = t->next;
	}
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

t_cmd	*parse_tokens(t_token *t, char **envp)
{
	t_cmd *cmd;

	redefine_quo(t, DQUOINT);
	redefine_$(t, envp);
	redefine_quo(t, QUOINT);
	optimize_words(t);
	optimize_delims(&t);
	syntax_checker(t);
	cmd = token_to_cmd(t);
	return (cmd);
}

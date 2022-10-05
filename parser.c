/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:37:58 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/05 19:17:01 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

void	redefine_dquo(t_token *t)
{
	if (t->type == DQUOINT)
		t->type = WORDINT;
	while (t->next)
	{
		t = t->next;
		if (t->type == DQUOINT)
			t->type = WORDINT;		
	}
}

void	get_kv(t_keyval *kv, char *str)
{
	int	len;
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

t_keyval	*get_env_keys(void)
{
	t_keyval	*env;
	t_keyval	*tmp;

	env = NULL;
	tmp = init_keyval();
	while (envp_g)
	{
		get_kv(tmp, *envp_g);
		add_back_keyval(env, tmp);
		envp_g++;
	}
	
}

void	redefine_$(t_token *t)
{
	t_keyval	*env;
	t_keyval	*lst;

	env = get_env_keys();
}
void	parse_tokens(t_token *t)
{
	redefine_dquo(t);
	redefine_$(t);
}
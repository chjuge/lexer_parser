/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_redefine_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:22:39 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/22 10:02:06 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

t_ks	*redefine_key(t_token *t)
{
	t_ks	*tmp;
	t_ks	*ks;
	int		i;

	ks = NULL;
	i = 0;
	if (t->content[0] != '$')
	{
		tmp = init_keysearch();
		i += get_substr(t->content, &(tmp->value), &(tmp->len), '$');
		add_back_keysearch(&ks, tmp);
	}
	i++;
	while (1)
	{
		tmp = init_keysearch();
		i += get_substr(t->content + i, &(tmp->key), &(tmp->len), '$');
		add_back_keysearch(&ks, tmp);
		if (t->content[i] == ENDL)
			break ;
		i++;
	}
	return (ks);
}

void	redefine_value(t_ks *ks, t_env *env, int flag)
{
	if (ks->value)
		free(ks->value);
	if (flag == 0)
	{
		ks->len = 0;
		ks->value = malloc(1);
		ks->value[0] = ENDL;
	}
	else
	{
		ks->len = env->len_v;
		ks->value = ft_strdup(env->val);
	}
}

void	parts_into_str(t_token *t, t_ks *ks)
{
	int		len;
	char	*str;
	t_ks	*tmp;

	len = 0;
	tmp = ks;
	while (tmp)
	{
		len += tmp->len;
		tmp = tmp->next;
	}
	str = malloc(len + 1);
	tmp = ks;
	while (tmp)
	{
		ft_strlcat(str, tmp->value, len + 1);
		tmp = tmp->next;
	}
	free(t->content);
	t->content = str;
	t->len = len;
}

t_env	*check_key(t_env *env, t_ks *tmp, int *flag)
{
	while (*flag == 0 && env)
	{
		if (tmp->len == env->len_k
			&& ft_strncmp(tmp->key, env->key, tmp->len) == 0)
		{
			*flag = 1;
			break ;
		}
		else
			env = env->next;
	}
	return (env);
}

void	redefine_full(t_token *t, t_env *envf)
{
	t_ks	*ks;
	t_ks	*tmp;
	int		flag;
	t_env	*env;

	ks = redefine_key(t);
	flag = 0;
	tmp = ks;
	if (tmp->key == NULL)
		tmp = tmp->next;
	while (tmp)
	{
		env = check_key(envf, tmp, &flag);
		redefine_value(tmp, env, flag);
		tmp = tmp->next;
	}
	parts_into_str(t, ks);
	free_keysearch(ks);
}

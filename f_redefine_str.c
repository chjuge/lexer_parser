/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_redefine_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:22:39 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/11 19:14:11 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

int	get_substr(char *src, char **dst, int *len, char ch)
{
	int		i;
	char	*s;

	i = 0;
	while (src[i] != ch && src[i] != ENDL)
		i++;
	if (i != 0)
	{
		s = malloc(i + 1);
		ft_strlcpy(s, src, i + 1);
		*len = i;
		*dst = s;
	}
	return (i);
}

t_keysearch	*redefine_key(t_token *t)
{
	t_keysearch	*tmp;
	t_keysearch	*ks;
	int			i;

	ks = NULL;
	i = 0;
	tmp = init_keysearch();
	if (t->content[0] != '$')
	{
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

void	redefine_value(t_keysearch *ks, t_env *env, int flag)
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

void	parts_into_str(t_token *t, t_keysearch *ks)
{
	int			len;
	char		*str;
	t_keysearch	*tmp;

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

void	redefine_full(t_token *t, t_env *envf)
{
	t_keysearch	*ks;
	t_keysearch	*tmp;
	int			flag;
	t_env		*env;

	ks = redefine_key(t);
	flag = 0;
	tmp = ks;
	if (tmp->key == NULL)
		tmp = tmp->next;
	while (tmp)
	{
		env = envf;
		while (flag == 0 && env)						
		{
			if (tmp->len == env->len_k && ft_strncmp(tmp->key, env->key, tmp->len) == 0)
			{
				flag = 1;
				break ;
			}
			else
				env = env->next;
		}
		redefine_value(tmp, env, flag);
		tmp = tmp->next;
		}
	parts_into_str(t, ks);
	free_keysearch(ks);
}

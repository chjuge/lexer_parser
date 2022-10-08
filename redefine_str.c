/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redefine_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:22:39 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/08 14:30:06 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

int	get_substr(char *src, char *dst, int *len, char ch)
{
	int	i;

	i = 0;
	while (src[i] != ch && src[i] != ENDL)
		i++;
	if (i != 0)
	{
		dst = malloc(i + 1);
		ft_strlcpy(dst, src, i + 1);
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
	i += get_substr(t->content, tmp->value, &(tmp->len), '$');
	add_back_keysearch(ks, tmp);
	i++;
	while (1)
	{
		tmp = init_keysearch();
		i += get_substr(t->content + i, tmp->key, &(tmp->len), '$');
		add_back_keysearch(ks, tmp);
		if (t->content[i] == ENDL)
			break ;
		i++;
	}
	return (ks);
}

void	redefine_value(t_keysearch *ks, t_keyval *env, int flag)
{
	if (ks->key)
		free(ks->key);
	if (ks->value)
		free(ks->value);
	if (flag == 0)
	{
		ks->len = 0;
		ks->key = NULL;
		ks->value = NULL;
		return ;
	}
	ks->value = ft_strdup(env->val);
	ks->len = env->len_v;
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
	str[len] = ENDL;
	tmp = ks;
	while (tmp)
	{
		ft_strlcat(str, tmp->value, len + 1);
		tmp = tmp->next;
	}
	free(t->content);
	t->content = str;
}

void	redefine_full(t_token *t, t_keyval *env)
{
	t_keysearch	*ks;
	int			flag;

	ks = redefine_key(t); // получили строку кусками
	flag = 0;
	if (ks->key == NULL)
		ks = ks->next;
	while (ks)
	{
		if (ft_strncmp(ks->key, env->key, ks->len) == 0) // если ключ в куске совпадает 
			flag = 1;									 // с ключом окружения
		while (!flag && env->next)						 // то ставим флаг на замену
		{
			env = env->next;
			if (ft_strncmp(ks->key, env->key, ks->len) == 0)
				flag = 1;
		}
		redefine_value(ks, env, flag);
		ks = ks->next;
	}
	parts_into_str(t, ks);
}
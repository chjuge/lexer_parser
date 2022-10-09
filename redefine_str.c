/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redefine_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:22:39 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/09 15:09:42 by mproveme         ###   ########.fr       */
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
	// printf("get_substr, i = %d\n", i);
	if (i != 0)
	{
		s = malloc(i + 1);
		ft_strlcpy(s, src, i + 1);
		*len = i;
		// printf("dst = %s\n", s);
		*dst = s;
	}
	return (i);
}

t_keysearch	*redefine_key(t_token *t) // делю строку на куски
{
	t_keysearch	*tmp;
	t_keysearch	*ks;
	int			i;

	ks = NULL;
	i = 0;
	// printf("token:	%s\n", t->content);
	tmp = init_keysearch();
	i += get_substr(t->content, &(tmp->value), &(tmp->len), '$');
	add_back_keysearch(&ks, tmp);
	// read_ks(ks);
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
	printf("in redefine_value\n");
	if (!env)
	{
		printf("env == NULL!!!\n");
		// exit(1);
	}
	if (ks->value)
		free(ks->value);
	printf("flag = %d\n", flag);
	if (flag == 0)
	{
		printf("1\n");
		ks->len = 0;
		printf("2\n");
		ks->value = malloc(1);
		printf("3\n");
		ks->value[0] = ENDL;
		printf("4\n");
		// printf("value of env:	%s\n", env->val);
		printf("new value of element: '%s'\n", ks->value);
		return ;
	}
	else
	{
		ks->len = env->len_v;
		ks->value = ft_strdup(env->val);
	}
	printf("5\n");
	printf("value of env:	%s\n", env->val);
	printf("new value of element: '%s'\n", ks->value);
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
}

void	redefine_full(t_token *t, t_env *envf)
{
	printf("voshel v -> redefine_full\n");
	t_keysearch	*ks;
	t_keysearch	*tmp;
	int			flag;
	t_env		*env;

	ks = redefine_key(t); // получили строку кусками -> структура ключей
	flag = 0;
	tmp = ks; //tmp для того, чтобы не потерять начало списка
	read_ks(tmp);
	if (tmp->key == NULL) // был текст до $, пропускаем
		tmp = tmp->next;
	while (tmp)
	{
		env = envf;
/* если ключ в куске совпадает с ключом окружения то ставим флаг на замену */
		while (flag == 0 && env)						
		{
			if (ft_strncmp(tmp->key, env->key, tmp->len) == 0)
			{
				flag = 1;
				break ;
			}
			else
				env = env->next;
		}
		redefine_value(tmp, env, flag); //в текущем элементе мы нашли необходимость
		tmp = tmp->next;					//преобразования. преобразуем 1 элемент списка
	}
	printf("ending of redefine_full\n");
	read_ks(ks);
	parts_into_str(t, ks); //у нас есть преобразованные куски, которые нужно склеить
	free_keysearch(ks); // очищаем уже ненужный список 
}

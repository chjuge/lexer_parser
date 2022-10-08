/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:37:58 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/08 15:12:58 by mproveme         ###   ########.fr       */
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

t_keyval	*get_env_keys(char **envp)
{
	t_keyval	*env;
	t_keyval	*tmp;

	env = NULL;
	while (envp)
	{
		tmp = init_keyval();
		get_kv(tmp, *envp);
		add_back_keyval(env, tmp);
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
	t_keyval	*env;

	env = get_env_keys(envp);  // перерабатываем параметры окружения в структуру ключ-знач
	while (t != NULL)
	{
		if (t->type == WORDINT && check_redefine(t))
			redefine_full(t, env);
		t = t->next;
	}
}

void	redefine_quo(t_token *t)
{
	while (t)
	{
		if (t->type == QUOINT)
			t->type = WORDINT;
		t = t->next;
	}
}

void	parse_tokens(t_token *t, char **envp)
{
	redefine_dquo(t); // тип "" в тип слов
	redefine_$(t, envp); // раскрываем слова
	redefine_quo(t); // '' в тип слов
	optimize_delims(t); // удаляем излишние токены-разделители
	optimize_words(t); // склеиваем токены, если рядом тип слова
	syntax_checker(t); // проверяем последовательность токенов на допустимый синтаксис
}

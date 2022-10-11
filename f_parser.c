/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:37:58 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/11 17:30:00 by mproveme         ###   ########.fr       */
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
		// printf("%s\n", envp[0]);
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

	env = get_env(envp);  // перерабатываем параметры окружения в структуру ключ-знач
	// printf("env is ready\n");
	// read_env(env);
	// int i = 0;
	while (t != NULL)
	{
		// printf("repeat: %d\n", ++i);
		if (t->type == WORDINT && check_redefine(t))
			redefine_full(t, env);
		t = t->next;
	}
	// printf("i = %d\n", i);
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

t_cmd	*parse_tokens(t_token *t, char **envp)
{
	t_cmd *cmd;

	// read_tokens(t);
	// printf("redefine_dquo\n");
	redefine_dquo(t); // тип "" в тип слов
	// printf("redefine_$\n");
	redefine_$(t, envp); // раскрываем слова
	// printf("redefine_quo\n");
	redefine_quo(t); // '' в тип слов
	// printf("optimize_words\n");
	optimize_words(t); // склеиваем токены, если рядом тип слова
	// read_tokens(t);	
	// printf("optimize_delims\n");
	optimize_delims(&t); // удаляем излишние токены-разделители UPD: УДАЛЯЕМ ВСЕ разделители
	// printf("read_tokens\n");
	// read_tokens(t);
	// printf("syntax_checker\n");
	syntax_checker(t); // проверяем последовательность токенов на допустимый синтаксис
	// printf("syntax is ok!\n");

	cmd = token_to_cmd(t);
	// printf("->>cmd parsed!\n");
	return (cmd);
}

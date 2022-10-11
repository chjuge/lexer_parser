/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:27:37 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/11 15:20:14 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

char	*get_line(char *s) // используем readline для получения строки
{
	// printf("--> in get_line\n");
	char	*str;
	
	if (s)
		free(s);
	str = readline("vvodi_svoyu_hernyu-> ");
	if (str && str[0] != ENDL)
		add_history(str);
	return (str);
}

int	main(int argc, char** argv, char **envp)
{
	// printf("--> in main\n");
	char	*str;

	(void)argc;
	(void)argv;
	str = NULL;
	// while(1)
	// {
		str = get_line(str);
		printf("inputed string: '%s'\n", str);
		string_run(str, envp);
	// 	if (str == NULL)
	// 		break ;
	// }
	return (0);
}

int	string_run(char *str, char **envp) // обрабатываем строку, получаем токены
{
	// printf("--> in string_run\n");
	int		i;
	t_token	*t;
	t_token *tmp;

	i = 0;

	t = NULL;
	while (str[i] != ENDL)
	{
		tmp = create_token(str + i, &i);
		add_back_token(&t, tmp);
		// printf("%c", str[i]);
		// i++;
	}
	fill_content_all(t);
	// read_tokens(t);
	parse_tokens(t, envp);
	// printf("\n");
	return (i);
}

int	check_sp_ch(char c) // проверяем на специальные символы
{
	// printf("--> in check_sp_ch\n");
	if (c == QUO)
		return (QUOINT);
	else if (c == DQUO)
		return (DQUOINT);
	else if (c == PIPE)
		return (PIPEINT);
	else if (c == DEL)
		return (DELINT);
	else if (c == REDG)
		return (REDGINT);
	else if (c == REDL)
		return (REDLINT);
	else if (c == ENDL)
		return (-1);
	return (WORDINT);
}

void	token_by_type(t_token *t, int *i)  // создаем токен в зависимости от типа
{
	// printf("--> in token_by_type\n");
	if (t->type == WORDINT)
		token_word(t, i);
	else if (t->type == DELINT)
		token_del(t, i);
	else if (t->type == PIPEINT)
		token_pipe(t, i);
	else if (t->type == QUOINT)
		token_quo(t, i);
	else if (t->type == DQUOINT)
		token_dquo(t, i);
	else if (t->type == REDGINT)
		token_redg(t, i);
	else if (t->type == REDLINT)
		token_redl(t, i);
	else
	{
		printf("Something got wrong! No right token\n");
		exit(1);
	}
}

t_token	*create_token(char *ptr, int *i)
{
	// printf("--> in create_token\n");
	t_token	*new_token;

	new_token = init_token();
	new_token->ptr = ptr;
	new_token->type = check_sp_ch(ptr[0]);
	token_by_type(new_token, i);
	return (new_token);
}

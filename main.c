/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:27:37 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/05 15:07:46 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

char	*get_line(char *s)
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
	(void)envp;
	str = NULL;
	// while(1)
	// {
		str = get_line(str);
		printf("inputed string: '%s'\n", str);
		string_run(str);
	// 	if (str == NULL)
	// 		break ;
	// }
	return (0);
}

int	string_run(char *str)
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
		ft_lstadd_back(&t, tmp);
		// printf("%c", str[i]);
		// i++;
	}
	fill_content_all(t);
	read_tokens(t);
	// printf("\n");
	return (i);
}

int	check_sp_ch(char c)
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

void	token_by_type(t_token *t, int *i)
{
	// printf("--> in token_by_type\n");
	if (t->type == 0)
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

void	token_word(t_token *t, int *i)
{
	// printf("--> in token_word\n");
	int	type;

	(t->len)++;
	(*i)++;
	type = check_sp_ch((t->ptr)[0]);
	while (type == WORDINT)
	{
		(t->len)++;
		(*i)++;
		type = check_sp_ch(t->ptr[t->len]);
	}
}

void	token_del(t_token *t, int *i)
{
	// printf("--> in token_del\n");
	(t->len)++;
	(*i)++;
}

void	token_pipe(t_token *t, int *i)
{
	// printf("--> in token_pipe\n");
	(t->len)++;
	(*i)++;	
}

void	token_quo(t_token *t, int *i)
{
	char	*ptr;

	// printf("--> in token_quo\n");
	(*i)++;
	(t->ptr)++;
	// printf("drop before if for while\n");
	ptr = t->ptr;
	while (ptr[0] != QUO && ptr[0] != ENDL)
	{
		(*i)++;
		(t->len)++;
		// printf ("len	%d	ptr	%p	char	%c\n", t->len, t->ptr, ptr[0]);
		ptr++;
		// usleep(100000*3);
	}
	// printf("drop before if for ENDL\n");
	if (ptr[0] == ENDL)
	{
		printf("Input error. There are no second quote.\n");
		exit(1);
	}
	(*i)++;
}

void	token_dquo(t_token *t, int *i)
{
	char	*ptr;

	// printf("--> in token_dquo\n");
	(*i)++;
	(t->ptr)++;
	ptr = t->ptr;
	while (ptr[0] != DQUO && ptr[0] != ENDL)
	{
		(*i)++;
		(t->len)++;
		// printf ("len	%d	ptr	%p	char	%c\n", t->len, t->ptr, ptr[0]);
		ptr++;
		// usleep(100000*3);
	}
	// printf("drop before if for ENDL\n");
	if (ptr[0] == ENDL)
	{
		printf("Input error. There are no second double quote.\n");
		exit(1);
	}
	(*i)++;
}

void	token_redg(t_token *t, int *i)
{
	// printf("--> in token_redg\n");
	(*i)++;
	(t->len)++;
	if (t->ptr[t->len] == REDG)
	{
		(*i)++;
		(t->len)++;
		t->type = REDGGINT;
	}
}

void	token_redl(t_token *t, int *i)
{
	// printf("--> in token_redl\n");
	(*i)++;
	(t->len)++;
	if (t->ptr[t->len] == REDL)
	{
		(*i)++;
		(t->len)++;
		t->type = REDLLINT;
	}
}

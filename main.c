#include "header/header.h"

char	*get_line(void)
{
	char	*str;
	
	str = readline("vvodi_svoyu_hernyu-> ");
	if (str[0] != ENDL)
		add_history(str);
	return (str);
}

int	main(int argc, char** argv, char **envp)
{
	// char *str = "hey bro! how are you?";
	char	*str;

	(void)argc;
	(void)argv;
	(void)envp;
	str = get_line();
	printf("'%s'\n", str);
	// printf("res = %d\n", string_run(str));
	return (0);
}

int	string_run(char *str)
{
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
	// printf("\n");
	return (i);
}

int	check_sp_ch(char c)
{
	if (c == QUO)
		return (QUOINT);
	else if (c == DQUO)
		return (DQUOINT);
	else if (c == PIPE)
		return (PIPEINT);
	else if (c == DEL)
		return (DELINT);
	else if (c == REDG || c == REDL)
		return (REDGINT);
	return (WORDINT);
}

void	token_by_type(t_token *t, int *i)
{
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
	t_token	*new_token;

	new_token = init_token();
	new_token->ptr = ptr;
	new_token->type = check_sp_ch(ptr[0]);
	token_by_type(new_token, i);
	return (new_token);
}

void	token_word(t_token *t, int *i)
{
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
	(t->len)++;
	(*i)++;
}

void	token_pipe(t_token *t, int *i)
{
	(t->len)++;
	(*i)++;	
}

void	token_quo(t_token *t, int *i)
{
	(*i)++;
	(t->ptr)++;
	while ((t->ptr)[0] != QUO || (t->ptr)[0] != ENDL)
	{
		(*i)++;
		(t->len)++;
		(t->ptr)++;
	}
	if ((t->ptr)[0] == ENDL)
	{
		printf("Input error. There are no second quote.\n");
		exit(1);
	}
	(*i)++;
}

void	token_dquo(t_token *t, int *i)
{
	(*i)++;
	(t->ptr)++;
	while ((t->ptr)[0] != DQUO || (t->ptr)[0] != ENDL)
	{
		(*i)++;
		(t->len)++;
		(t->ptr)++;
	}
	if ((t->ptr)[0] == ENDL)
	{
		printf("Input error. There are no second duoble quote.\n");
		exit(1);
	}
	(*i)++;
}

void	token_redg(t_token *t, int *i)
{
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
	(*i)++;
	(t->len)++;
	if (t->ptr[t->len] == REDL)
	{
		(*i)++;
		(t->len)++;
		t->type = REDLLINT;
	}
}
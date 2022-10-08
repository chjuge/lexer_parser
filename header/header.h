/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:58:31 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/08 14:30:43 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define DEL ' '
# define DELINT 1
# define QUO '\''
# define QUOINT 2
# define DQUO '\"'
# define DQUOINT 3
# define PIPE '|'
# define PIPEINT 4
# define REDG '>'
# define REDGINT 5
# define REDL '<'
# define REDLINT 6
# define REDLLINT 7
# define REDGGINT 8
# define WORDINT 0
# define ENDL '\0'

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_token  // структура токенов, то, что приходит в парсер
{
	struct s_token	*next;		//следующий токе в списке
	int				type;		//слово, разделитель и т.д.
	int				len;		//длина всего слова, если это слово
	char			*ptr;		//начало слова в строке
	char			*content;		//само слово после извлечения/раскрытия
}					t_token;

typedef struct s_keyval  // переменная окружения, переработанная в список ключ + значение
{
	struct s_keyval	*next;
	char			*key;
	char			*val;
	int				len_k;
	int				len_v;
}					t_keyval;

typedef struct s_group  // финальные группы для исполненинеия execve
{						// т.е. то, что получится после парсера
	t_keyval	*g;		// и применения токенов пайпа
	t_keyval	*next;
}				t_group;

typedef struct s_keysearch   // структура для отработки $
{
	struct s_keysearch	*next;
	char				*ptr;
	char				*key;
	char				*value;
	int					len;
}						t_keysearch;


// rrr.c
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int	ft_strncmp(const char *s1, const char *s2, size_t len);
char	*ft_strdup(const char *str);

t_token	*init_token(void);
// t_token	*ft_lstlast(t_token *lst);
void	add_back_token(t_token **lst, t_token *new);

int		string_run(char *str, char **envp);
int		check_sp_ch(char c);
t_token	*create_token(char *ptr, int *i);
void	token_by_type(t_token *t, int *i);
void	token_word(t_token *t, int *i);
void	token_quo(t_token *t, int *i);
void	token_dquo(t_token *t, int *i);
void	token_del(t_token *t, int *i);
void	token_pipe(t_token *t, int *i);
void	token_redg(t_token *t, int *i);
void	token_redl(t_token *t, int *i);


void	fill_content(t_token *t);
void	fill_content_all(t_token *t);
void	read_tokens(t_token *t);

t_keyval	*init_keyval(void);
void		add_back_keyval(t_keyval **lst, t_keyval *new);

t_group		*init_group(void);
void		add_back_group(t_group **lst, t_group *new);


t_keysearch	*init_keysearch(void);
void	add_back_keysearch(t_keysearch **lst, t_keysearch *new);

//parser.c
void	parse_tokens(t_token *t, char **envp);
void	redefine_$(t_token *t, char **envp);


//redefine_str.c
int		get_substr(char *src, char *dst, int *len, char ch);
void	redefine_full(t_token *t, t_keyval *env);
#endif

// gcc -Wall -Wextra -Werror -lreadline *.c      
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:58:31 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/05 19:00:33 by mproveme         ###   ########.fr       */
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

typedef struct s_token
{
	struct s_token	*next;		//следующий токе в списке
	int				type;		//слово, разделитель и т.д.
	int				len;		//длина всего слова, если это слово
	char			*ptr;		//начало слова в строке
	char			*content;		//само слово после извлечения/раскрытия
}					t_token;

typedef struct s_keyval
{
	struct s_keyval	*next;
	char			*key;
	char			*val;
	int				len_k;
	int				len_v;
}					t_keyval;


size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

t_token	*init_token(void);
// t_token	*ft_lstlast(t_token *lst);
void	add_back_token(t_token **lst, t_token *new);

int		string_run(char *str);
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
void	add_back_keyval(t_keyval **lst, t_keyval *new);
#endif

// gcc -Wall -Wextra -Werror -lreadline *.c      
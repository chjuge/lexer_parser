/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:58:31 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/04 15:45:26 by mproveme         ###   ########.fr       */
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

typedef struct s_token
{
	struct s_token	*next;		//следующий токе в списке
	int				type;		//слово, разделитель и т.д.
	int				len;		//длина всего слова, если это слово
	char			*ptr;		//начало слова в строке
	char			*str;		//само слово после извлечения/раскрытия
}					t_token;


size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

t_token	*init_token(void);
t_token	*ft_lstlast(t_token *lst);
void	ft_lstadd_back(t_token **lst, t_token *new);

int		string_run(char *str);
int		check_sp_ch(char c);
void	token_by_type(t_token *t, int *i);
void	token_word(t_token *t, int *i);
void	token_quo(t_token *t, int *i);
void	token_dquo(t_token *t, int *i);

#endif
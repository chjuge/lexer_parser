/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:58:31 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/12 16:15:41 by mproveme         ###   ########.fr       */
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
	struct s_token	*next;
	int				type;
	int				len;
	char			*ptr;
	char			*content;
}					t_token;

typedef struct s_env
{
	struct s_env	*next;
	char			*key;
	char			*val;
	int				len_k;
	int				len_v;
}					t_env;

typedef struct s_group
{
	struct s_group	*g;
	struct s_group	*next;
}					t_group;

typedef struct s_keysearch
{
	struct s_keysearch	*next;
	char				*ptr;
	char				*key;
	char				*value;
	int					len;
}						t_keysearch;

typedef struct s_param
{
	struct s_param	*next;
	char			*content;
}					t_param;


typedef struct s_red
{
	struct s_red	*next;
	char			*word;
}					t_red;

typedef struct		s_cmd
{
	char			*cmd;
	char			**args;
	t_red			*red_g;
	t_red			*red_gg;
	t_red			*red_l;
	t_red			*red_ll;
	struct s_cmd	*next;
}					t_cmd;

/*	f_create_token.c	*/
t_token	*create_token(char *ptr, int *i);
void	token_by_type(t_token *t, int *i);
int		check_sp_ch(char c);
/*	f_utils.c	*/
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
char	*ft_strdup(const char *str);
void	ft_strcpy(char *dst, char *src, int cnt);
/*	t_token.c	*/
t_token	*init_token(void);
void	add_back_token(t_token **lst, t_token *new);
void	free_token(t_token *t);
void	free_tokens_all(t_token *t);
/*	main.c	*/
t_cmd	*string_run(char *str, char **envp);
/*	f_token_by_type.c	*/
void	token_word(t_token *t, int *i);
void	token_quo(t_token *t, int *i, char ch);
void	token_del(t_token *t, int *i);
void	token_pipe(t_token *t, int *i);
void	token_red(t_token *t, int *i);
/*	f_fill_content.c	*/
void	fill_content(t_token *t);
void	fill_content_all(t_token *t);
/*	f_readers.c		*/
void	read_tokens(t_token *t);
void	read_env(t_env *env);
void	read_ks(t_keysearch *ks);
void	read_red_all(t_red *r);
void	free_cmds_all(t_cmd *t);
void	read_cmds_all(t_cmd *cmd);
/*	t_env.c	*/
t_env	*init_env(void);
void	add_back_env(t_env **lst, t_env *new);
void	free_envs_all(t_env *env);
/*	t_group.c	*/
t_group		*init_group(void);
void		add_back_group(t_group **lst, t_group *new);
/*	t_keysearch.c	*/
t_keysearch	*init_keysearch(void);
void	add_back_keysearch(t_keysearch **lst, t_keysearch *new);
void	free_keysearch(t_keysearch *t);
/*	f_parser.c	*/
t_cmd	*parse_tokens(t_token *t, char **envp);
void	redefine_$(t_token *t, char **envp);
/*	f_redefine_str.c	*/
int		get_substr(char *src, char **dst, int *len, char ch);
void	redefine_full(t_token *t, t_env *env);
/*	f_optimize_tokens.c	*/
void	optimize_delims(t_token **t);
void	optimize_words(t_token *t);
/*	syntax_checker.c	*/
void	syntax_checker(t_token *t);
/*	t_red.c	*/
t_red	*init_red(char	*content);
void	add_back_red(t_red **lst, t_red *new);
void	free_red(t_red *t);
void	free_reds_all(t_red *t);
/*	t_cmd.c	*/
t_cmd	*init_cmd(void);
void	add_back_cmd(t_cmd **lst, t_cmd *new);
void	free_cmd(t_cmd *t);
/*	f_token_to_cmd.c	*/
t_cmd	*token_to_cmd(t_token *t);
/*	t_param.c	*/
t_param	*init_param(char *s);
void	add_back_param(t_param **lst, t_param *new);
void	free_param(t_param *t);
void	free_params_all(t_param *t);
/*	f_free_array.c	*/
void	free_array(char **arr);
#endif
// gcc -Wall -Wextra -Werror -lreadline *.c     

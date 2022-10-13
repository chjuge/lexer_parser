/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:58:31 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/13 15:06:12 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
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

typedef struct s_ks
{
	struct s_ks	*next;
	char		*ptr;
	char		*key;
	char		*value;
	int			len;
}				t_ks;

typedef struct s_word
{
	struct s_word	*next;
	char			*word;
}					t_word;

typedef struct s_cmd
{
	char			*cmd;
	char			**args;
	t_word			*red_g;
	t_word			*red_gg;
	t_word			*red_l;
	t_word			*red_ll;
	struct s_cmd	*next;
}					t_cmd;

/*	f_create_token.c	*/
t_token	*create_token(char *ptr, int *i);
void	token_by_type(t_token *t, int *i);
int		check_sp_ch(char c);
/*	f_utils.c	*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	ft_strcpy(char *dst, char *src, int cnt);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
char	*ft_strdup(const char *str);
/*	f_utils2.c	*/
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
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
void	read_ks(t_ks *ks);
void	read_red_all(t_word *r);
void	read_cmd(t_cmd *cmd);
void	free_cmds_all(t_cmd *t);
void	read_cmds_all(t_cmd *cmd);
/*	t_env.c	*/
t_env	*init_env(void);
void	add_back_env(t_env **lst, t_env *new);
void	free_envs_all(t_env *env);
/*	t_keysearch.c	*/
t_ks	*init_keysearch(void);
void	add_back_keysearch(t_ks **lst, t_ks *new);
void	free_keysearch(t_ks *t);
/*	f_parser.c	*/
t_cmd	*parse_tokens(t_token **t, char **envp);
/*	f_parser_utils	*/
void	redefine_dollar(t_token *t, char **envp);
void	redefine_quo(t_token *t, int type);
int		check_redefine(t_token *t);
t_env	*get_env(char **envp);
void	get_kv(t_env *env, char *str);
/*	f_redefine_str.c	*/
void	redefine_full(t_token *t, t_env *env);
/*	f_get_substr.c	*/
int		get_substr(char *src, char **dst, int *len, char ch);
/*	f_optimize_tokens.c	*/
void	optimize_delims(t_token **t);
void	optimize_words(t_token *t);
/*	f_optimize_tokens_utils.c	*/
void	delite_next_token(t_token *curr, t_token *next);
void	delite_curr_token(t_token *curr, t_token *prev);
t_token	*skip_to_delims(t_token *tmp, t_token **prev);
void	delete_delims(t_token **tmp, t_token *prev, t_token **t);
void	token_cat(t_token *curr, t_token *next);
/*	syntax_checker.c	*/
void	syntax_checker(t_token *t);
/*	t_word.c	*/
t_word	*init_word(char	*content);
void	add_back_word(t_word **lst, t_word *new);
void	free_word(t_word *t);
void	free_words_all(t_word *t);
/*	t_cmd.c	*/
t_cmd	*init_cmd(void);
void	add_back_cmd(t_cmd **lst, t_cmd *new);
void	free_cmd(t_cmd *t);
/*	f_token_to_cmd.c	*/
t_cmd	*token_to_cmd(t_token *t);
char	**parse_args(t_word	*p);
/*	f_free_array.c	*/
void	free_array(char **arr);
/*	f_token_to_cmd_utils.c	*/
int		find_count(t_word *tmp);
void	add_red_to_cmd(t_cmd *cmd, int *flag, char *content);
void	init_and_add_back_word(t_word **head, char *str);
void	end_of_cmd(t_cmd **cmd, t_cmd **tmp, t_word **param, t_token *t);
void	init_base(t_cmd **cmd, t_cmd **tmp, int *flag, t_word **param);
#endif
// gcc -Wall -Wextra -Werror -lreadline *.c     

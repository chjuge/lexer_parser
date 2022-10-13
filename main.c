/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:27:37 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/13 14:31:30 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

char	*get_line(char *s)
{
	char	*str;

	if (s)
		free(s);
	str = readline("vvodi_svoyu_hernyu-> ");
	if (str && str[0] != ENDL)
		add_history(str);
	return (str);
}

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	t_cmd	*cmd;

	(void)argc;
	(void)argv;
	str = NULL;
	str = get_line(str);
	printf("inputed string: '%s'\n", str);
	cmd = string_run(str, envp);
	read_cmds_all(cmd);
	free(str);
	free_cmds_all(cmd);
	return (0);
}

t_cmd	*string_run(char *str, char **envp)
{
	int		i;
	t_token	*t;
	t_token	*tmp;
	t_cmd	*cmd;

	i = 0;
	t = NULL;
	while (str[i] != ENDL)
	{
		tmp = create_token(str + i, &i);
		add_back_token(&t, tmp);
	}
	fill_content_all(t);
	cmd = parse_tokens(&t, envp);
	free_tokens_all(t);
	return (cmd);
}

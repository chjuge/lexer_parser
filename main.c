/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:27:37 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/26 18:10:33 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

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

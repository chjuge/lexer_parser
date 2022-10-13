/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:37:58 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/13 14:57:33 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

t_cmd	*parse_tokens(t_token **t, char **envp)
{
	t_cmd	*cmd;

	redefine_quo(*t, DQUOINT);
	redefine_dollar(*t, envp);
	redefine_quo(*t, QUOINT);
	optimize_words(*t);
	optimize_delims(t);
	syntax_checker(*t);
	cmd = token_to_cmd(*t);
	return (cmd);
}

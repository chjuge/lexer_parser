/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:31:57 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/09 13:11:24 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

void	print_parse_error(char ch)
{
	printf("parse error near `%c'\n", ch);
	exit(1);
}

void	syntax_checker(t_token *t)
{
	if (t->type == PIPEINT)
		print_parse_error(PIPE);	
}

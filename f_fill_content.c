/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_fill_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:02:49 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/26 18:07:20 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

void	fill_content(t_token *t)
{
	char	*content;
	int		i;

	content = malloc(t->len + 1);
	content[t->len] = ENDL;
	i = 0;
	while (i < t->len)
	{
		content[i] = t->ptr[i];
		i++;
	}
	t->content = content;
}

void	fill_content_all(t_token *t)
{
	while (t)
	{
		fill_content(t);
		t = t->next;
	}
}

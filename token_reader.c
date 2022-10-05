/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:09:30 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/05 14:19:11 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

void	read_tokens(t_token *t)
{
	// printf("--> in read_tokens\n");
	printf("type	%d	len	%d	ptr	%p	content	%s	\n", t->type, t->len, t->ptr, t->content);
	while (t->next)
	{
		t = t->next;
		printf("type	%d	len	%d	ptr	%p	content	%s	\n", t->type, t->len, t->ptr, t->content);
	}
}

void	fill_content(t_token *t)
{
	// printf("--> in fill_content\n"); 
	char	*content;
	int		i;

	content = malloc(t->len + 1);
	content[t->len] = ENDL;
	i = 0;
	// printf("voshel v cicle kopirovaniya\n");
	while (i < t->len)
	{
		// write(1, t->ptr+i, 1);
		content[i] = t->ptr[i];
		i++;
	}
	// printf("\n");
	t->content = content;
}

void	fill_content_all(t_token *t)
{
	fill_content(t);
	while (t->next)
	{
		t = t->next;
		fill_content(t);
	}
}

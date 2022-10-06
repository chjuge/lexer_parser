/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redefine_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:22:39 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/06 17:41:18 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

void	redefine_str(t_token *t, t_keyval *env)
{
	t_keysearch	*tmp;
	t_keysearch	*ks;
	int			i;

	ks = NULL;
	i = 0;
	tmp = init_keysearch();
	while (t->content[i++] != '$')
		tmp->len++;
	tmp->value = malloc(tmp->len + 1);
	ft_strlcpy(tmp->value, t->content, tmp->len);
	add_back_keysearch(ks, tmp);
	i++;
	while (1)
	{
		tmp = init_keysearch();
		tmp->ptr = t->content + i;
		while (t->content[i] != '$' && t->content[i++] != ENDL)
			tmp->len++;
		tmp->key = malloc(tmp->len + 1);
		ft_strlcpy(tmp->key, tmp->ptr, tmp->len);
		add_back_keysearch(ks, tmp);
		if (t->content[i] == ENDL)
			break ;
		i++;
	}
}

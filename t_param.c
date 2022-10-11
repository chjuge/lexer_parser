/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_param.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:06:49 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/11 16:27:16 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

t_param	*init_param(char *s)
{
	t_param	*res;

	res = malloc(sizeof(t_param));
	res->next = NULL;
	res->content = ft_strdup(s);
	return (res);
}

t_param *param_last(t_param *lst)
{
	printf("param_last\n");
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_back_param(t_param **lst, t_param *new)
{
	t_param	*tmp;

	// printf("add_back_param	%p\n", lst);
	if (!lst)
	{
		// printf("lst -> NULL\n");
		return ;
	}
	// printf("0\n");
	tmp = *lst;
	// tmp = NULL;
	// printf("1\n");
	if (!tmp)
	{
		// printf("10\n");
		*lst = new;
		// printf("11\n");
		return ;
	}
	// printf("2\n");
	tmp = param_last(tmp);
	// printf("3\n");
	tmp->next = new;
	// printf("4\n");
}

void	free_param(t_param *t)
{
	if (t->content)
		free(t->content);
	free(t);
}

void	free_params_all(t_param *t)
{
	t_param	*tmp;

	tmp = t;
	while (t)
	{
		tmp = t;
		t = t->next;
		free_param(tmp);
	}
}

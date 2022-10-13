/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:33:52 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/13 14:30:28 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

t_env	*init_env(void)
{
	t_env	*new_el;

	new_el = malloc(sizeof(t_env));
	new_el->next = NULL;
	new_el->key = NULL;
	new_el->val = NULL;
	new_el->len_k = 0;
	new_el->len_v = 0;
	return (new_el);
}

t_env	*env_last(t_env *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_back_env(t_env **lst, t_env *new)
{
	t_env	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	if (!tmp)
	{
		*lst = new;
		return ;
	}
	tmp = env_last(tmp);
	tmp->next = new;
}

void	free_env(t_env *env)
{
	free(env->key);
	free(env->val);
}

void	free_envs_all(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (env)
	{
		tmp = env;
		env = env->next;
		free_env(tmp);
	}	
}

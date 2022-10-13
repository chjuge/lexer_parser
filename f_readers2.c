/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_readers2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:09:30 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/13 14:59:27 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

void	read_cmds_all(t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	if (tmp == NULL)
		printf("list of commands is empty\n");
	while (tmp)
	{
		read_cmd(tmp);
		tmp = tmp->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_free_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:13:06 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/12 14:32:48 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

void	free_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	printf ("arr	%p\n", *arr);
	// printf("arr[0]	%p\n", arr[0]);
	while (arr[i] != NULL)
	{
		printf("i --> %d	s	%s\n", i, arr[i]);
		free(arr[i]);
		i++;
	}
	printf("vishel	%p\n", arr);
	free(arr);
}

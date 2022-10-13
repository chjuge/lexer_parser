/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_get_substr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:03:46 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/13 15:04:10 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

int	get_substr(char *src, char **dst, int *len, char ch)
{
	int		i;
	char	*s;

	i = 0;
	while (src[i] != ch && src[i] != ENDL)
		i++;
	if (i != 0)
	{
		s = malloc(i + 1);
		ft_strlcpy(s, src, i + 1);
		*len = i;
		*dst = s;
	}
	return (i);
}

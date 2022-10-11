/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:47:26 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/11 17:42:32 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/header.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (dst);
	if (!src && !dst)
		return (0);
	while (i < n)
	{
		((char *)(dst))[i] = ((char *)(src))[i];
		i++;
	}
	return ((char *)(dst));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_size;

	src_size = ft_strlen(src);
	if (src_size + 1 < size)
		ft_memcpy(dst, src, src_size + 1);
	else if (size)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (src_size);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_size;
	size_t	dst_size;
	size_t	bytes_to_copy;

	src_size = ft_strlen(src);
	dst_size = ft_strlen(dst);
	if (size < dst_size + 1)
		return (src_size + size);
	bytes_to_copy = size - dst_size;
	ft_strlcpy(dst + dst_size, src, bytes_to_copy);
	return (src_size + dst_size);
}

void	ft_strcpy(char *dst, char *src, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		dst[i] = src[i];
		i++;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	unsigned char	tmp1;
	unsigned char	tmp2;

	while (len-- > 0)
	{
		tmp1 = (unsigned char) *s1++;
		tmp2 = (unsigned char) *s2++;
		if (tmp1 != tmp2)
			return (tmp1 - tmp2);
		if (tmp1 == '\0')
			return (0);
	}
	return (0);
}

char	*ft_strdup(const char *str)
{
	char	*new_str;
	int		len;
	int		i;

	len = ft_strlen(str);
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (0);
	i = 0;
	while (i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

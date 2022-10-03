/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:58:31 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/03 18:05:29 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define DEL ' '
# define DELINT 4
# define COM '\''
# define COMINT 1
# define COM2 '\"'
# define COM2INT 2
# define PIPE '|'
# define PIPEINT 3
# define REDG '>'
# define REDL '<'
# define REDINT 5

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_token
{
	struct s_token	*next;		//следующий токе в списке
	int				type;		//слово, разделитель и т.д.
	char			*ptr;		//начало слова в строке
	int				len;		//длина всего слова, если это слово
	char			*str;		//само слово после извлечения/раскрытия
};


size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
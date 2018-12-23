/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olesgedz <olesgedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:37:38 by olesgedz          #+#    #+#             */
/*   Updated: 2018/12/20 21:14:16 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static size_t		ft_toutf8(char *dest, unsigned int ch)
{
	if (ch < 0x800)
	{
		dest[0] = (ch >> 6) | 0xC0;
		dest[1] = (ch & 0x3F) | 0x80;
		return (2);
	}
	if (ch < 0x10000)
	{
		dest[0] = (ch >> 12) | 0xE0;
		dest[1] = ((ch >> 6) & 0x3F) | 0x80;
		dest[2] = (ch & 0x3F) | 0x80;
		return (3);
	}
	if (ch < 0x110000)
	{
		dest[0] = (ch >> 18) | 0xF0;
		dest[1] = ((ch >> 12) & 0x3F) | 0x80;
		dest[2] = ((ch >> 6) & 0x3F) | 0x80;
		dest[3] = (ch & 0x3F) | 0x80;
		return (4);
	}
	return (0);
}

/*
** (unsigned char)c < 0x80
*/

void				ft_putchar(char c)
{
	char	strm[4];
	int		length;

	if (1)
		write(1, &c, 1);
	else
	{
		length = ft_toutf8(strm, (unsigned char)c);
		if (length == 0)
			return ;
		write(1, strm, length);
	}
}

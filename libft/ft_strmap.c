/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:30:25 by jblack-b          #+#    #+#             */
/*   Updated: 2018/12/08 20:19:32 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		ft_u_striter(char *s, char (*f)(char))
{
	if (s)
		while (*s)
		{
			*s = f(*s);
			s++;
		}
	return (*s);
}

char			*ft_strmap(char const *s, char (*f)(char))
{
	char *new;

	if (s == NULL)
		return (NULL);
	if (!(new = (char *)(malloc(sizeof(char) * ft_strlen((char *)s) + 1))))
		return (NULL);
	ft_strcpy(new, s);
	ft_u_striter(new, f);
	return (new);
}

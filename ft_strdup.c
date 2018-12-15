/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:07:42 by jblack-b          #+#    #+#             */
/*   Updated: 2018/12/15 10:36:06 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *new;

	if (!(new = (char*)malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (NULL);
	ft_strcpy(new, src);
	return (new);
}

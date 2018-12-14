/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:32:09 by jblack-b          #+#    #+#             */
/*   Updated: 2018/12/15 02:26:39 by olesgedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_strlen(const char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

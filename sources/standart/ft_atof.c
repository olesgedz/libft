/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 20:38:25 by jblack-b          #+#    #+#             */
/*   Updated: 2020/03/06 20:39:20 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	int		sign;
	double	i;
	double	value;
	int		exponent;

	i = 1;
	sign = 0;
	value = 0;
	while (ft_is_space(*str))
		str++;
	*str == '-' ? sign = 1 : 0;
	*str == '-' || *str == '+' ? str++ : 0;
	while ('0' <= *str && *str <= '9')
		value = value * 10 + (*str++ - '0');
	if (*str == '.' && (str++))
		while ('0' <= *str && *str <= '9')
			value += (*str++ - '0') / (i *= 10);
	if (*str == 'E' && (str++))
	{
		exponent = ft_atoi(str);
		if (exponent != 0)
			value = value * ft_pow(10, exponent);
	}
	return (sign == 1 && value > 0 ? -value : value);
}
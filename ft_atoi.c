/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:37:56 by jblack-b          #+#    #+#             */
/*   Updated: 2018/12/16 12:07:42 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		ft_atoi_skip(const char **str, int *sign)
{
	while (**str == ' ' || **str == '\n'
	|| **str == '\t' || **str == '\r'
	|| **str == '\v' || **str == '\f')
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			*sign = -1;
		(*str)++;
	}
	while (**str == '0')
		(*str)++;
}

int				ft_atoi(const char *str)
{
	long	int				nbr;
	int						sign;
	int						digits;

	sign = 1;
	nbr = 0;
	digits = 0;
	ft_atoi_skip(&str, &sign);
	while ('0' <= *str && *str <= '9')
	{
		nbr = nbr * 10 + *str - '0';
		str++;
	}
	if ((9223372036854775807 <= nbr && sign == 1))
		return (-1);
	if ((9223372036854775807 < nbr && sign == -1))
		return (0);
	return ((int)(nbr) * sign);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 20:39:09 by jblack-b          #+#    #+#             */
/*   Updated: 2020/03/06 20:39:57 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(double nb, int expo)
{
	double result;

	result = 1;
	while (expo > 0)
	{
		result = result * nb;
		expo--;
	}
	while (expo < 0)
	{
		result = result / nb;
		expo++;
	}
	return (result);
}
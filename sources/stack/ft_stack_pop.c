/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olesgedz <olesgedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 03:25:09 by olesgedz          #+#    #+#             */
/*   Updated: 2019/04/23 03:25:25 by olesgedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_stack_pop(t_stack *stack)
{
	t_list *temp;
	temp = stack->top;
	if (stack->top->next)
		stack->top = stack->top->next;
	return (temp);
}

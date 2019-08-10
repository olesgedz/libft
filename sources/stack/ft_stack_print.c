/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olesgedz <olesgedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 03:18:01 by olesgedz          #+#    #+#             */
/*   Updated: 2019/04/23 03:18:22 by olesgedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stack_print(t_stack *stack)
{
	while (stack->top)
	{
		ft_memprint(stack->top->content,\
		stack->top->content_size);
		ft_putchar('\n');
		stack->top = stack->top->next;
	}
}
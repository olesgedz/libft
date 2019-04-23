/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olesgedz <olesgedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 01:36:09 by olesgedz          #+#    #+#             */
/*   Updated: 2019/04/23 03:26:32 by olesgedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include  <stdlib.h>
#include <stdio.h>


int main()
{
	t_stack *stack;

	stack = ft_stack_create("hello", 5);
	ft_stack_push(stack, "booo", 4);
	ft_stack_push(stack, "b2oo", 4);
	ft_stack_push(stack, "b3oo", 4);
	printf("xx%s\n", ft_stack_peek(stack)->content);

	//ft_memprint(stack->top->before->content, 4);
	ft_stack_print(stack);

}
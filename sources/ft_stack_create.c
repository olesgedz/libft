/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olesgedz <olesgedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 03:20:34 by olesgedz          #+#    #+#             */
/*   Updated: 2019/04/23 03:29:16 by olesgedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_stack		*ft_stack_create(void *content, size_t content_size)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    new->size = 1;
    new->top = ft_lstnew(content, content_size);
    return (new);
}
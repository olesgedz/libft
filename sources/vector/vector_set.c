/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olesgedz <olesgedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 08:43:57 by olesgedz          #+#    #+#             */
/*   Updated: 2019/05/18 09:52:37 by olesgedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void vector_set(t_vector *v, int index, void *item)
{
    if (index >= 0 && index < v->total)
        v->items[index] = item;
}
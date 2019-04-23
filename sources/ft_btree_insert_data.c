/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olesgedz <olesgedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 07:15:17 by olesgedz          #+#    #+#             */
/*   Updated: 2019/04/23 07:15:35 by olesgedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
    if (*root == NULL)
        *root = ft_btree_create_node(item);
    else
    {
        if ((*cmpf)(item, (*root)->item) < 0)
            ft_btree_insert_data(&(*root)->left, item, cmpf);
        else
            ft_btree_insert_data(&(*root)->right, item, cmpf);
    }
}
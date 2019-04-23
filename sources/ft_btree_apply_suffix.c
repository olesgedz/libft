/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olesgedz <olesgedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 07:13:31 by olesgedz          #+#    #+#             */
/*   Updated: 2019/04/23 07:15:59 by olesgedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void        ft_btree_apply_suffix(t_btree *root, void (*applyf)(void*))
{
    if (root == NULL)
        return ;
    ft_btree_apply_suffix(root->left, (*applyf));
    ft_btree_apply_suffix(root->right, (*applyf));
    (*applyf)(root->item);
}
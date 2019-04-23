/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_infix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olesgedz <olesgedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 07:12:00 by olesgedz          #+#    #+#             */
/*   Updated: 2019/04/23 07:13:03 by olesgedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_btree_apply_infix(t_btree *root, void (*applyf)(void*))
{
    if (root == NULL)
      return ;
    ft_btree_apply_infix(root->left, (*applyf));
    (*applyf)(root->item);
    ft_btree_apply_infix(root->right, (*applyf));
}
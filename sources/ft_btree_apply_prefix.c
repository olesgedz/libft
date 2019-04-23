/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_prefix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olesgedz <olesgedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 07:10:48 by olesgedz          #+#    #+#             */
/*   Updated: 2019/04/23 07:11:09 by olesgedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
    if (!root)
        return ;
      (*applyf)(root->item);
      ft_btree_apply_prefix(root->left, (*applyf));
      ft_btree_apply_prefix(root->right, (*applyf));
}

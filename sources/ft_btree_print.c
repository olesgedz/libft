/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olesgedz <olesgedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 07:24:19 by olesgedz          #+#    #+#             */
/*   Updated: 2019/04/23 07:24:37 by olesgedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_btree_print(t_btree *root, int spaces)
{
  if (root == NULL)
    return;
  spaces += 5;
  ft_btree_print(root->right, spaces);
  ft_putstr("\n");
  for (int i = 5; i < spaces; i++)
    ft_putstr(" ");
  ft_putstr(root->item);
  ft_btree_print(root->left, spaces);
}
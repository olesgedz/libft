/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search_item.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olesgedz <olesgedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 07:17:20 by olesgedz          #+#    #+#             */
/*   Updated: 2019/09/20 21:05:50 by olesgedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_btree_search_item(t_btree *root, void *data_ref,\
	int (*cmpf)(void *, void *))
{
	if (root)
	{
		if (root->left)
		{
			if (ft_btree_search_item(root->left, data_ref, cmpf))
				return (ft_btree_search_item(root->left, data_ref, cmpf));
		}
		if ((*cmpf)(data_ref, root->item) == 0)
			return (root);
		if (root->right)
		{
			if (ft_btree_search_item(root->right, data_ref, cmpf))
				return (ft_btree_search_item(root->right, data_ref, cmpf));
		}
	}
	return (NULL);
}

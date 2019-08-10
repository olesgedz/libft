/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olesgedz <olesgedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 07:20:33 by olesgedz          #+#    #+#             */
/*   Updated: 2019/04/23 07:20:52 by olesgedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	ft_queue_push(t_queue **queue, t_btree *root, int current_level)
{
	t_queue *last;
	t_queue *elem;

	elem = (t_queue *)malloc(sizeof(*elem));
	elem->next = NULL;
	elem->node = root;
	elem->current_level = current_level;
	if (*queue == NULL)
	{
		elem->is_first_elem = 1;
		*queue = elem;
		return ;
	}
	last = *queue;
	while (last->next != NULL)
	{
		last = last->next;
	}
	elem->is_first_elem = last->current_level != current_level;
	last->next = elem;
}
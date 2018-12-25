/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 16:04:10 by jblack-b          #+#    #+#             */
/*   Updated: 2018/12/25 16:05:04 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		ft_lstmap_clean(t_list **begin)
{
	t_list *next_tmp;

	while (*begin)
	{
		free((*begin)->content);
		(*begin)->content = NULL;
		next_tmp = (*begin)->next;
		free(*begin);
		*begin = NULL;
		*begin = next_tmp;
	}
	*begin = NULL;
	begin = NULL;
}

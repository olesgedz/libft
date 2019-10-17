/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 17:41:51 by olesgedz          #+#    #+#             */
/*   Updated: 2019/10/17 17:45:37 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "malloc.h"

unsigned char	**ft_nsplit(void *s, size_t n1, void *match, size_t n2)
{
	size_t			count;
	size_t			n;
	unsigned char	**ret;
	unsigned char	*buf;
	void			*s1;

	count = 0;
	s1 = s;
	n = n1;
	while (ft_word(&s1, &n, match, n2))
		count++;
	ret = ft_memalloc(sizeof(*ret) * (count + 1));
	while ((buf = ft_word(&s, &n1, match, n2)))
	{
		*ret = malloc(sizeof(*ret) * (count + 1));
		ft_memcpy(*ret, buf, (unsigned char *)s - buf);
		(*ret)[(unsigned char *)s - buf] = '\0';
		ret++;
	}
	*ret = NULL;
	return (ret - count);
}

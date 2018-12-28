/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 22:51:08 by jblack-b          #+#    #+#             */
/*   Updated: 2018/12/23 23:17:44 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define MALLOC_CHECK_NULL(x) if (!(x)) return (NULL);
# define MALLOC_CHECK_INT(x) if (!(x)) return (-1);
# define BUFF_SIZE 20

int		get_next_line(const int fd, char **line);

#endif

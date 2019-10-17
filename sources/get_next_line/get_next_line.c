/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:20:41 by jblack-b          #+#    #+#             */
/*   Updated: 2019/10/17 15:05:19 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

// static t_list		*ft_getfile(t_list **file, int fd)
// {
// 	t_list *tmp;

// 	tmp = *file;
// 	while (tmp)
// 	{
// 		if (tmp->content_size == fd)
// 		{
// 			return (tmp);
// 		}
// 		tmp = tmp->next;
// 	}
// 	if (!tmp && !(tmp = ft_lstnew("", fd)))
// 		return (NULL);
// 	ft_lstadd(file, tmp);
// 	tmp = *file;
// 	return (tmp);
// }

// static char			*ft_getline(t_list *lst, char **line)
// {
// 	char	*temp;
// 	size_t	i;

// 	if (ft_strchr((char *)lst->content, '\n'))
// 	{
// 		temp = *line;
// 		*line = ft_strsub((char *)lst->content, 0,\
// 		ft_strchr((char *)lst->content, '\n') - (char *)lst->content);
// 		i = ft_strchr((char *)lst->content, '\n') - (char *)lst->content;
// 		temp = lst->content;
// 		(i < ft_strlen((char *)lst->content)) ? lst->content = \
// 		ft_strdup((char *)lst->content + i + 1)\
// 		: ft_strclr((char *)lst->content);
// 		ft_memdel((void **)&temp);
// 	}
// 	else
// 	{
// 		i = ft_strlen((char *)lst->content);
// 		*line = ft_strncpy(ft_strnew(i), (char *)lst->content, i);
// 		lst->content = ft_strdup((char *)lst->content + i);
// 	}
// 	return (*line);
// }

// int					get_next_line(const int fd, char **line)
// {
// 	int				ret;
// 	static	t_list	*file;
// 	t_list			*lst;
// 	char			*temp;
// 	char			*buf;

// 	if(!(buf = malloc(BUFF_SIZE + 1)))
// 		return (0);
// 	if (fd < 0 || !line || read(fd, buf, 0) < 0 || BUFF_SIZE < 1)
// 		return (-1);
// 	lst = ft_getfile(&file, fd);
// 	while ((ret = read(fd, buf, BUFF_SIZE)))
// 	{
// 		buf[ret] = '\0';
// 		temp = (char *)lst->content;
// 		lst->content = ft_strjoin((char *)lst->content, buf);
// 		ft_memdel((void **)&temp);
// 		if (ft_strchr((char *)lst->content, '\n'))
// 			break ;
// 	}
// 	ft_memdel((void **)&buf);
// 	if (ret < BUFF_SIZE && !ft_strlen((char *)lst->content))
// 		return (0);
// 	*line = ft_getline(lst, line);
// 	return (1);
// }

typedef struct      s_stree
{
    struct s_stree  *left;
    struct s_stree  *right;
    char            *buff;
    int             fd;
}                   t_stree;

char	*ft_recharlloc(char **str, char c)
{
	char		*buff;
	size_t		len;

	len = ft_strlen(*str);
	if (!(buff = ft_strnew(len + 1)))
		return (0);
	if (*str)
		ft_memcpy(buff, *str, len);
	buff[len] = c;
	if (*str)
		ft_memdel((void **)str);
	return (buff);
}


static t_stree	*stree_create_node(int fd)
{
	t_stree	*node;

	if (!(node = (t_stree*)malloc(sizeof(t_stree))))
		return (0);
	if (!(node->buff = ft_strnew(BUFF_SIZE)))
	{
		free(node);
		return (0);
	}
	node->fd = fd;
	node->left = 0;
	node->right = 0;
	return (node);
}

static t_stree	*stree_search_item(t_stree *root, int fd)
{
	if (root)
	{
		if (fd == root->fd)
			return (root);
		if (fd > root->fd)
		{
			if (root->right)
				return (stree_search_item(root->right, fd));
			else
				return (root->right = stree_create_node(fd));
		}
		if (fd < root->fd)
		{
			if (root->left)
				return (stree_search_item(root->left, fd));
			else
				return (root->left = stree_create_node(fd));
		}
	}
	else
		return (stree_create_node(fd));
	return (0);
}

static int		reader(t_stree *current_node, char **line)
{
	size_t			i;
	long int		err;

	i = 0;
	while (current_node->buff[i] != '\n')
	{
		if (!(current_node->buff[i]))
		{
			err = read(current_node->fd, current_node->buff, BUFF_SIZE);
			if (err == 0 && ft_strlen(*line))
				current_node->buff[err++] = '\n';
			else if (err <= 0)
				return (err);
			else if (err < BUFF_SIZE && current_node->buff[err - 1] != '\n')
				current_node->buff[err++] = '\n';
			current_node->buff[err] = '\0';
		}
		i = 0;
		while (current_node->buff[i] && current_node->buff[i] != '\n')
			if (!(*line = ft_recharlloc(line, current_node->buff[i++])))
				return (-1);
	}
	i++;
	current_node->buff = ft_strcpy(current_node->buff, current_node->buff + i);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_stree	*root_node;
	t_stree			*current_node;

	if (!line || !(*line = ft_strnew(0)) || fd < 0 || read(fd, 0, 0) < 0)
		return (-1);
	if (!root_node)
		root_node = stree_search_item(root_node, fd);
	if (!(current_node = stree_search_item(root_node, fd)))
		return (-1);
	return (reader(current_node, line));
}

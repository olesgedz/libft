/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 18:10:33 by jblack-b          #+#    #+#             */
/*   Updated: 2019/01/08 01:55:08 by olesgedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include "get_next_line.h"

typedef struct s_etris	t_etris;

struct				s_etris
{
	char				**value;
	int 					valid;
	t_etris				*last;
	unsigned char		id;
	unsigned char		x;
	unsigned char		y;
	unsigned char		width;
	unsigned char		height;
};

void		ft_count_nieghbors(int j, int k, int *count, char **temp)
{
	if (temp[j][k] == '#')
	{
		*count += 1;
		if (k - 1 >= 0 && temp[j][k - 1] == '#')
			*count += 1;
		if (k + 1 <= 3 && temp[j][k + 1] == '#')
			*count += 1;
		if (j - 1 >= 0 && temp[j - 1][k] == '#')
			*count += 1;
		if (j + 1 <= 3 && temp[j + 1][k] == '#')
			*count += 1;
	}
}

int		ft_checkwidth(char **figure, int j, int *map)
{
	if (ft_strlen(figure[j]) != 4)
		*map = 0;
	return (*map);
}

int		ft_validate(t_etris *figure)
{
	int		j;
	int		k;
	int		count;
	int		map;

	map = 1;
	j = 0;
	count = 0;
	while (j < 4)
	{
		k = 0;
		ft_checkwidth(figure->value, j, &map);
		while (k < 4)
		{
			if ((figure->value)[j][k] != '#' && (figure->value)[j][k] != '.')
				map = 0;
			ft_count_nieghbors(j, k++, &count, figure->value);
		}
		j++;
	}
	if ((count == 10 || count == 12) && map == 1)
		figure->valid = 1;
	else
		figure->valid = 0;
	return (figure->valid);
}
int		ft_getsizeY(t_etris *figure)
{
	int j;
	int start;
	int end;
	int temp;

	j = 0;
	start = -1;
	while (j < 4)
	{
		if (ft_strchr(figure->value[j], '#'))
		{
			if (start == -1)
				start = j;
			end = j;
		}
		j++;
	}
	figure->height = end - start + 1;
	figure->y = start;
	return (end - start + 1);
}


int		ft_getsizeX(t_etris *figure)
{
	int j;
	int k;
	int start;
	int end;

	start = 5;
	j = 0;
	while (j < 4)
	{
		k = 0;
		while (k < 4)
		{
			if (figure->value[j][k] == '#')
			{
				if (start > k)
					start = k;
				if (end < k)
					end = k;
			}
			k++;
		}
		j++;
	}
	figure->width = end - start + 1;
	figure->x = start;
	return (end - start + 1);
}

char		**ft_normfigure(char **dst, t_etris *figure, int x, int y)
{
	int j;
	int k;
	j = figure->y;
	while (j < figure->height + figure->y)
	{
		k = figure->x;
		printf("k:%d j:%d", k, j);
		while (k < figure->width + figure->x)
		{
			if (figure->value[j][k] == '#')
			{
				figure->value[j - figure->y][k - figure->x] = \
				figure->value[j][k];
				figure->value[j][k] = '.';
			}
			k++;
		}
		j++;
	}
	return (dst);
}

char**		ft_2darraynew(size_t y, size_t x, char c)
{
	char** new;
	size_t j;
	size_t k;

	if (!(new = (char **)(malloc(sizeof(char *) * y + 1))))
		return (NULL);
	new[y] = NULL;

	j = 0;
	while (j < y)
	{
		if (!(new[j]= (char *)(malloc(sizeof(char ) * x + 1))))
			return (NULL);
		new[j][x] = '\0';
		k = 0;
		while (k < x)
		{
			new[j][k] = c;
			k++;
		}
		j++;
	}
	return()
}
char		**ft_putfigure(char **dst, t_etris *figure, int x, int y)
{
	int j;
	int k;
	j = figure->y;
	while (j < figure->height + figure->y)
	{
		k = figure->x;
		printf("k:%d j:%d", k, j);
		while (k < figure->width + figure->x)
		{
			if (figure->value[j][k] == '#')
			{
				dst[j + y][k + x] = \
				figure->value[j][k];
			}
			k++;
		}
		j++;
	}
	return (dst);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		fd2;

	char **matrix;
	int i;
	t_etris *figures[4];
	uint64_t temp;
	int j;
	char *line;

	j = 0;
	while (j < 4)
	{
		figures[j] = malloc(sizeof(t_etris));
		figures[j]->value = malloc(sizeof(char *) * 5);
		figures[j++]->value[5] = NULL;
	}
	matrix = (char **)(malloc(sizeof(char *) * 5));
	matrix[4] = NULL;
	i = 0;
	if (argc < 2)
	{
		ft_putstr("ERROR");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	j = 0;
	while (j < 4)
	{
		while (get_next_line(fd, &line) && i < 4)
		{
			figures[j]->value[i] = ft_strdup(line);
			i++;
			free(line);
		}
		i = 0;
		j++;
	}
	i = 0;
	while (i < 4)
	{

		printf("%d y:%d x:%d\n", ft_validate(figures[i]), ft_getsizeY(figures[i]), ft_getsizeX(figures[i]));
	//	printf("%d, %d\n", figures[i]->x, figures[i]->y);
		//figures[i]->value[figures[i]->y][figures[i]->x] = 'S';
		ft_normfigure(figures[i]->value, figures[i], 0, 0);
		//ft_putfigure(figures[i]->value, figures[i], 0, 1);
		//ft_printmap(figures[i]->value);
		i++;
	}
	return (0);
}

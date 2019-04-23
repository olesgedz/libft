
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int ft_test_cmp(void *s1, void *s2)
{
	return(*(char *)s1-*(char *)s2);
}

void		ft_rb_remove(struct s_rb_node **root, void *data,\
		int (*cmpf)(void *, void *), void (*freef)(void *))
{

}

int			main(void)
{
	t_rb_node *rb_tree;
	rb_tree = ft_rb_node_create("hello");
	ft_rb_insert(&rb_tree, "a", ft_test_cmp);
	ft_rb_insert(&rb_tree, "b", ft_test_cmp);
	ft_rb_insert(&rb_tree, "e", ft_test_cmp);
	ft_rb_insert(&rb_tree, "z", ft_test_cmp);
	ft_rb_insert(&rb_tree, "i", ft_test_cmp);
	ft_rb_insert(&rb_tree, "f", ft_test_cmp);
	ft_rb_insert(&rb_tree, "z", ft_test_cmp);
	ft_rb_insert(&rb_tree, "a", ft_test_cmp);
	ft_rb_insert(&rb_tree, "b", ft_test_cmp);
	ft_rb_insert(&rb_tree, "e", ft_test_cmp);
	ft_rb_insert(&rb_tree, "z", ft_test_cmp);
	ft_rb_insert(&rb_tree, "i", ft_test_cmp);
	ft_rb_insert(&rb_tree, "f", ft_test_cmp);
	ft_rb_insert(&rb_tree, "z", ft_test_cmp);
	ft_rb_node_print(rb_tree, 10);
}


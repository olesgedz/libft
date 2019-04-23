
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int ft_test_cmp(void *s1, void *s2)
{
    return(*(char *)s1-*(char *)s2);
}

//void rb_remove(struct s_rb_node **root, void *data, int (*cmpf)(void *, void *), void (*freef)(void *));

t_rb_node *ft_rb_node_create(void *data)
{
    t_rb_node *new_node;

    if(!(new_node = (t_rb_node *)malloc(sizeof(t_rb_node))))
        return (NULL);
    new_node->data = data;
    new_node->parent = NULL;
    new_node->right = NULL;
    new_node->left = NULL;
    new_node->color = RB_BLACK;
    return (new_node);
}

t_rb_node *ft_rb_node_parent(t_rb_node * node)
{
    return (node->parent);
}

t_rb_node *ft_rb_node_grandparent(t_rb_node *node)
{
 t_rb_node *parent = ft_rb_node_parent(node);
 if (parent == NULL)
  return (NULL);
 return (ft_rb_node_parent(parent)); 
}

t_rb_node *ft_rb_node_sibling(t_rb_node * n)
{
    t_rb_node *p = ft_rb_node_parent(n);
    if (p == NULL)
        return (NULL); 
    if (n == p->left)
        return (p->right);
    else
        return (p->left);
}

t_rb_node *ft_rb_node_uncle(t_rb_node *n) {
 t_rb_node *p = ft_rb_node_parent(n);
 t_rb_node *g = ft_rb_node_grandparent(n);
 if (g == NULL)
  return (NULL);
 return (ft_rb_node_sibling(p));
}

void rotate_left(t_rb_node *n) {
 t_rb_node *nnew = n->right;
 t_rb_node *p = ft_rb_node_parent(n);
 n->right = nnew->left; 
 nnew->left = n;
 n->parent = nnew;
 // handle other child/parent pointers
 if (n->right != NULL)
  n->right->parent = n;
 if (p != NULL) // initially n could be the root
 {
  if (n == p->left)
   p->left = nnew;
  else if (n == p->right) // if (...) is excessive
   p->right = nnew;
 }
 nnew->parent = p;
}

void rotate_right(t_rb_node *n) {
 t_rb_node *nnew = n->left;
 t_rb_node *p = ft_rb_node_parent(n);
 n->left = nnew->right;
 nnew->right = n;
 n->parent = nnew;
 // handle other child/parent pointers
 if (n->left != NULL)
  n->left->parent = n;
 if (p != NULL) // initially n could be the root
 {
  if (n == p->left)
   p->left = nnew;
  else if (n == p->right) // if (...) is excessive
   p->right = nnew;
 }
 nnew->parent = p;
}

t_rb_node *insert(t_rb_node *root, t_rb_node *n) {
 // insert new node into the current tree
 insert_recurse(root, n);

 // repair the tree in case any of the red-black properties have been violated
 insert_repair_tree(n);

 // find the new root to return
 root = n;
 while (ft_rb_node_parent(root) != NULL)
  root = ft_rb_node_parent(root);
 return root;
}

void insert_recurse(t_rb_node *root, t_rb_node *n) {
 // recursively descend the tree until a leaf is found
 if (root != NULL && n->key < root->key)
{
  if (root->left != NULL) {
   insert_recurse(root->left, n);
   return;
  }
  else
   root->left = n;
 } else if (root != NULL) {
  if (root->right != NULL){
   insert_recurse(root->right, n);
   return;
  }
  else
   root->right = n;
 }

 // insert new node n
 n->parent = root;
 n->left = LEAF;
 n->right = LEAF;
 n->color = RED;
}

void ft_rb_insert(t_rb_node **root, void *data, int (*cmpf)(void *, void *))
{
    t_rb_node *new;

    if (*root != NULL && cmpf(data, (*root)->data) < 0)
    {
        if  ((*root)->left != NULL)
        {
            ft_rb_insert(&(*root)->left, data, cmpf);
                return;
        } 
        else
            (*root)->left = ft_rb_node_create(data);
    } else if (root != NULL)
    {
        if  ((*root)->right != NULL)
        {
            ft_rb_insert(&(*root)->right, data, cmpf);
                return;
        } 
        else
        {
            (*root)->right = ft_rb_node_create(data);]
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           }
               
    }

    // if (*root == NULL)
    // {
    //     *root = ft_rb_node_create(data);
    //     (*root)->color = RB_BLACK;
    // }
    // else
    // {
    //     if(cmpf(data, (*root)->data) < 0)
    //     {
    //         if ((*root)->left == NULL)
    //         {
    //             (*root)->left->parent = *root;
    //             ft_rb_insert(&(*root)->left, data, cmpf);

    //         }
    //     }
    //     // else
    //     // {
    //     //     if ((*root)->right == NULL)
    //     //     {
    //     //         (*root)->right = ft_rb_node_create(data);
    //     //         (*root)->right->parent = *root;
    //     //         ft_rb_insert(&(*root)->right, data, cmpf);

    //     //     }
    //     // }
    //     printf("hjh\n");
    //     if ((*root)->right && (*root)->left)
    //         (*root)->color = RB_RED;
    // }
    
}

void ft_rb_node_print(t_rb_node *root, int spaces)
{
  if (root == NULL)
    return;
  spaces += 5;
  ft_rb_node_print(root->right, spaces);
  ft_putstr("\n");
  for (int i = 5; i < spaces; i++)
    ft_putstr(" ");
  ft_putstr(root->data);
    if (root->color == RB_RED)
        ft_putstr("-R");
    else
        ft_putstr("-B");
  ft_rb_node_print(root->left, spaces);
}

int			main(void)
{
    t_rb_node *rb_tree;
    rb_tree = ft_rb_node_create("hello");
    ft_rb_insert(&rb_tree, "cool", ft_test_cmp);
    ft_rb_insert(&rb_tree, "z1ool", ft_test_cmp);
    ft_rb_insert(&rb_tree, "co2ol", ft_test_cmp);
    ft_rb_insert(&rb_tree, "coo3l", ft_test_cmp);
    ft_rb_node_print(rb_tree, 5);
   // printf("%s\n", )

// 	t_btree		*root;
// 	t_btree   *root_2;
// 	t_btree   *found;
	
// 	root_2 = 0;

// 	root = ft_btree_create_node("F");
// 	root->left = ft_btree_create_node("D");
// 	root->left->left = ft_btree_create_node("B");
// 	root->left->right = ft_btree_create_node("E");
// 	root->left->left->left = ft_btree_create_node("A");
// 	root->left->left->right = ft_btree_create_node("C");
// 	root->right = ft_btree_create_node("J");
// 	root->right->left = ft_btree_create_node("G");
// 	root->right->right = ft_btree_create_node("K");
// 	root->right->left->right = ft_btree_create_node("I");
// 	root->right->left->right->left = ft_btree_create_node("H");
  
//   printf("Printing Tree...\n");
// 	ft_btree_apply_infix(root, ft_print_node);
	
// 	printf("\n\nInserting new node...\n");
// 	ft_btree_insert_data(&root, "Z", ft_test_cmp);
	
// 	printf("\n\nPrinting Tree...\n");
// 	ft_btree_apply_infix(root_2, ft_print_node);
	
// 	printf("\n\nSearching for Node...\n");
// 	found = ft_btree_search_item(root, "A", ft_test_cmp);
// 	printf("Found data: %s\n", found->item);
	
// 	printf("\n\nCounting Levels...\n");
// 	printf("Number of levels: %d\n", ft_btree_level_count(root));

//     ft_btree_print(root, 5);

}
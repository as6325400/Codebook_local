#include <stdio.h>
#include <stdlib.h>

struct node
{
  int val;
  struct node *left, *right;
} typedef node;

node *insert(node *now, int val)
{
  if (now == NULL)
  {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->val = val;
    newnode->left = newnode->right = NULL;
    return newnode;
  }
  if (now->val > val)
  {
    now->left = insert(now->left, val);
  }
  else if (now->val < val)
  {
    now->right = insert(now->right, val);
  }
  return now;
}

node *deletenode(node *now, int val)
{
  if (now == NULL)
    return now;
  if (now->val > val)
  {
    now->left = deletenode(now->left, val);
  }
  else if (now->val < val)
  {
    now->right = deletenode(now->right, val);
  }
  else
  {
    if (now->left == NULL)
    {
      node *tmp = now->right;
      free(now);
      return tmp;
    }
    else if (now->right == NULL)
    {
      node *tmp = now->left;
      free(now);
      return tmp;
    }
    else
    {
      node *tmp = now->right;
      while (tmp->left)
        tmp = tmp->left;
      now->val = tmp->val;
      now->right = deletenode(now->right, now->val);
    }
  }
  return now;
}
/*
** list.c for rtv1 in /home/thibaud/rendu/MUL_2013_rtv1
**
** Made by thibaud
** Login   <thibaud@epitech.net>
**
** Started on  Wed Feb 26 14:16:33 2014 thibaud
** Last update Thu Apr 24 14:40:33 2014 romaric
*/

#include "rtv1.h"

t_spot		*creat_spot_list()
{
  t_spot        *root;

  if ((root = malloc(sizeof (t_spot))) == NULL)
    exit(-1);
  root->x = 0;
  root->y = 0;
  root->z = 0;
  root->color = 0x000000;
  root->next = NULL;
  return (root);
}

int		ad_spot(t_spot *list, int x, int y, int z, int color)
{
  t_spot        *new_elem;

  while (list->next != NULL)
    list = list->next;
  if ((new_elem = malloc(sizeof (t_spot))) == NULL)
    exit(-1);
  new_elem->next = NULL;
  new_elem->x = x;
  new_elem->y = y;
  new_elem->z = z;
  new_elem->color = color;
  list->next = new_elem;
  return (0);
}

t_obj		*creat_obj_list()
{
  t_obj		*root;
  int		color;

  color = 0x000000;
  if ((root = malloc(sizeof (t_obj ))) == NULL)
    exit(-1);
  root->next = NULL;
  root->color = color;
  root->R = 0;
  root->type = NULL;
  root->angle = NULL;
  return (root);
}

int		ad_obj(t_obj *list, char *type
		       , int R, int color, t_vec3 *pos, t_vec3 *angle)
{
  t_obj		*new_elem;

  while (list->next != NULL)
    list = list->next;
  if ((new_elem = malloc(sizeof (t_obj))) == NULL)
    exit(-1);
  new_elem->next = NULL;
  new_elem->R = R;
  new_elem->color = color;
  if ((new_elem->pos = malloc(sizeof (pos))) == NULL)
    exit(-1);
  if ((new_elem->angle = malloc(sizeof (angle))) == NULL)
    exit(-1);
  new_elem->pos->x = pos->x;
  new_elem->pos->y = pos->y;
  new_elem->pos->z = pos->z;
  new_elem->angle->x = angle->x;
  new_elem->angle->y = angle->y;
  new_elem->angle->z = angle->z;
  list->next = new_elem;
  new_elem->type = type;
  return (0);
}

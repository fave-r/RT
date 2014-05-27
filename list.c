/*
** list.c for rtv1 in /home/thibaud/rendu/MUL_2013_rtv1
**
** Made by thibaud
** Login   <thibaud@epitech.net>
**
** Started on  Wed Feb 26 14:16:33 2014 thibaud
** Last update Tue May 27 22:54:49 2014 bourrel
*/

#include "rtv1.h"

t_spot		*creat_spot_list()
{
  t_spot	*root;

  root = xmalloc(sizeof(t_spot));
  root->x = 0;
  root->y = 0;
  root->z = 0;
  root->color = 0x000000;
  root->next = NULL;
  return (root);
}

int		ad_spot(t_spot *list, int color, t_vec3 *pos)
{
  t_spot        *new_elem;

  while (list->next != NULL)
    list = list->next;
  new_elem = xmalloc(sizeof(t_spot));
  new_elem->next = NULL;
  new_elem->x = pos->x;
  new_elem->y = pos->y;
  new_elem->z = pos->z;
  new_elem->color = color;
  list->next = new_elem;
  return (0);
}

t_obj		*creat_obj_list()
{
  t_obj		*root;

  root = xmalloc(sizeof(t_obj));
  root->next = NULL;
  root->info = NULL;
  root->angle = NULL;
  root->pos = NULL;
  return (root);
}

int		ad_obj(t_obj *list, t_info *info, t_vec3 *pos, t_vec3 *angle)
{
  t_obj		*new_elem;

  while (list->next != NULL)
    list = list->next;
  new_elem = xmalloc(sizeof(t_obj));
  new_elem->next = NULL;
  new_elem->info = xmalloc(sizeof(*info));
  new_elem->pos = xmalloc(sizeof(*pos));
  new_elem->angle = xmalloc(sizeof(*angle));
  new_elem->info->type = info->type;
  new_elem->info->R = info->R;
  new_elem->info->color = info->color;
  new_elem->pos->x = pos->x;
  new_elem->pos->y = pos->y;
  new_elem->pos->z = pos->z;
  new_elem->angle->x = angle->x;
  new_elem->angle->y = angle->y;
  new_elem->angle->z = angle->z;
  list->next = new_elem;
  new_elem = NULL;
  return (0);
}

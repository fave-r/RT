/*
** moove_obj.c for rtv1 in /home/thibaud/rendu/MUL_2013_rtv1
**
** Made by thibaud
** Login   <thibaud@epitech.net>
**
** Started on  Thu Mar  6 16:09:23 2014 thibaud
** Last update Thu Apr 24 14:28:37 2014 romaric
*/

#include "rtv1.h"

int     translate_pos(t_vec3 *pos, t_vec3 *go_to)
{
  pos->x = pos->x - go_to->x;
  pos->y = pos->y - go_to->y;
  pos->z = pos->z - go_to->z;
  return (0);
}

int     translate_pos_inv(t_vec3 *pos, t_vec3 *go_to)
{
  pos->x = pos->x + go_to->x;
  pos->y = pos->y + go_to->y;
  pos->z = pos->z + go_to->z;
  return (0);
}

int     place_obj(t_vec3 *pos, t_vec3 *dir, t_vec3 *go_to, t_vec3 *rotate)
{
  rotate_all(dir, rotate);
  translate_pos(pos, go_to);
  return (0);
}

int     place_obj_inv(t_vec3 *pos, t_vec3 *dir, t_vec3 *go_to, t_vec3 *rotate)
{
  rotate_all_inv(dir, rotate);
  translate_pos_inv(pos, go_to);
  return (0);
}

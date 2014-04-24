/*
** ombre.c for rtv1 in /home/thibaud/rendu/MUL_2013_rtv1
**
** Made by thibaud
** Login   <thibaud@epitech.net>
**
** Started on  Thu Mar  6 16:25:10 2014 thibaud
** Last update Thu Apr 24 14:31:14 2014 romaric
*/

#include "rtv1.h"

t_vec3		*inter_obj(t_eye *eye, float k)
{
  t_vec3        *result;

  result = malloc(sizeof(t_vec3 *));
  result->x = eye->pos->x + (k * eye->dir->x);
  result->y = eye->pos->y + (k * eye->dir->y);
  result->z = eye->pos->z + (k * eye->dir->z);
  return (result);
}

t_vec3		*to_light_(t_vec3 *inter, t_spot *spot)
{
  t_vec3        *result;

  result = malloc(sizeof(t_vec3 *));
  result->x = spot->x - inter->x;
  result->y = spot->y - inter->y;
  result->z = spot->z - inter->z;
  return (result);
}

int     put_ombre(int color, int nb)
{
  int   col[3];
  float ombre;
  ombre = 1;
  if (nb > 0)
    ombre = 0.4 / nb;
  col[2] = (color / (256 * 256));
  col[1] = (color % (256 * 256)) / 256;
  col[0] = color % 256;
  col[0] = col[0] * ombre;
  col[1] = col[1] * ombre;
  col[2] = col[2] * ombre;
  color = (col[0]) + (256 * col[1]) + (256 * 256 * col[2]);
  return (color);
}

int		ombre(t_obj *obj, t_eye *eye
		      , t_obj *clos_obj, float k2, t_spot *cur_spot)
{
  t_obj         *cur_obj;
  t_vec3        *inter;
  t_vec3        *vec_light;

  cur_obj = obj->next;
  inter = inter_obj(eye, k2);
  vec_light = to_light_(inter, cur_spot);
  while (cur_obj != NULL)
    {
      if (cur_obj != clos_obj)
        {
	  translate_pos(inter, cur_obj->pos);
          k2 = tab[find_type(cur_obj)].inter(inter, vec_light, cur_obj->R);
	  translate_pos_inv(inter, cur_obj->pos);
          if (k2 > ZERO && k2 < 1 + ZERO)
            return (1);
        }
      cur_obj = cur_obj->next;
    }
  free(inter);
  free(vec_light);
  return (0);
}

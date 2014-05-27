/*
** ombre.c for rtv1 in /home/thibaud/rendu/MUL_2013_rtv1
**
** Made by thibaud
** Login   <thibaud@epitech.net>
**
** Started on  Thu Mar  6 16:25:10 2014 thibaud
** Last update Tue May 27 15:02:29 2014 bourrel
*/

#include "rtv1.h"

t_vec3		*inter_obj(t_eye *eye, float k)
{
  t_vec3        *result;

  result = xmalloc(sizeof(t_vec3));
  result->x = eye->pos->x + (k * eye->dir->x);
  result->y = eye->pos->y + (k * eye->dir->y);
  result->z = eye->pos->z + (k * eye->dir->z);
  return (result);
}

t_vec3		*to_light_(t_vec3 *inter, t_spot *spot)
{
  t_vec3        *result;

  result = xmalloc(sizeof(t_vec3));
  result->x = spot->x - inter->x;
  result->y = spot->y - inter->y;
  result->z = spot->z - inter->z;
  return (result);
}

int		put_ombre(int color, int nb)
{
  int		col[3];
  float		ombre;
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

int		ombre(t_obj *obj, t_eye *eye, t_obj *clos_obj, float k2, t_spot *cur_spot)
{
  t_obj         *c_obj;
  t_vec3        *inter;
  t_vec3        *vec_light;

  c_obj = obj->next;
  inter = inter_obj(eye, k2);
  vec_light = to_light_(inter, cur_spot);
  while (c_obj != NULL)
    {
      if (c_obj != clos_obj)
        {
	  translate_pos(inter, c_obj->pos);
          k2 = tab[find_type(c_obj)].inter(inter, vec_light, c_obj->info->R);
	  translate_pos_inv(inter, c_obj->pos);
          if (k2 > ZERO && k2 < 1 + ZERO)
            return (1);
        }
      c_obj = c_obj->next;
    }
  free(inter);
  free(vec_light);
  return (0);
}

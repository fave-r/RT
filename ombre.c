/*
** ombre.c for rtv1 in /home/thibaud/rendu/MUL_2013_rtv1
**
** Made by thibaud
** Login   <thibaud@epitech.net>
**
** Started on  Thu Mar  6 16:25:10 2014 thibaud
** Last update Fri Jun  6 16:03:18 2014 bourrel
*/

#include "rt.h"

t_vec3		*inter_obj(t_vec3 *result, t_eye *eye, float k)
{
  result->x = eye->pos->x + (k * eye->dir->x);
  result->y = eye->pos->y + (k * eye->dir->y);
  result->z = eye->pos->z + (k * eye->dir->z);
  return (result);
}

t_vec3		*to_light_(t_vec3 *inter, t_spot *spot)
{
  t_vec3        *result;

  result = xmalloc(sizeof(*result));
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

int		free_inter(int ret, t_vec3 *inter, t_vec3 *vec_light)
{
  free(inter);
  free(vec_light);
  return (ret);
}

int		ombre(t_obj *obj, t_eye *eye, t_light l, t_spot *cur_spot)
{
  t_obj         *c_obj;
  t_vec3        *inter;
  t_vec3        *vec_light;

  c_obj = obj->next;
  inter = xmalloc(sizeof(*inter));
  inter = inter_obj(inter, eye, l.k2);
  vec_light = to_light_(inter, cur_spot);
  while (c_obj != NULL)
    {
      if (c_obj != l.clos_obj)
        {
	  translate_pos(inter, c_obj->pos);
	  l.k2 = tab[find_type(c_obj)].inter(inter, vec_light, c_obj->info->R);
	  translate_pos_inv(inter, c_obj->pos);
          if (l.k2 > ZERO && l.k2 < 1 + ZERO)
	    return (free_inter(1, inter, vec_light));
        }
      c_obj = c_obj->next;
    }
  return (free_inter(0, inter, vec_light));
}

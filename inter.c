/*
** inter.c for rtv1 in /home/thibaud/rendu/MUL_2013_rtv1
**
** Made by thibaud
** Login   <thibaud@epitech.net>
**
** Started on  Wed Feb 26 14:21:52 2014 thibaud
** Last update Tue Jun  3 19:24:26 2014 odet
*/

#include "rt.h"

float		inter_sphere(t_vec3 *pos, t_vec3 *dir, int R)
{
  float		delta;
  float		k1;
  float		k2;
  float		c[3];

  k1 = ZERO;
  c[0] = (dir->x * dir->x) + (dir->y * dir->y) + (dir->z * dir->z);
  c[1] = 2 * ((pos->x * dir->x) + (pos->y * dir->y) + (pos->z * dir->z));
  c[2] = (pos->x * pos->x) + (pos->y * pos->y) + (pos->z * pos->z) - (R * R);
  delta = (c[1] * c[1]) - (4 * c[0] * c[2]);
  if (delta >= ZERO)
    {
      k1 = (((c[1] * (-1)) - sqrt(delta)) / (2 * c[0]));
      k2 = ((((-1) * c[1]) + sqrt(delta)) / (2 * c[0]));
      if (k2 < k1 && k2 >= ZERO)
        k1 = k2;
    }
  else
    return (-1);
  return (k1);
}

float		inter_plan(t_vec3 *pos, t_vec3 *dir, int R)
{
  float		k;

  (void)R;
  k = ZERO;
  if (dir->z != ZERO)
    k = (-pos->z / dir->z);
  return (k);
}

float		cut_obj(float k1, t_vec3 *pos, t_vec3 *dir)
{
  t_eye		eye_tmp;
  t_vec3	*inter;
  float		x;
  float		y;

  x = ZERO - 800;
  y = ZERO;
  eye_tmp.pos = pos;
  eye_tmp.dir = dir;
  inter = xmalloc(sizeof(*inter));
  inter = inter_obj(inter, &eye_tmp, k1);
  if (inter->z < x || inter->z > y)
    {
      free(inter);
      return (ZERO);
    }
  free(inter);
  return (k1);
}

float		inter_cone(t_vec3 *pos, t_vec3 *dir, int R)
{
  float		delta;
  float		k1;
  float		k2;
  float		c[3];

  k1 = -1;
  k2 = 0;
  c[0] = (pow(dir->x, 2) + pow(dir->y, 2)) - pow(dir->z, 2)
    * tan(rad_conv(R));
  c[1] = (pos->x * dir->x) + (pos->y * dir->y) -
    ((pos->z * dir->z) * tan(rad_conv(R)));
  c[1] *= 2;
  c[2] = (pow(pos->x, 2) + pow(pos->y, 2)) -
    pow(pos->z, 2) * tan(rad_conv(R));
  delta = pow(c[1], 2) - 4 * (c[0] * c[2]);
  if (delta >= ZERO)
    {
      k1 = (((c[1] * (-1)) - sqrt(delta)) / (2 * c[0]));
      k2 = ((((-1) * c[1]) + sqrt(delta)) / (2 * c[0]));
      if (k2 < k1 && k2 >= ZERO)
	k1 = k2;
    }
  return (k1);
}

/*
** rotation.c for rtv1 in /home/thibaud/rendu/MUL_2013_rtv1
**
** Made by thibaud
** Login   <thibaud@epitech.net>
**
** Started on  Thu Feb 20 00:54:53 2014 thibaud
** Last update Sun Jun  8 20:55:41 2014 romaric
*/

#include "rt.h"

void		rotx(t_vec3 *vec, float angle)
{
  float		tmp[3];

  tmp[0] = vec->x;
  tmp[1] = vec->y;
  tmp[2] = vec->z;
  vec->y = cosf(angle) * tmp[1] - sinf(angle) * tmp[2];
  vec->z = sinf(angle) * tmp[1] + cosf(angle) * tmp[2];
}

void		roty(t_vec3 *vec, float angle)
{
  float		tmp[3];

  tmp[0] = vec->x;
  tmp[1] = vec->y;
  tmp[2] = vec->z;
  vec->x = cosf(angle) * tmp[0] + sinf(angle) * tmp[2];
  vec->z = -1 * sinf(angle) * tmp[0] + cosf(angle) * tmp[2];
}

void		rotz(t_vec3 *vec, float angle)
{
  float		tmp[3];

  tmp[0] = vec->x;
  tmp[1] = vec->y;
  tmp[2] = vec->z;
  vec->x = cosf(angle) * tmp[0] - sinf(angle) * tmp[1];
  vec->y = sinf(angle) * tmp[0] + cosf(angle) * tmp[1];
}

void		rotate_all(t_vec3 *dir, t_vec3 *angle)
{
  rotx(dir, rad_conv(angle->x));
  roty(dir, rad_conv(angle->y));
  rotz(dir, rad_conv(angle->z));
}

void		rotate_all_inv(t_vec3 *dir, t_vec3 *angle)
{
  rotx(dir, -rad_conv(angle->x));
  roty(dir, -rad_conv(angle->y));
  rotz(dir, -rad_conv(angle->z));
}

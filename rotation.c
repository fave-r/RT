/*
** rotation.c for rtv1 in /home/thibaud/rendu/MUL_2013_rtv1
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Thu Feb 20 00:54:53 2014 thibaud
** Last update Sat Mar  8 16:11:00 2014 thibaud
*/

#include "rtv1.h"

void	rotX(t_vec3 *vec, float angle)
{
  float	tmp[3];

  tmp[0] = vec->x;
  tmp[1] = vec->y;
  tmp[2] = vec->z;
  vec->y = cosf(angle) * tmp[1] - sinf(angle) * tmp[2];
  vec->z = sinf(angle) * tmp[1] + cosf(angle) * tmp[2];
}

void	rotY(t_vec3 *vec, float angle)
{
  float	tmp[3];

  tmp[0] = vec->x;
  tmp[1] = vec->y;
  tmp[2] = vec->z;
  vec->x = cosf(angle) * tmp[0] + sinf(angle) * tmp[2];
  vec->z = -1 * sinf(angle) * tmp[0] + cosf(angle) * tmp[2];
}

void	rotZ(t_vec3 *vec, float angle)
{
  float	tmp[3];

  tmp[0] = vec->x;
  tmp[1] = vec->y;
  tmp[2] = vec->z;
  vec->x = cosf(angle) * tmp[0] - sinf(angle) * tmp[1];
  vec->y = sinf(angle) * tmp[0] + cosf(angle) * tmp[1];
}

void            rotate_all(t_vec3 *pos, t_vec3 *angle)
{
  rotX(pos, rad_conv(angle->x));
  rotY(pos, rad_conv(angle->y));
  rotZ(pos, rad_conv(angle->z));
}

void            rotate_all_inv(t_vec3 *pos, t_vec3 *angle)
{
  rotX(pos, -rad_conv(angle->x));
  rotY(pos, -rad_conv(angle->y));
  rotZ(pos, -rad_conv(angle->z));
}

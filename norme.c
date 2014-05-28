/*
** norme.c for rtv1 in /home/thibaud/rendu/MUL_2013_rtv1
**
** Made by thibaud
** Login   <thibaud@epitech.net>
**
** Started on  Wed Feb 26 16:15:20 2014 thibaud
** Last update Wed May 28 00:29:57 2014 bourrel
*/

#include "rtv1.h"

t_vec3		*norme_plan(t_vec3 *inter)
{
  t_vec3	*result;

  (void)inter;
  result = xmalloc(sizeof(t_vec3));
  result->x = 0;
  result->y = 0;
  result->z = 100;
  return (result);
}

t_vec3		*norme_sphere(t_vec3 *inter)
{
  t_vec3	*result;

  result = xmalloc(sizeof(t_vec3));
  result->x = inter->x;
  result->y = inter->y;
  result->z = inter->z;
  return (result);
}

t_vec3		*norme_cylindre(t_vec3 *inter)
{
  t_vec3	*result;

  result = xmalloc(sizeof(t_vec3));
  result->x = inter->x;
  result->y = inter->y;
  result->z = inter->z * 0.2 + 200;
  return (result);
}

t_vec3		*norme_cone(t_vec3 *inter)
{
  t_vec3	*result;

  result = xmalloc(sizeof(t_vec3));
  result->x = inter->x;
  result->y = inter->y;
  result->z = inter->z * 0.2 + 50;
  return (result);
}

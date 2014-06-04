/*
** obj_color.c for RT in /home/leo/rendu/RT
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Wed Jun  4 17:32:20 2014 bourrel
** Last update Wed Jun  4 17:32:40 2014 bourrel
*/

#include "rt.h"

int	obj_color(t_light l, t_eye *eye, t_obj *obj, t_spot *spot)
{
  int	color;

  color = 0;
  if (l.clos_obj != NULL)
    {
      if (l.clos_obj->angle->x != 0 || l.clos_obj->angle->y != 0
          || l.clos_obj->angle->z != 0)
        {
          place_obj(eye->pos, eye->dir, l.clos_obj->pos, l.clos_obj->angle);
          color = gere_light(eye, l, obj, spot);
          place_obj_inv(eye->pos, eye->dir, l.clos_obj->pos, l.clos_obj->angle);
        }
      else
        color = gere_light(eye, l, obj, spot);
    }
  return (color);
}

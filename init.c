/*
** init.c for rtv1 in /home/thibaud/rendu/MUL_2013_rtv1
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Wed Feb 26 16:30:55 2014 thibaud
** Last update Tue May 27 15:01:59 2014 bourrel
*/

#include "rtv1.h"

void	init_info(char *type, int R, int color, t_info *info)
{
  info->type = type;
  info->R = R;
  info->color = color;
}

void    init_spot(t_spot *spot)
{
  spot->x = -400;
  spot->y = 0;
  spot->z = 200;
  spot->color = 0x000000;
}

int     init_obj_pos(float x, float y, float z, t_vec3 *pos)
{
  pos->x = x;
  pos->y = y;
  pos->z = z;
  return (0);
}

int     init_eye(t_eye *eye)
{
  eye->pos = xmalloc(sizeof(t_vec3));
  eye->dir = xmalloc(sizeof(t_vec3));
  eye->rotation = xmalloc(sizeof(t_vec3));
  eye->pos->x = -1000;
  eye->pos->y = 0;
  eye->pos->z = 50;
  eye->rotation->x = 0;
  eye->rotation->y = 0;
  eye->rotation->z = 0;
  return (0);
}

int	init_obj_angle(float x, float y, float z, t_vec3 *angle)
{
  angle->x = x;
  angle->y = y;
  angle->z = z;
  return (0);
}

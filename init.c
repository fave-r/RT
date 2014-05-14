/*
** init.c for rtv1 in /home/thibaud/rendu/MUL_2013_rtv1
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Wed Feb 26 16:30:55 2014 thibaud
<<<<<<< HEAD
** Last update Thu May  8 16:46:36 2014 thibaud
=======
** Last update Wed May 14 11:36:31 2014 bourrel
>>>>>>> 1721af264d0d2b50ef22ef68333e9dc06c2ef26b
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
  if ((eye->pos = malloc(sizeof(t_vec3))) == NULL)
    exit(-1);
  if ((eye->dir = malloc(sizeof(t_vec3))) == NULL)
    exit(-1);
  if ((eye->rotation = malloc(sizeof(t_vec3))) == NULL)
    exit(-1);
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

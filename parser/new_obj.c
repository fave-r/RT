/*
** new_obj.c for RT in /home/leo/rendu/RT/parser
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Wed May  7 01:24:27 2014 bourrel
** Last update Sun Jun  8 18:36:32 2014 bourrel
*/

#include "rt.h"

void		new_spot(char **tmp, t_spot *spot)
{
  int		color;
  t_vec3	pos;
  float         x;

  x = ZERO;
  init_obj_pos(x + atof(tmp[3]), x + atof(tmp[1]), x + atof(tmp[2]), &pos);
  if ((color = is_color(tmp[4])) == -1)
    {
      printf("Unknown color, please check your file !\n");
      exit(-1);
    }
  ad_spot(spot, color, &pos);
}

void		new_obj(char **tmp, t_obj *list)
{
  t_vec3	rot;
  t_vec3	pos;
  t_info	info;
  int		color;
  float		x;

  x = ZERO;
  if ((color = is_color(tmp[8])) == -1)
    {
      printf("Unknown color, please check your file !\n");
      exit(-1);
    }
  init_obj_angle(x + atof(tmp[4]), x + atof(tmp[5]), x + atof(tmp[6]), &rot);
  init_obj_pos(x + atof(tmp[3]), x + atof(tmp[1]), x + atof(tmp[2]), &pos);
  init_info(tmp[0], x + atof(tmp[7]), color, &info);
  ad_obj(list, &info, &pos, &rot);
}

/*
** new_obj.c for RT in /home/leo/rendu/RT/parser
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Wed May  7 01:24:27 2014 bourrel
** Last update Wed May 28 14:42:17 2014 lhomme
*/

#include <string.h>
#include "../rtv1.h"

void		new_spot(char **tmp, t_spot *spot)
{
  int		color;
  t_vec3	pos;

  init_obj_pos(atoi(tmp[3]), atoi(tmp[1]), atoi(tmp[2]), &pos);
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

  if ((color = is_color(tmp[8])) == -1)
    {
      printf("Unknown color, please check your file !\n");
      exit(-1);
    }
  init_info(tmp[0], atoi(tmp[7]), color, &info);
  init_obj_pos(atoi(tmp[3]), atoi(tmp[1]), atoi(tmp[2]), &pos);
  init_obj_angle(atoi(tmp[4]), atoi(tmp[5]), atoi(tmp[6]), &rot);
  if (my_strcompare("CONE", tmp[0]) || my_strcompare("cone", tmp[0]))
    ad_obj(list, &info, &pos, &rot);
  else
    ad_obj(list, &info, &pos, &rot);
}

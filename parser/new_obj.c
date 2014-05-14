/*
** new_obj.c for RT in /home/leo/rendu/RT/parser
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Wed May  7 01:24:27 2014 bourrel
** Last update Wed May 14 11:55:37 2014 bourrel
*/

#include <string.h>
#include "../rtv1.h"

int	is_color(char *str)
{
  if (my_strcompare("BLEU", str))
    return (BLEU);
  else if (my_strcompare("CYAN", str))
    return (CYAN);
  else if (my_strcompare("JAUNE", str))
    return (JAUNE);
  else if (my_strcompare("MAGENTA", str))
    return (MAGENTA);
  else if (my_strcompare("ROUGE", str))
    return (ROUGE);
  else if (my_strcompare("VERT", str))
    return (VERT);
  else if (my_strcompare("NOIR", str))
    return (NOIR);
  else if (my_strcompare("BLANC", str))
    return (BLANC);
  else if (my_strcompare("ORANGE", str))
    return (ORANGE);
  else
    return (-1);
}

void		new_spot(char **tmp, t_spot *spot)
{
  int		color;
  t_vec3	pos;

  init_obj_pos(atoi(tmp[3]), atoi(tmp[1]), atoi(tmp[2]), &pos);
  if ((color = is_color(tmp[4])) == -1)
    exit (-1);
  ad_spot(spot, color, &pos);
}

void		new_obj(char **tmp, t_obj *list)
{
  t_vec3	rot;
  t_vec3	pos;
  t_info	info;
  int		color;

  if ((color = is_color(tmp[8])) == -1)
    exit (-1);
  init_info(tmp[0], atoi(tmp[7]), color, &info); 
  init_obj_pos(atoi(tmp[3]), atoi(tmp[1]), atoi(tmp[2]), &pos);
  init_obj_angle(atoi(tmp[4]), atoi(tmp[5]), atoi(tmp[6]), &rot);
  if (my_strcompare("CONE", tmp[0]) || my_strcompare("cone", tmp[0]))
    ad_obj(list, &info, &pos, &rot);
  else
    ad_obj(list, &info, &pos, &rot);
}

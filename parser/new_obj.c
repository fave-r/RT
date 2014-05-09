/*
** new_obj.c for RT in /home/leo/rendu/RT/parser
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Wed May  7 01:24:27 2014 bourrel
** Last update Fri May  9 15:17:09 2014 bourrel
*/

#include <string.h>
#include "../rtv1.h"

char		*cpy_nbr(char *str, int i)
{
  char		*cpy;
  int	j;

  j = 0;
  cpy = malloc(sizeof(*cpy) * strlen(str) + 1);
  while (str[i])
    {
      cpy[j] = str[i];
      j++;
      i++;
    }
  return (str);
}

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

int		find_color(char *str)
{
  char	*cpy;
  int	ret;

  ret = 0;
  if (my_strncompare("0x", str, 2))
    {
      cpy = cpy_nbr(str, 2);
      ret = atoi(cpy);
      return (ret);
    }
  else if (str[0] >= '0' && str[0] <= '9')
    return (atoi(str));
  else if ((str[0] >= 'a' && str[0] <= 'z')
	   || (str[0] >= 'A' && str[0] <= 'Z'))
    return (is_color(str));
  else
    return (-1);
  return (1);
}

void		new_spot(char **tmp, t_spot *spot)
{
  int		nbr[3];
  int		j;
  t_vec3        pos;

  j = 0;
  while (j < 3)
    {
      nbr[j] = atoi(tmp[j + 1]);
      j++;
    }
  init_obj_pos(nbr[0], nbr[1], nbr[2], &pos);
  ad_spot(spot, nbr[0], nbr[1], nbr[2], ROUGE);
}

void		new_obj(char **tmp, t_obj *list)
{
  int		nbr[6];
  int		j;
  t_vec3	rot;
  t_vec3	pos;
  int		color;

  j = 0;
  while (j < 6)
    {
      nbr[j] = atoi(tmp[j + 1]);
      j++;
    }
  if ((color = find_color(tmp[7])) == -1)
    exit (-1);
  init_obj_pos(nbr[0], nbr[1], nbr[2], &pos);
  init_obj_angle(nbr[3], nbr[4], nbr[5], &rot);
  printf("%s\n%f\t%f\t%f\n%f\t%f\t%f\n\n", tmp[0],pos.x, pos.y, pos.z, rot.x, rot.y, rot.z);
  if (my_strcompare("CONE", tmp[0]) || my_strcompare("cone", tmp[0]))
    ad_obj(list, tmp[0], 3, color, &pos, &rot);
  else
    ad_obj(list, tmp[0], 100, color, &pos, &rot);
}

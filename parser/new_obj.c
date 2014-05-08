/*
** new_obj.c for RT in /home/leo/rendu/RT/parser
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Wed May  7 01:24:27 2014 bourrel
** Last update Thu May  8 22:46:28 2014 bourrel
*/

#include <string.h>
#include "../rtv1.h"

int     find_nbr(char *str, int *i)
{
  int   ret;
  char  *nb;
  int   j;
  int	neg;

  ret = 0;
  j = 0;
  neg = 0;
  nb = malloc(sizeof(*nb) * strlen(str));
  if (str[*i] == '-')
    {
      neg = 1;
      *i = *i + 1;
    }
  while (str[*i] >= '0' && str[*i] <= '9')
    {
      nb[j] = str[*i];
      j++;
      *i = *i + 1;
    }
  ret = atoi(nb);
  if (neg == 1)
    return (-ret);
  return (ret);
}

void		new_spot(char *str, t_spot *spot, int i)
{
  int		nbr[3];
  int		j;
  t_vec3        pos;

  j = 0;
  while (j < 3)
    {
      if (((str[i] >= '0' && str[i] <= '9') || str[i] == '-') && j < 3)
	{
	  nbr[j] = find_nbr(str, &i);
	  j++;
	}
      i++;
    }
  init_obj_pos(nbr[0], nbr[1], nbr[2], &pos);
  printf("Pos X :%d\nPos Y : %d\nPOS Z : %d\n\n", nbr[0], nbr[1], nbr[2]);
  ad_spot(spot, nbr[0], nbr[1], nbr[2], ROUGE);
}

void		new_obj(char *str, t_obj *list, int i, char *type)
{
  int		nbr[3];
  int		j;
  t_vec3	rot;
  t_vec3	pos;

  j = -1;
  while (j < 2)
    {
      if ((str[i] >= '0' && str[i] <= '9') && j < 3)
	nbr[++j] = find_nbr(str, &i);
      i++;
    }
  init_obj_pos(nbr[0], nbr[1], nbr[2], &pos);
  j = -1;
  while (j < 2)
    {
      if ((str[i] >= '0' && str[i] <= '9') && j < 3)
	nbr[++j] = find_nbr(str, &i);
      i++;
    }
  init_obj_angle(nbr[0], nbr[1], nbr[2], &rot);
  printf("Pos X : %f\nPos Y : %f\nPOS Z : %f\n", pos.x, pos.y, pos.z);
  printf("Rot X : %f\nRot Y : %f\nROT Z : %f\n", rot.x, rot.y, rot.z);
  ad_obj(list, type, 100, ROUGE, &pos, &rot);
}

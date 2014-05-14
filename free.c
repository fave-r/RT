/*
** free.c for rtv1 in /home/thibaud/rendu/MUL_2013_rtv1
**
** Made by thibaud
** Login   <thibaud@epitech.net>
**
** Started on  Sun Mar 16 20:46:52 2014 thibaud
** Last update Mon May 12 16:09:36 2014 bourrel
*/

#include "rtv1.h"

void	free_tab(char **tmp)
{
  int	i;

  i = 0;
  while (tmp[i])
    {
      free(tmp[i]);
      i++;
    }
  free(tmp);
}

int		free_eye(t_eye eye)
{
  free(eye.pos);
  free(eye.dir);
  free(eye.rotation);
  return (0);
}

int		free_all(t_obj *objs, t_spot *spots)
{
  free_spots(spots);
  free_objs(objs);
  return (0);
}

int		free_spots(t_spot *spots)
{
  t_spot        *tmp1;
  t_spot        *tmp2;

  if (spots != NULL)
    {
      tmp1 = spots;
      tmp2 = spots->next;
      while (tmp1 != NULL)
        {
          free(tmp1);
          tmp1 = tmp2;
          if (tmp2 != NULL)
            tmp2 = tmp2->next;
        }
    }
  return (0);
}

int		free_objs(t_obj *objs)
{
  t_obj		*tmp1;
  t_obj		*tmp2;

  if (objs != NULL)
    {
      tmp1 = objs;
      tmp2 = objs->next;
      while (tmp1!= NULL)
        {
          free(tmp1);
          tmp1 = tmp2;
          if (tmp2 != NULL)
            tmp2 = tmp2->next;
        }
    }
  return (0);
}

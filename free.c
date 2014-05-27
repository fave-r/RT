/*
** free.c for rtv1 in /home/thibaud/rendu/MUL_2013_rtv1
**
** Made by thibaud
** Login   <thibaud@epitech.net>
**
** Started on  Sun Mar 16 20:46:52 2014 thibaud
** Last update Tue May 27 23:15:54 2014 bourrel
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

  t_spot	*tmp;
  t_spot	*tmpnxt;

  tmp = spots;
  while (tmp != NULL)
    {
      tmpnxt = tmp->next;
      free(tmp);
      tmp = tmpnxt;
    }
  spots = tmp;
  return (0);
}

int		free_objs(t_obj *objs)
{
  t_obj		*tmp;
  t_obj		*tmpnxt;

  tmp = objs;
  while (tmp != NULL)
    {
      tmpnxt = tmp->next;
      free(tmp->pos);
      free(tmp->angle);
      free(tmp->info);
      free(tmp);
      tmp = tmpnxt;
    }
  objs = tmp;
  return (0);
}

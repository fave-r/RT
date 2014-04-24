/*
** basic_fct2.c for rtv1 in /home/thibaud/rendu/MUL_2013_rtv1
**
** Made by thibaud
** Login   <thibaud@epitech.net>
**
** Started on  Sat Mar 15 19:36:13 2014 thibaud
** Last update Thu Apr 24 14:34:21 2014 romaric
*/

#include "rtv1.h"

t_mlx		get_data(t_mlx mlx)
{
  int           bpp;
  int           sizeline;
  int           endian;

  mlx.data = mlx_get_data_addr(mlx.img_ptr, &bpp, &sizeline, &endian);
  return (mlx);
}

int		find_type(t_obj *obj)
{
  int		i;

  i = 0;
  while (my_strcmp(tab[i].type, "\0") != 0)
    {
      if ((my_strcmp(tab[i].type, obj->type) == 0))
        return (i);
      i++;
    }
  exit(-1);
  return (i);
}

int		*color_limit(int *col)
{
  if (col[0] > 255)
    col[0] = 255;
  if (col[1] > 255)
    col[1] = 255;
  if (col[2] > 255)
    col[2] = 255;
  return (col);
}

/*
** basic_fct.c for rtv1 in /home/thibaud/rendu/MUL_2013_rtv1
**
** Made by thibaud
** Login   <thibaud@epitech.net>
**
** Started on  Wed Feb 26 14:26:20 2014 thibaud
** Last update Wed May 28 15:29:54 2014 lhomme
*/

#include "rt.h"

int     my_strcmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  if (!s1)
    return (-1);
  else if (!s2)
    return (1);
  while (s1[i])
    {
      if (s1[i] < s2[i])
        return (-1);
      if (s1[i] > s2[i])
        return (1);
      i++;
    }
  if (s1[i] < s2[i])
    return (-1);
  if (s1[i] > s2[i])
    return (1);
  return (0);
}

float   rad_conv(float deg)
{
  float rad;

  rad = deg * M_PI * 2 / 360;
  return (rad);
}

int     gere_expose(t_mlx *mlx)
{
  mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
  return (0);
}

int     gere_key(int keycode)
{
  if (keycode == 65307)
    exit(0);
  return (0);
}

int     mlx_put_pixel(char *data, int x, int y, int color)
{
  char  *ptr;
  char  *color_ptr;

  ptr = data + y * 2400 + x * 4;
  color_ptr = (char *)&color;
  ptr[0] = color_ptr[0];
  ptr[1] = color_ptr[1];
  ptr[2] = color_ptr[2];
  return (0);
}

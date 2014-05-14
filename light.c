/*
** light.c for rtv1 in /home/thibaud/rendu/MUL_2013_rtv1
**
** Made by thibaud
** Login   <thibaud@epitech.net>
**
** Started on  Thu Mar  6 20:34:38 2014 thibaud
** Last update Wed May 14 11:44:26 2014 bourrel
*/

#include "rtv1.h"

int		final_lum(t_spot *spot)
{
  int		color;
  t_spot        *cur_spot;

  color = 0;
  cur_spot = spot->next;
  while (cur_spot != NULL)
    {
      color = ad_color(color, cur_spot->color);
      cur_spot = cur_spot->next;
    }
  return (color);
}

int		gere_light(t_eye *eye, float k2
			   , t_obj *clos_obj, t_obj *obj, t_spot *spot)
{
  int		color;
  t_spot        *cur_spot;
  int		ombre_nb;

  ombre_nb = 0;
  cur_spot = spot->next;
  color = clos_obj->info->color;
  while (cur_spot != NULL)
    {
      luminosite(eye, k2, clos_obj, cur_spot, color);
      ombre_nb += ombre(obj, eye, clos_obj, k2, cur_spot);
      cur_spot = cur_spot->next;
    }
  color = final_lum(spot);
  color = put_ombre(color, ombre_nb);
  return (color);
}

int		luminosite(t_eye *eye, float k2
			   , t_obj *clos_obj, t_spot *spot, int color)
{
  t_vec3        *inter;
  t_vec3        *vec_light;
  float         result;
  t_vec3        *norme;

  inter = inter_obj(eye, k2);
  norme = tab[find_type(clos_obj)].norme(inter);
  vec_light = to_light_(inter, spot);
  result = (norme->x * vec_light->x + norme->y
	    * vec_light->y + norme->z * vec_light->z) /
    ((sqrt(pow(norme->x, 2) + pow(norme->y, 2) + pow(norme->z, 2)) *
      sqrt(pow(vec_light->x, 2)
	   + pow(vec_light->y, 2) + pow(vec_light->z, 2))));
  spot->color = put_lum(color, result);
  free(inter);
  free(vec_light);
  free(norme);
  return (spot->color);
}

int		ad_color(int color1, int color2)
{
  int		col[3];
  int		col1[3];
  int		col2[3];
  int		result;

  col1[2] = (color1 / (256 * 256));
  col1[1] = (color1 % (256 * 256)) / 256;
  col1[0] = color1 % 256;
  col2[2] = (color2 / (256 * 256));
  col2[1] = (color2 % (256 * 256)) / 256;
  col2[0] = color2 % 256;
  col[2] = col1[2] + col2[2];
  col[1] = col1[1] + col2[1];
  col[0] = col1[0] + col2[0];
  color_limit(col);
  result = (col[0]) + (256 * col[1]) + (256 * 256 * col[2]);
  return (result);
}

int		put_lum(int color, float result)
{
  int		col[3];

  if (result > ZERO)
    {
      col[2] = (color / (256 * 256));
      col[1] = (color % (256 * 256)) / 256;
      col[0] = color % 256;
      col[0] = col[0] * result;
      col[1] = col[1] * result;
      col[2] = col[2] * result;
      color_limit(col);
      color = (col[0]) + (256 * col[1]) + (256 * 256 * col[2]);
    }
  else
    return (0);
  return (color);
}

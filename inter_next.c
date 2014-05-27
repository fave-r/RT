/*
** inter2.c for rtv1 in /home/thibaud/rendu/MUL_2013_rtv1
**
** Made by thibaud
** Login   <thibaud@epitech.net>
**
** Started on  Sat Mar 15 20:00:56 2014 thibaud
** Last update Tue May 27 23:35:56 2014 bourrel
*/

#include "rtv1.h"

float           *calcul_delta(t_vec3 *pos, t_vec3 *dir, int R, float k[2])
{
  float         c[3];
  float         delta;

  c[0] = (dir->x * dir->x) + (dir->y * dir->y);
  c[1] = 2 * ((pos->x * dir->x) + (pos->y * dir->y));
  c[2] = (pos->x * pos->x) + (pos->y * pos->y) - (R * R);
  delta = (c[1] * c[1]) - (4 * c[0] * c[2]);
  if (delta >= 0)
    {
      k[0] = (((c[1] * (-1)) - sqrt(delta)) / (2 * c[0]));
      k[1] = ((((-1) * c[1]) + sqrt(delta)) / (2 * c[0]));
    }
  return (k);
}

float           inter_cylindre(t_vec3 *pos, t_vec3 *dir, int R)
{
  float         k[2];
  t_vec3        *inter;

  (void)inter;
  k[0] = 0;
  k[1] = 0;
  calcul_delta(pos, dir, R, k);
  if (k[0] > 0 || k[1] > 0)
    {
      if (k[1] < k[0] && k[1] > ZERO)
        k[0] = k[1];
    }
  else
    return (-1);
  return (k[0]);
}

float           *inter_disque(t_vec3 *pos, t_vec3 *dir, int R, float k[2])
{
  float         c[3];
  float         delta;

  if (dir->z != 0)
    {
      c[0] = (dir->x * dir->x) + (dir->y * dir->y);
      c[1] = 2 * ((pos->x * dir->x) + (pos->y * dir->y));
      c[2] = (pos->x * pos->x) + (pos->y * pos->y) - (R * R);
      delta = (c[1] * c[1]) - (4 * c[0] * c[2]);
      if (delta >= 0)
        {
          k[0] = (((c[1] * (-1)) - sqrt(delta)) / (2 * c[0]));
          k[1] = ((((-1) * c[1]) + sqrt(delta)) / (2 * c[0]));
        }
    }
  return (k);
}

float           inter_carre(t_vec3 *pos, t_vec3 *dir, int R)
{
  float         k;
  t_vec3        *inter;
  t_eye         *tmp_eye;

  (void)R;
  k = ZERO;
  if (dir->z != ZERO)
    k = (-pos->z / dir->z);
  if (k)
    {
      tmp_eye = xmalloc(sizeof(t_eye));
      tmp_eye->dir = dir;
      tmp_eye->pos = pos;
      inter = xmalloc(sizeof(*inter));
      inter = inter_obj(inter, tmp_eye, k);
      if ((inter->x > R || inter->x < -R) || (inter->y > R || inter->y < -R))
        return (ZERO);
    }
  return (k);
}

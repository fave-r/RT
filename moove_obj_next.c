/*
** moove_obj2.c for rtv1 in /home/thibaud/rendu/MUL_2013_rtv1
**
** Made by thibaud
** Login   <thibaud@epitech.net>
**
** Started on  Sat Mar 15 19:38:01 2014 thibaud
** Last update Wed May 28 15:31:36 2014 lhomme
*/

#include "rt.h"

int     moove_eye_back(t_eye *eye)
{
  rotate_all_inv(eye->dir, eye->rotation);
  //rotate_all_inv(eye->pos, eye->rotation);
  return (0);
}

int     moove_eye(t_eye *eye)
{
  //rotate_all(eye->pos, eye->rotation);
  rotate_all(eye->dir, eye->rotation);
  return (0);
}

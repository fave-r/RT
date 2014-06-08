/*
** moove_obj2.c for rtv1 in /home/thibaud/rendu/MUL_2013_rtv1
**
** Made by thibaud
** Login   <thibaud@epitech.net>
**
** Started on  Sat Mar 15 19:38:01 2014 thibaud
** Last update Sun Jun  8 20:50:08 2014 romaric
*/

#include "rt.h"

int	moove_eye_back(t_eye *eye)
{
  rotate_all_inv(eye->dir, eye->rotation);
  return (0);
}

int	moove_eye(t_eye *eye)
{
  rotate_all(eye->dir, eye->rotation);
  return (0);
}

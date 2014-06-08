/*
** bright.c for bright in /home/odet/work/RT
**
** Made by odet
** Login   <odet@epitech.net>
**
** Started on  Tue Jun  3 17:50:20 2014 odet
** Last update Sun Jun  8 20:40:37 2014 romaric
*/

#include "rt.h"

int	bright(float coeff, int color, int old_color)
{
  int	new_color;

  new_color = (((color + coeff) * old_color));
  return (new_color);
}

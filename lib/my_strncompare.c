/*
** my_strncompare.c for RT in /home/leo/rendu/RT/lib
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Fri May  9 14:18:35 2014 bourrel
** Last update Wed May 28 15:33:37 2014 lhomme
*/

#include "rt.h"

int     my_strncompare(char *s1, char *s2, int nbr)
{
  int   i;

  i = 0;
  if ((!s1 || !s2) || nbr == 0)
    return (0);
  while ((s1[i] != '\0' || s2[i] != '\0') && i < nbr)
    {
      if (s1[i] != s2[i])
        return (0);
      i++;
    }
  return (1);
}

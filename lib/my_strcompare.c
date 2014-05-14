/*
** my_strcompare.c for RT in /home/leo/rendu/RT/lib
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Fri May  9 14:17:06 2014 bourrel
** Last update Fri May  9 14:17:22 2014 bourrel
*/

#include "../rtv1.h"

int     my_strcompare(char *s1, char *s2)
{
  int   i;

  i = 0;
  if (!s1 || !s2)
    return (0);
  while (s1[i] != '\0' || s2[i] != '\0')
    {
      if (s1[i] != s2[i])
        return (0);
      i++;
    }
  return (1);
}

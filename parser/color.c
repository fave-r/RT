/*
** color.c for RT in /home/leo/rendu/RT
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Wed May 28 02:23:50 2014 bourrel
** Last update Wed May 28 15:34:53 2014 lhomme
*/

#include "rt.h"

int	*color_to_tab(char *nbr, int tmp[])
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (nbr[i])
    {
      if (nbr[i] >= 'A' && nbr[i] <= 'F')
        tmp[j] = (nbr[i] - 55) * 16;
      else
        tmp[j] = (nbr[i] - '0') * 16;
      if (nbr[i + 1] >= 'A' && nbr[i + 1] <= 'F')
        tmp[j] += (nbr[i + 1] - 55);
      else
        tmp[j] += (nbr[i + 1] - '0');
      i += 2;
      j++;
    }
  return (tmp);
}

char	*copy_color(char *nbr, char *str)
{
  int	i;
  int	j;

  i = 2;
  j = 0;
  while (str[i] != '\0')
    {
      nbr[j] = str[i];
      j++;
      i++;
    }
  nbr[j] = '\0';
  return (nbr);
}

int	find_color(char *str)
{
  int   result;
  char  *nbr;
  int   tmp[3];

  nbr = xmalloc(sizeof(char) * strlen(str));
  result = 0;
  nbr = copy_color(nbr, str);
  color_to_tab(nbr, tmp);
  result = (tmp[0] * 65536) + (tmp[1] * 256) + tmp[2];
  free(nbr);
  return (result);
}

int	is_color(char *str)
{
  if (my_strcompare("BLEU", str))
    return (BLEU);
  else if (my_strcompare("CYAN", str))
    return (CYAN);
  else if (my_strcompare("JAUNE", str))
    return (JAUNE);
  else if (my_strcompare("MAGENTA", str))
    return (MAGENTA);
  else if (my_strcompare("ROUGE", str))
    return (ROUGE);
  else if (my_strcompare("VERT", str))
    return (VERT);
  else if (my_strcompare("NOIR", str))
    return (NOIR);
  else if (my_strcompare("BLANC", str))
    return (BLANC);
  else if (my_strcompare("ORANGE", str))
    return (ORANGE);
  else if (my_strcompare("ROSE", str))
    return (ROSE);
  else if (my_strncompare("0x", str, 2))
    return (find_color(str));
  else
    return (-1);
}

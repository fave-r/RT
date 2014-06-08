/*
** my_str_to_wordtab.c for rt in /home/blackbird/work/RT/lib
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Sun Jun  8 21:16:59 2014 romaric
** Last update Sun Jun  8 21:17:17 2014 romaric
*/

#include "rt.h"

int	strlen_word(const char *str, char *sep)
{
  int	i;

  i = 0;
  if (str[0] == 0)
    return (0);
  else if (my_strchr(str[0], sep) != -1)
    return (0);
  while (my_strchr(str[i], sep) == -1 && str[i] != 0)
    i++;
  return (i);
}

int	lentab(char *str, char *sep)
{
  int	i;
  int	nbr_word;
  int	bool;

  i = 0;
  nbr_word = 0;
  bool = 0;
  while (my_strchr(str[i], sep) != -1)
    i++;
  while (str[i] != 0)
    {
      if (my_strchr(str[i], sep) != -1)
	  nbr_word = (++bool == 1) ? nbr_word + 1 : nbr_word;
      else
	bool = 0;
      i++;
    }
  if (bool == 0)
    nbr_word++;
  return (nbr_word);
}

char	**my_str_to_wordtab(char **tb, char *str, char *sep)
{
  int	tmp;
  int	j;
  char	*first;

  j = 0;
  tmp = lentab(str, sep);
  tb = xmalloc((tmp + 1) * sizeof(char *));
  first = str;
  while (j != tmp && *str != 0)
    {
      if (strlen_word(str, sep) > 0)
	{
	  tb[j] = xmalloc((strlen_word(str, sep) + 1) * sizeof(char));
	  tb[j] = strncpy(tb[j], str, strlen_word(str, sep));
	  tb[j][strlen_word(str, sep)] = 0;
	  str = str + strlen_word(str, sep) + 1;
	  j++;
	}
      else
	str = str + 1;
    }
  tb[j] = NULL;
  str = first;
  return (tb);
}

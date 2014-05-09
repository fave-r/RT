/*
** parser.c for RT in /home/leo/rendu/RT/parser
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Mon May  5 16:49:21 2014 bourrel
** Last update Fri May  9 14:19:38 2014 bourrel
*/

#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "../rtv1.h"

char	**epur_tab(char **tmp)
{
  int	i;

  i = 0;
  while (tmp[i])
    {
      tmp[i] = my_epur_str(tmp[i]);
      i++;
    }
  return (tmp);
}

int	is_in_tab(char *str, t_flag tab[])
{
  int	i;

  i = 0;
  while (i < 6)
    {
      if (my_strcompare(tab[i].type, str))
	return (1);
      i++;
    }
  return (0);
}

void	fill_list(char **tmp, t_flag tab[], t_obj *obj, t_spot *spot)
{
  int		i;
  static int	line = 0;

  i = 0;
  line++;
  if (is_in_tab(tmp[0], tab) == 1)
    new_obj(tmp, obj);
  else if (my_strcompare("SPOT", tmp[0]))
    new_spot(tmp, spot);
  else
    printf("File incorrect line : %d\n", line);
}

int		parser(char *name, t_flag tab[], t_obj *obj, t_spot *spot)
{
  int		fd;
  char		*str;
  char		**tmp;

  str = NULL;
  if ((fd = open(name, O_RDONLY)) == -1)
    {
      printf("Cannot read file %s\n", name);
      return (-1);
    }
  while ((str = get_next_line(fd)) != NULL)
    {
      tmp = my_str_to_wordtab(str, ",:");
      tmp = epur_tab(tmp);
      fill_list(tmp, tab, obj, spot);
    }
  close (fd);
  return (1);
}

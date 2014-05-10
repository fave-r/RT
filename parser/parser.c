/*
** parser.c for RT in /home/leo/rendu/RT/parser
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Mon May  5 16:49:21 2014 bourrel
** Last update Sat May 10 00:31:34 2014 bourrel
*/

#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "../rtv1.h"

void	free_tab(char **tmp)
{
  int	i;

  i = 0;
  while (tmp[i])
    {
      free(tmp[i]);
      i++;
    }
  free(tmp);
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

void		fill_list(char **tmp, t_flag tab[], t_obj *obj, t_spot *spot)
{
  static int	i = 0;

  i++;
  if (is_in_tab(tmp[0], tab) == 1)
    {
      check_obj(tmp, i);
      new_obj(tmp, obj);
    }
  else if (my_strcompare("SPOT", tmp[0]))
    {
      check_spot(tmp, i);
      new_spot(tmp, spot);
    }
  else
    {
      printf("Unknown object line %d\n", i);
      exit (-1);
    }
}

int		parser(char *name, t_flag tab[], t_obj *obj, t_spot *spot)
{
  int		fd;
  char		*str;
  char		**tmp;

  if ((fd = open(name, O_RDONLY)) == -1)
    {
      printf("Cannot read file %s\n", name);
      return (-1);
    }
  while ((str = get_next_line(fd)))
    {
      if (str[1])
	{
	  tmp = my_str_to_wordtab(str, ", :\t");
	  fill_list(tmp, tab, obj, spot);
	}
    }
  close (fd);
  return (1);
}

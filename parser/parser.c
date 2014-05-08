/*
** parser.c for RT in /home/leo/rendu/RT/parser
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Mon May  5 16:49:21 2014 bourrel
** Last update Thu May  8 16:04:22 2014 bourrel
*/

#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "../rtv1.h"

int	my_strcompare(char *s1, char *s2)
{
  int	i;

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

void	fill_list(char *str, t_flag tab[], t_obj *obj, t_spot *spot)
{
  int		i;
  static int	line = 0;
  char		*type;

  i = 0;
  line++;
  type = malloc(sizeof(*type) * strlen(str));
  while ((str[i] >= 'a' && str[i] <= 'z')
	 || (str[i] >= 'A' && str[i] <= 'Z'))
    {
      type[i] = str[i];
      i++;
    }
  type[i] = '\0';
  printf("%s\n", type);
  if (is_in_tab(type, tab) == 1)
    new_obj(str, obj, i, type);
  else if (my_strcompare("SPOT", type))
    new_spot(str, spot, i);
  else
    printf("File incorrect line : %d", line);
  printf("\n");
}

int		parser(char *file_name, t_flag tab[], t_obj *obj, t_spot *spot)
{
  int		fd;
  char		*str;

  str = NULL;
  if ((fd = open(file_name, O_RDONLY)) == -1)
    {
      printf("Cannot read file %s\n", file_name);
      return (-1);
    }
  while ((str = get_next_line(fd)) != NULL)
    fill_list(str, tab, obj, spot);
  close (fd);
  return (1);
}

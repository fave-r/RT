/*
** get_next_line.c for get_next_line in /home/lhomme_a/rendu/CPE_2014_corewar/asm
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Wed Apr  2 16:44:34 2014 lhomme
** Last update Wed May 28 15:32:46 2014 lhomme
*/

#include "rt.h"

void	*xmalloc(int size)
{
  void	*temp;

  if ((temp = malloc(size)) == NULL)
    exit(-1);
  return (temp);
}

int    stock_buffer(t_var *var, char *tmp, int *save)
{
  while (var->i < BUFF_SIZE)
    {
      if (tmp[*save] == '\0')
	{
	  var->buffer[var->i] = '\0';
	  *save = 0;
	  if (var->nb_read < BUFF_SIZE)
	    return (1);
	  return (0);
	}
      if (tmp[*save] == '\n')
	{
          var->buffer[var->i] = '\0';
	  if (*save + 1 >= var->nb_read)
	    *save = 0;
	  else
	    (*save)++;
          return (1);
	}
      var->buffer[var->i++] = tmp[(*save)++];
    }
  var->buffer[var->i] = '\0';
  return (1);
}

char        *get_next_line(const int fd)
{
  static int	save = 0;
  static char	buff[BUFF_SIZE + 1];
  static int	nb_read;
  t_var		var;

  var.i = 0;
  var.buffer = xmalloc(BUFF_SIZE + 1);
  while (var.i < BUFF_SIZE)
    {
      if (save == 0)
	if ((nb_read = read(fd, buff, BUFF_SIZE)) <= 0)
	  return (0);
      var.nb_read = nb_read;
      if (stock_buffer(&var, buff, &save))
	return (var.buffer);
    }
  return (var.buffer);
}

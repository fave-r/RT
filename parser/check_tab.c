/*
** check_tab.c for RT in /home/leo/rendu/RT/parser
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Fri May  9 17:30:45 2014 bourrel
** Last update Sat May 10 00:28:47 2014 bourrel
*/

#include <stdio.h>
#include <stdlib.h>
#include "../rtv1.h"

void    check_color(char *str, int line)
{
  int   i;

  i = -1;
  while (str[++i])
    if ((str[i] < 'a'|| str[i] > 'z')
	&& (str[i] < 'A'|| str[i] > 'Z'))
      {
        printf("Invalid color at line %d\n", line);
        exit (-1);
      }
}

void	check_nbr(char *str, int line, int arg)
{
  int	i;

  i = -1;
  while (str[++i])
    if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
      {
	printf("Invalid argument at line %d and arg %d\n", line, arg);
	exit (-1);
      }
}

void	check_obj(char **tab, int line)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  if (i != 8)
    {
      printf("Invalid number of argument line %d\n", line);
      exit (-1);
    }
  i = 0;
  while (++i < 7)
    check_nbr(tab[i], line, i);
  check_color(tab[7], line);
}

void    check_spot(char **tab, int line)
{
  int   i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  if (i != 5)
    {
      printf("Invalid number of argument line %d\n", line);
      exit (-1);
    }
  i = 0;
  while (++i < 4)
    check_nbr(tab[i], line, i);
  check_color(tab[4], line);
}

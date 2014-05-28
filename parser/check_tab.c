/*
** check_tab.c for RT in /home/leo/rendu/RT/parser
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Fri May  9 17:30:45 2014 bourrel
** Last update Wed May 28 13:43:19 2014 lhomme
*/

#include <stdio.h>
#include <stdlib.h>
#include "../rtv1.h"

void	print_error(int line)
{
  printf("Invalid color at line %d\n", line);
  exit(-1);
}

void    check_color(char *str, int line)
{
  int   i;

  i = 0;
  if (my_strncompare("0x", str, 2))
    {
      if (strlen(str) != 8)
	print_error(line);
      while (str[i])
	{
	  if (str[i] != 'x' && (str[i] < '0'|| str[i] > '9')
	      &&  (str[i] < 'a'|| str[i] > 'z') && (str[i] < 'A'|| str[i] > 'Z'))
	    print_error(line);
	  i++;
	}
    }
  else
    {
      while (str[i])
	{
	  if ((str[i] < 'a'|| str[i] > 'z')
	      && (str[i] < 'A'|| str[i] > 'Z'))
	    print_error(line);
	  i++;
	}
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
	exit(-1);
      }
}

void	check_obj(char **tab, int line)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  if (i != 9)
    {
      printf("Invalid number of argument line %d\n", line);
      exit(-1);
    }
  i = 0;
  while (++i < 8)
    check_nbr(tab[i], line, i);
  check_color(tab[8], line);
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
      exit(-1);
    }
  i = 0;
  while (++i < 4)
    check_nbr(tab[i], line, i);
  check_color(tab[4], line);
}

/*
** my_strchr.c for rt in /home/blackbird/work/RT/lib
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Sun Jun  8 21:01:07 2014 romaric
** Last update Sun Jun  8 21:01:13 2014 romaric
*/

int	my_strchr(char src, char *dest)
{
  int	i;

  i = 0;
  while (dest[i] != 0 && dest[i] != src)
    i++;
  if (dest[i] == 0)
    return (-1);
  return (i);
}

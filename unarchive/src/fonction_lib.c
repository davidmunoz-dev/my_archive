/*
** fonction_lib.c for fctlib in /home/counil_m/rendu/Rush1/unarchive
** 
** Made by maxime counil
** Login   <counil_m@epitech.net>
** 
** Started on  Sun Jan 10 19:18:27 2016 maxime counil
** Last update Sun Jan 10 19:24:06 2016 maxime counil
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	my_strlen (char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int	gestion_erreur(char *msg, int status)
{
  write(2, msg, my_strlen(msg));
  return (status);
}

char	*my_realloc(char *old, int size)
{
  int	i;
  char	*new;

  i = 0;
  new = NULL;
  new = malloc((my_strlen(old) + size) * sizeof(char *));
  while (old[i])
    {
      new[i] = old[i];
      i++;
    }
  free(old);
  return (new);
}

int	signe(char *str)
{
  int	a;
  int	signe;

  a = 0;
  signe = 0;
  while (str[a] == 45 || str[a] == 43)
    {
      if (str[a] == 45)
        signe = signe + 1;
      str[a] = 48;
      a = a + 1;
    }
  return (signe);
}

int	my_getnbr(char *str)
{
  int	signet;
  int	compt;
  int	a;
  int	b;
  int	i;
  int	m;

  b = 0;
  m = 1;
  i = 0;
  compt = signe(str);
  signet = compt;
  while (str[compt] != '\0' && str[compt] > 47 && str[compt] < 58)
    compt = compt + 1;
  compt = compt - 1;
  while (i <= compt)
    {
      a = str[compt - i];
      b = b + ((a - 48) * m);
      m = m * 10;
      i = i + 1;
    }
  if (signet % 2 == 0)
    return (b);
  return (-b);
}

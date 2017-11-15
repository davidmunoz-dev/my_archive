/*
** fonction_lib.c for fctlib in /home/counil_m/rendu/Rush1/archive
** 
** Made by maxime counil
** Login   <counil_m@epitech.net>
** 
** Started on  Sun Jan 10 19:18:08 2016 maxime counil
** Last update Sun Jan 10 19:18:09 2016 maxime counil
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/my.h"

int	gestion_erreur(char *msg, int status)
{
  write(2, msg, my_strlen(msg));
  return (status);
}

int	my_strlen (char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
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

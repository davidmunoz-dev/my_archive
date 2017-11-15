/*
** main.c for rush in /home/counil_m/rendu/Rush1
** 
** Made by maxime counil
** Login   <counil_m@epitech.net>
** 
** Started on  Sat Jan  9 01:05:02 2016 maxime counil
** Last update Sun Jan 10 19:23:34 2016 maxime counil
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "../include/my.h"

int	copy_file(int ac, char **av)
{
  struct stat	sb;
  t_list	va;

  va.i = 2;
  va.fichier = fopen(av[1], "wr");
  fprintf(va.fichier, "%d\n", ac - 2);
  while (va.i < ac)
    {
      stat(av[va.i], &sb);
      va.chaine = malloc(sb.st_size);
      va.buff = sb.st_size;
      fprintf(va.fichier, "%s\n%d\n", av[va.i], va.buff);
      va.file = fopen(av[va.i], "r");
      if (va.file == NULL)
	return (gestion_erreur("ERROR : Le fichier n'existe pas\n", 0));
      if (va.fichier != NULL)
	while (fgets(va.chaine, va.buff,  va.file) != NULL)
	  fprintf(va.fichier, "%s", va.chaine);
      va.chaine = my_realloc(va.chaine, 1);
      va.i++;
    }
  fclose(va.fichier);
  fclose(va.file);
  free(va.chaine);
  return (0);
}

int	main(int ac, char **av)
{
  int	file;
  char	*str;
  if (ac < 3)
    {
      printf("ERROR : To few arguments\n");
      return (0);
    }
  else
    {
      copy_file(ac, av);
      return (0);
    }
  printf("\n");
}


/*
** my_unarchives.c for unarchive in /home/counil_m/rendu/Rush1/src
** 
** Made by maxime counil
** Login   <counil_m@epitech.net>
** 
** Started on  Sat Jan  9 12:48:15 2016 maxime counil
** Last update Sun Jan 10 19:18:38 2016 maxime counil
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "../include/variables.h"

int	count_files(t_list var, struct stat sb)
{
  int	nb_files;
  char	*count;

  nb_files = 0;
  count = malloc(sb.st_size);
  count = fgets(var.chaine, var.buff, var.archive);
  nb_files = my_getnbr(count);
  return (nb_files);
}

int	save_argv(t_list var, char **av, struct stat sb)
{
  int	nb;
  char	*str;

  str = malloc(sb.st_size);
  var.fichier_generer = fopen(var.chaine, "w");
  str = fgets(var.chaine, var.buff, var.archive);
  nb = my_getnbr(str);
  fread(str, 1, nb, var.archive);
  fwrite(str, 1, nb, var.fichier_generer);
}

int	unarchives(int ac, char **av)
{
  t_list	var;
  struct stat	sb;
  int		i;
  int		files;

  i = 0;
  stat(av[1], &sb);
  var.buff = sb.st_size;
  var.chaine = malloc(sb.st_size);
  var.archive = fopen(av[1], "r");
  if (var.archive == NULL)
    return (gestion_erreur("ERROR : Le fichier n'existe pas\n", 0));
  files = count_files(var, sb);
  while (i < files)
    {
      fgets(var.chaine, var.buff, var.archive);
      var.chaine[my_strlen(var.chaine) - 1] = 0;
      fprintf(var.archive, "%s", var.chaine);
      save_argv(var, av, sb);
      var.chaine = my_realloc(var.chaine, 1);
      i++;
    }
  fclose(var.archive);
  free(var.chaine);
  return (0);
}

int	main(int ac, char **av)
{
  int	file;
  char	*str;
  if (ac != 2)
    {
      printf("ERROR : Invalid arguments\n");
      return (0);
    }
  else
    {
      unarchives(ac, av);
      return (0);
    }
  printf("\n");
}

/*
** variables.h for variables in /home/counil_m/rendu/Rush1/unarchive/src
** 
** Made by maxime counil
** Login   <counil_m@epitech.net>
** 
** Started on  Sat Jan  9 19:52:23 2016 maxime counil
** Last update Sat Jan  9 20:26:40 2016 maxime counil
*/

#ifndef VARIABLES_H_
# define VARIABLE_H_

typedef struct s_list
{
  FILE*		archive;
  FILE*		fichier_generer;
  char		*chaine;
  char		*str;
  int		buff;
  int		i;
}	t_list;


int	count_files(t_list var, struct stat sb);
int	signe(char *str);
int	my_getnbr(char *str);
int	unarchives(int ac, char **av);
int	main(int ac, char **av);
int	save_argv(t_list var, char **av, struct stat sb);
int	gestion_erreur(char *msg, int status);
int	my_strlen(char *str);
char	*my_realloc(char *old, int size);

#endif /*VARIABLE_H_*/

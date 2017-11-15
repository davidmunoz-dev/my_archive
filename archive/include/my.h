/*
** my.h for my.h in /home/counil_m/rendu/Rush1/archive/include
** 
** Made by maxime counil
** Login   <counil_m@epitech.net>
** 
** Started on  Sun Jan 10 19:17:56 2016 maxime counil
** Last update Sun Jan 10 19:22:50 2016 maxime counil
*/

#ifndef MY_H_
# define MY_H_

typedef struct s_list
{
  int   buff;
  int   i;
  FILE* fichier;
  FILE* file;
  char  *chaine;
}	t_list;

int	gestion_erreur(char *msg, int status);
int	my_strlen(char *str);
char	*my_realloc(char *old, int size);
int	copy_file(int ac, char **av);

#endif /* !MY_H_ */

##
## Makefile for make in /rendu/rendu_Systeme_Unix/PSU_2015_my_ls
##
## Made by munoz david
## Login   <munoz_d@epitech.net>
##
## Started on  Thu Nov 26 22:59:46 2015 munoz david
## Last update Tue Jan  5 10:38:57 2016 Munoz David
##

NAME	= my_unarchive

OBJ	= $(SRC:.c=.o)

SRC	= src/main.c \
	src/fonction_lib.c

CC	= gcc

CFLAGS	= -I./include/ -g

RM 	= rm -f

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

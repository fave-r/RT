##
## Makefile for Makefile in /home/thibaud/rendu/Piscine-C-lib/my
##
## Made by thibaud
## Login   <thibaud@epitech.net>
##
## Started on  Mon Oct 21 09:07:38 2013 thibaud
## Last update Wed Apr 23 16:47:23 2014 romaric
##

CC=		gcc

RM=		rm -f

CFLAGS=		-Wextra -Wall -Werror

NAME=		rt

SRCS=		main.c \
		rotation.c \
		list.c \
		inter.c \
		inter2.c \
		basic_fct.c \
		basic_fct2.c \
		norme.c \
		init.c \
		moove_obj.c \
		moove_obj2.c \
		ombre.c \
		free.c \
		light.c

MINLIB=		-lmlx -L/usr/lib64 -lxext -lX11 -L/usr/lib64/X11 -lm

OBJS=		$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) $(MINLIB)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all fclean re

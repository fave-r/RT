##
## Makefile for Makefile in /home/thibaud/rendu/Piscine-C-lib/my
##
## Made by thibaud
## Login   <thibaud@epitech.net>
##
## Started on  Mon Oct 21 09:07:38 2013 thibaud
## Last update Tue May 27 15:18:31 2014 bourrel
##

CC=		gcc

RM=		rm -f

CFLAGS=		-W -Werror -Wall -g3 -ggdb3 -I.

NAME=		rt

SRCS=		main.c \
		rotation.c \
		list.c \
		inter.c \
		inter_next.c \
		basic_fct.c \
		basic_fct_next.c \
		norme.c \
		init.c \
		moove_obj.c \
		moove_obj_next.c \
		ombre.c \
		free.c \
		light.c \
		parser/parser.c \
		parser/new_obj.c \
		parser/check_tab.c \
		lib/get_next_line.c \
		lib/my_str_to_wordtab.c \
		lib/my_epur_str.c \
		lib/my_strchr.c \
		lib/my_strcompare.c \
		lib/my_strncompare.c

MINLIB=		-lmlx -L/usr/lib64 -lXext -lX11 -L/usr/lib64/X11 -lm

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

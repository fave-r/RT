##
## Makefile for rt in /tmp/RT
##
## Made by romaric
## Login   <fave_r@epitech.net>
##
## Started on  Sun Jun  8 21:29:15 2014 romaric
## Last update Sun Jun  8 22:09:07 2014 romaric
##

CC=		gcc

RM=		rm -f

CFLAGS=		-Wextra -Wall -Werror -I. -I./minilibx/

NAME=		rt

SRCS=		main.c \
		rotation.c \
		list.c \
		inter.c \
		inter_next.c \
		basic_fct.c \
		basic_fct_next.c \
		bright.c \
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
		parser/color.c \
		lib/get_next_line.c \
		lib/my_str_to_wordtab.c \
		lib/my_epur_str.c \
		lib/my_strchr.c \
		lib/my_strcompare.c \
		lib/my_strncompare.c

MINLIB=		-L./minilibx/ -lmlx -L/usr/lib64/X11 -lXext -lX11 -lm

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

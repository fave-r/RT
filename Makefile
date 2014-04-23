##
## Makefile for Makefile in /home/thibaud/rendu/Piscine-C-lib/my
## 
## Made by thibaud
## Login   <thibaud@epitech.net>
## 
## Started on  Mon Oct 21 09:07:38 2013 thibaud
## Last update Sun Mar 16 20:49:32 2014 thibaud
##

RM	= rm -f

RMO	= rm *.o

CC	= gcc

NAME	= rtv1

SRCS	= main.c \
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

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME) :	$(OBJS)
	$(CC) -o $(NAME) $(SRCS) -W -Werror -Wall -lm -L/usr/lib64 -lmlx_$(HOSTTYPE) -L/usr/lib64/X11 -lXext -lX11
	$(RMO)

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME) *~

re: fclean all

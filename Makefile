#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/27 12:31:31 by acrosnie          #+#    #+#              #
#    Updated: 2014/02/14 11:04:55 by acrosnie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = rtv1

NAME_MINILIBX = mlx

CC = cc -g -Werror -Wall -Werror -O3

DIR_LIBS = /usr/X11/lib/

LDFLAGS = -L /usr/X11/lib -lmlx -lXext -lX11

SRC = src/main.c src/image.c src/init.c src/ft_strsplit.c src/get_next_line.c \
src/ft_strlen.c src/ft_strjoin.c src/ft_putendl.c src/ft_putchar.c \
src/ft_putstr.c src/ft_memalloc.c src/ft_bzero.c src/ft_strdup.c src/ft_atoi.c \
src/draw.c src/vecteur.c src/intersection.c src/objet.c src/rotation.c src/ft_strcmp.c \
src/display.c src/math.c src/camera.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o: %.c fdf_42.h
	$(CC) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all re fclean

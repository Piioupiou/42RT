#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acrosnie <acrosnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/27 12:31:31 by acrosnie          #+#    #+#              #
#    Updated: 2015/05/25 17:43:29 by acrosnie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = rtv1

NAME_MINILIBX = mlx

CC = cc -g -Werror -Wall -Werror -O3 -oFast

DIR_LIBS = /lib

LDFLAGS =  lib/libmlx.a  -lmlx -framework OpenGL -framework AppKit

SRC = src/main.c src/image.c src/init.c src/ft_strsplit.c src/get_next_line.c \
src/ft_strlen.c src/ft_strjoin.c src/ft_putendl.c src/ft_putchar.c \
src/ft_putstr.c src/ft_memalloc.c src/ft_bzero.c src/ft_strdup.c src/ft_atoi.c \
src/draw.c src/vecteur.c src/intersection.c src/objet.c src/ft_strcmp.c \
src/display.c src/calc_math.c src/camera.c src/matrice.c src/ft_strcat.c src/ft_strnew.c \
src/create_object.c src/vecteur_again.c src/key.c src/effect.c src/light_shadow.c src/normal.c \
src/intersection_again.c src/ft_strcpy.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib ; $(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o: %.c fdf_42.h
	$(CC) -o $@ -c $<

clean:
	make clean -C lib
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
	make re -C lib
.PHONY: clean all re fclean

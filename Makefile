# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkotliar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/22 10:15:44 by kkotliar          #+#    #+#              #
#    Updated: 2017/05/31 16:52:35 by kkotliar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

CFLAG = -Wall -Werror -Wextra
SDLFLAG = -framework SDL2_ttf -framework SDL2 -F.

SRC =  main.c \
	   ft_move_over_map.c \
	   ft_read.c \
	   ft_sdl.c

OBJ = main.o \
	  ft_move_over_map.o \
	  ft_read.o \
	  ft_sdl.o

HEADER = filler.h

LIB = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	gcc  $(OBJ) $(LIB) -o $(NAME) $(CFLAG) $(SDLFLAG)


%.o: %.c
	gcc -c -o $@ $< $(CFLAG) -F.
clean:
	make clean -C ./libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all
	make re -C ./libft

sdl2:
	@echo "[Installing SDL2 SDL2_ttf...]"
	@cp -r SDL2_ttf.framework ~/Library/Frameworks/
	@cp -r SDL2.framework ~/Library/Frameworks/
	@echo "[DONE...]"

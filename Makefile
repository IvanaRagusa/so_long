# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iragusa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 20:18:08 by iragusa           #+#    #+#              #
#    Updated: 2023/02/04 20:18:13 by iragusa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# \ = is used to Splitting Long Lines 3.1.1

# ;\ = indicates a multiline command and keeps the instance of the terminal for
# the next command

# % = the same as * 'wildcard'
# $@ = means what is before the : in the target
# $^ = means what is after the : in the target
# $< = the first prerequisite (usually a source file)
# -I.  = adds include directory of header files.
# -f = force the removal even if the files have been already deleted.

# -c = Compile or assemble the source files, but do not link.
# cp = copy.
# The linking stage simply is not done. The ultimate output is
# in the form of an object file for each source file.
# By default, the object file name for a source file is made by replacing
# the suffix .c, .i, .s, etc., with .o. Unrecognized input files,
# not requiring compilation or assembly, are ignored.
# -s = silent
# @echo = stampa quello che viene dopo

NAME = so_long

CC = gcc 

CFLAGS = -Wall -Wextra -Werror -Iheaders/

LIBFT = libft/libft.a

LIB = minilibx/libmlx_Linux.a -lX11 -lXext -lm

MLX = minilibx/

FLAG = -lXext -lX11 -lm -lz

SRC = src/main.c src/map.c src/ft_close.c src/image.c src/command.c src/floodfill.c

SRC_BONUS = src_bonus/main.c src_bonus/map.c src_bonus/ft_close.c src_bonus/image.c \
	    src_bonus/command.c src_bonus/floodfill.c src_bonus/ft_enemy.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "⌛ compiling...⌛"
	$(MAKE) -s -C libft/
	$(MAKE) -s -C $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(LIBFT) -o $(NAME)
	@echo "🎉 so_long compiled! 🎉"

clean:	
	@echo "🧽 cleaning... 🧽"
	@rm -f $(OBJ) $(OBJ_BONUS)
	@make clean -s -C libft/


fclean: clean
	@echo "🚮♻️ spring cleaning, rm $(NAME)... ♻️ 🚮" 
	make clean -C $(MLX)
	rm -rf $(NAME)

re: fclean all

bonus:	$(OBJ_BONUS)
	@echo "⌛ compiling bonus...⌛"
	$(MAKE) -s -C libft/
	$(MAKE) -s -C $(MLX)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIB) $(LIBFT) -o $(NAME)
	@echo "🎉 so_long compiled! 🎉"
	
.SILENT:

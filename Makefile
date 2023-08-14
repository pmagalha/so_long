# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmagalha <pmagalha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 13:47:37 by pmagalha          #+#    #+#              #
#    Updated: 2023/08/01 10:59:02 by pmagalha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L ./libs/minilibx-linux -lm -lmlx -Ilmlx -lXext -lX11
RM = rm -f

NAME = so_long

NAME_BNS = so_long_bonus

SRC =	sources/main.c sources/vibe_check.c sources/init.c sources/render.c \
sources/free_everything.c sources/movements.c sources/keypresses.c \
sources/path_check.c

SRC_BNS =	sources_bonus/main.c sources_bonus/vibe_check.c sources_bonus/init.c sources_bonus/render.c \
sources_bonus/free_everything.c sources_bonus/movements.c sources_bonus/keypresses.c \
sources_bonus/path_check.c sources_bonus/enemies.c sources_bonus/exit_animations.c sources_bonus/movements_aux.c\
sources_bonus/enemy_movement.c sources_bonus/enemy_animations.c sources_bonus/extra_animations.c

OBJ = $(SRC:.c=.o)

OBJ_BNS = $(SRC_BNS:.c=.o)

LIBFT = libs/libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libs/libft
	$(MAKE) -C ./libs/minilibx-linux
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)

bonus: $(NAME_BNS)

$(NAME_BNS): $(OBJ_BNS)
	$(MAKE) -C ./libs/libft
	$(MAKE) -C ./libs/minilibx-linux
	$(CC) $(CFLAGS) $(OBJ_BNS) $(LIBFT) $(MLXFLAGS) -o $(NAME_BNS)

clean: 
	$(MAKE) clean -C ./libs/libft
	$(MAKE) clean -C ./libs/minilibx-linux
	@$(RM) $(OBJ) $(OBJ_BNS)

fclean : clean
	@$(RM) $(LIBFT) $(NAME)

re: fclean all	

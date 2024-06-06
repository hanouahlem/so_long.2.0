# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahbey <ahbey@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 19:20:15 by ahbey             #+#    #+#              #
#    Updated: 2024/06/03 21:24:33 by ahbey            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS =	gnl/get_next_line_utils.c\
		gnl/get_next_line.c\
		srcs/bord_parsing.c\
		srcs/so_long.c\
		srcs/move.c\
		srcs/stock_map.c\
		srcs/make_image.c\
		srcs/check_map.c\
		srcs/free_map.c\
		srcs/libft.c\
		srcs/parsing.c\
		srcs/game.c\
		srcs/flood_fill.c\

SRCS_BONUS = gnl/get_next_line_utils.c\
			gnl/get_next_line.c\
			bonussrcs/stock_map.c\
			bonussrcs/check_map.c\
			bonussrcs/free_map.c\
			bonussrcs/libft.c\
			bonussrcs/so_long_bonus.c\
			bonussrcs/move_bonus.c\
			bonussrcs/make_image_bonus.c\
			bonussrcs/parsing_bonus.c\
			bonussrcs/game_bonus.c\
			bonussrcs/bord_parsing.c\
			bonussrcs/flood_fill_bonus.c\

CC	=	cc

CFLAGS	=	-Wall -Wextra -Werror -g3

OBJS	=	$(SRCS:.c=.o)

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

NAME	=	so_long
BONUS	=	so_long_bonus

INCL	= -I. -I/usr/include -Imlx -Ilibft
MFLAGS	= -lmlx_Linux -lXext -lX11 -lm -lz -Lmlx -L/usr/lib
MLX		= mlx/libmlx_Linux.a

PRINTF	=	printf/libftprintf.a

all: ${NAME}

$(NAME): $(OBJS) $(PRINTF) $(MLX)
		$(CC) $(CFLAGS) $(OBJS) $(MLX) $(MFLAGS) $(PRINTF) -o $(NAME) 

bonus: ${BONUS}

$(BONUS): $(OBJS_BONUS) $(PRINTF) $(MLX)
		$(CC) $(CFLAGS) $(OBJS_BONUS) $(MLX) $(MFLAGS) $(PRINTF) -o $(BONUS) 

$(PRINTF):
	make -C printf

$(MLX):
	make -C mlx
	
%.o: %.c so_long.h
	$(CC) $(CFLAGS) -I. -c $< -o $@ $(INCL)

clean:
		rm -f ${OBJS}
		rm -f ${OBJS_BONUS}
		make -C printf clean
		make -C mlx clean

fclean: clean
		rm -f $(NAME)
		rm -f ${BONUS}
		make -C printf fclean

re:		fclean all

.PHONY: all clean fclean re bonus/
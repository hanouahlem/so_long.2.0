# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahbey <ahbey@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 19:20:15 by ahbey             #+#    #+#              #
#    Updated: 2024/05/29 12:43:45 by ahbey            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS =	gnl/get_next_line_utils.c\
		gnl/get_next_line.c\
		bord_parsing.c\
		so_long.c\
		move.c\
		stock_map.c\
		make_image.c\
		check_map.c\
		free_map.c\
		libft.c\
		parsing.c\
		game.c\
		flood_fill.c\

CC	=	cc

CFLAGS	=	-Wall -Wextra -Werror -g

OBJS	=	$(SRCS:.c=.o)

NAME	=	so_long

INCL	= -I. -I/usr/include -Imlx -Ilibft
MFLAGS	= -lmlx_Linux -lXext -lX11 -lm -lz -Lmlx -L/usr/lib
MLX		= mlx/libmlx_Linux.a

PRINTF	=	printf/libftprintf.a

all: ${NAME}

$(NAME): $(OBJS) $(PRINTF) $(MLX)
		$(CC) $(CFLAGS) $(OBJS) $(MLX) $(MFLAGS) $(PRINTF) -o $(NAME) 

$(PRINTF):
	make -C printf

$(MLX):
	make -C mlx
	
%.o: %.c so_long.h
	$(CC) $(CFLAGS) -I. -c $< -o $@ $(INCL)

clean:
		rm -f ${OBJS}
		make -C printf clean
		make -C mlx clean
		
fclean: clean
		rm -f $(NAME)
		make -C printf fclean
		

re:		fclean all

.PHONY: all clean fclean re/
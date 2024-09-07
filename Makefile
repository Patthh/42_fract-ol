# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pracksaw <pracksaw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/10 12:07:55 by pracksaw          #+#    #+#              #
#    Updated: 2024/09/07 17:07:30 by pracksaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -Wall -Wextra -Werror
NAME = fractol
BNAME = fractol_bonus
MLXFLAGS = -Lminilibx-linux -lm -lmlx -lX11 -lXext
SRCS = 	handler.c main.c conversion.c rendering.c init.c utils.c
BSRCS = handler.c main.c conversion.c rendering.c init.c utils.c


OBJS = $(addprefix src/,$(SRCS:.c=.o))
BOBJS = $(addprefix src_bonus/,$(BSRCS:.c=.o))


default: $(NAME)

all : $(NAME) $(BNAME)

$(NAME) : $(OBJS)
				make -C minilibx-linux -s 
				$(CC) $(OBJS) $(MLXFLAGS) -o $(NAME) 

bonus: $(BNAME)

$(BNAME): $(BOBJS)
				@make -C minilibx-linux -s
				$(CC) $(BOBJS) $(MLXFLAGS) -o  $(BNAME)

clean : 
				rm -rf $(OBJS)
				rm -rf $(BOBJS)
fclean : clean
				rm -rf $(NAME)
				rm -rf $(BNAME)
				
re : fclean all


.PHONY: all clean fclean re bonus default

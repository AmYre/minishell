# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 17:31:31 by amben-ha          #+#    #+#              #
#    Updated: 2023/12/05 18:22:47 by amben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	main.c\

OBJS		= ${SRCS:.c=.o}
NAME		= minish
CC			= cc -Wall -Wextra -Werror

INCLUDES = -I. -Ilibft

LIBFT = libft/libft.a

all: ${NAME}

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT) -lreadline -lncurses

$(LIBFT):
	make -C libft

%.o: %.c minish.h
	$(CC) -o $@ -c $< $(INCLUDES)

clean:
	rm -f ${OBJS}
	make -C libft clean

fclean:		clean
	rm -f ${NAME}
	make -C libft fclean

re:			fclean all

.PHONY:		all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 17:31:31 by amben-ha          #+#    #+#              #
#    Updated: 2023/12/05 00:24:35 by amben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	unset.c\
				export.c\

OBJS		= ${SRCS:.c=.o}
NAME		= a.out
CC			= cc -g -Wall -Wextra -Werror

INCLUDES = -I. -I../libft

LIBFT = ../libft/libft.a

all: ${NAME}

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	make -C ../libft

%.o: %.c builtins.h
	$(CC) -o $@ -c $< $(INCLUDES)

clean:
	rm -f ${OBJS}
	make -C ../libft clean

fclean:		clean
	rm -f ${NAME}
	make -C ../libft fclean

re:			fclean all

.PHONY:		all clean fclean re bonus
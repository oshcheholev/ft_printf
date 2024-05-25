# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oshcheho <oshcheho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 14:46:25 by oshcheho          #+#    #+#              #
#    Updated: 2024/05/23 14:59:14 by oshcheho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

AR		= ar rsc

SRC		= ./ft_printf.c ./ft_putnbr_base_fd.c ./ft_putnbr_fd.c ./ft_putstr_fd.c ./ft_putchar_fd.c ./ft_putnbr_fd_unsigned.c

HEAD	= ./

OBJS	= ${SRC:.c=.o}

RM		= rm -f

LIB		= ranlib

CC		= cc



CFLAGS = -Wall -Wextra -Werror


${NAME}:	${OBJS}
	${AR} ${NAME} ${OBJS}
	${LIB} ${NAME}

${OBJS}:	%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

.c.o:
	${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c-.o}

all:	$(NAME)

clean:
	@$(RM) ${OBJS} ${BONUS_OBJS}

fclean:	clean
		@$(RM) -f ${NAME} libftprintf.co

re:		fclean all

.PHONY: all clean fclean re

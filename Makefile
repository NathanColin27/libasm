# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nathan <nathan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 11:10:58 by nathan            #+#    #+#              #
#    Updated: 2021/02/20 08:51:12 by nathan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libasm.a

ASM			= nasm
ASMFLAGS	= -f elf64

AR			= ar rcs

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

SRCS 		=	srcs/ft_strlen.s \
				srcs/ft_strcmp.s \
				srcs/ft_write.s \
				srcs/ft_read.s \
				srcs/ft_strcpy.s \
				srcs/ft_strdup.s \

OBJS 		= $(SRCS:.s=.o)

TICK = \342\234\224
RE = \342\231\272
TRASH = \360\237\227\221

default:
	@make -s all

%.o:%.s
	$(ASM) $(ASMFLAGS) -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@echo "\033[32;1m\rLibasm compiled ${TICK}          \033[0m"

test: $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME) -o test
	@echo "\033[32;1m\rTest compiled ${TICK}          \033[0m"

clean:
	rm -rf $(OBJS)
	rm -rf test
	@echo "\033[32;1m\rDirectory cleaned ${TRASH}          \033[0m"

fclean:	clean
	@rm -rf $(NAME)
	@echo "\033[32;1m\rDirectory fully cleaned ${TRASH} ${TRASH} ${TRASH}          \033[0m"

re:
	@echo "\033[32;1m\rMinishell recompiling ${RE}          \033[0m"
	@make -s fclean 
	@make -s all

.PHONY:	all test clean fclean re
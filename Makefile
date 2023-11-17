# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 10:42:39 by fbock             #+#    #+#              #
#    Updated: 2023/11/15 10:42:40 by fbock            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap
CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra -Wunreachable-code-return
DFLAGS 	:= -g

LIBPRINTF := ./libs/printf
LIBFT := ./libs/libft
HEADERS	:= -I $(LIBFT) -I $(LIBPRINTF) -I ./include
LIBS	:= $(LIBPRINTF)/libftprintf.a $(LIBFT)/libft.a

SRCS	:= src/push_swap.c src/parse_arg.c src/stack_ops.c \
           src/list_utils.c src/parsing_utils.c src/stack_utils.c \
		   src/sorting_utils.c src/sorting_algo.c src/sort_rest.c

OBJS	:= ${SRCS:.c=.o}
DOBJS   := ${SRCS:.c=.d.o}

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

%.d.o: %.c
	$(CC) $(CFLAGS) $(DFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT) bonus
	$(MAKE) -C $(LIBPRINTF) bonus
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

debug: $(DOBJS)
	$(MAKE) -C $(LIBFT) debug
	$(MAKE) -C $(LIBPRINTF) debug

	$(CC) $(CFLAGS) $(DFLAGS) $(DOBJS) $(LIBS) $(HEADERS) -o push_swap_debug

clean:
	$(MAKE) -C $(LIBPRINTF) clean
	$(MAKE) -C $(LIBFT) clean
	rm	-rf $(OBJS) $(DOBJS)

fclean: clean
	$(MAKE) -C $(LIBPRINTF) fclean
	$(MAKE) -C $(LIBFT) fclean
	@rm -rf $(NAME) push_swap_debug

re: clean all

.PHONY: all, clean, fclean, re

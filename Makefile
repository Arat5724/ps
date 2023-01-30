# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeongble <jeongble@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/21 11:45:45 by jeongble          #+#    #+#              #
#    Updated: 2022/07/22 10:21:58 by jeongble         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = #-Wall -Wextra -Werror
NAME = push_swap
SRCS =  push_swap.c push_swap_parse.c push_swap_node.c push_swap_op.c \
		push_swap_op_node.c push_swap_stack.c push_swap_sort.c \
		push_swap_op1.c push_swap_op2.c push_swap_op3.c \
		ft_atoi_err.c \
		push_swap_queue.c \
		push_swap_queue_valid.c sort.c op.c
CHCKER = checker
B_SRCS = checker.c push_swap_parse.c push_swap_node.c push_swap_op.c \
		push_swap_op_node.c push_swap_stack.c push_swap_sort.c \
		push_swap_op1.c push_swap_op2.c push_swap_op3.c \
		ft_atoi_err.c \
		push_swap_queue.c \
		push_swap_queue_valid.c \
		get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)
LIBDIR = ft_printf
LIBFT = $(LIBDIR)/libftprintf.a

all : $(NAME)

bonus : $(CHCKER)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBDIR) -lftprintf -o $(NAME)

$(CHCKER) : $(LIBFT) $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) -L$(LIBDIR) -lftprintf -o $(CHCKER)

$(LIBFT) :
	make -C $(LIBDIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make clean -C $(LIBDIR)
	rm -f push_swap.o $(B_OBJS)

fclean : clean
	rm -f $(LIBFT)
	rm -f $(NAME)
	rm -f $(CHCKER)

re :
	make fclean
	make all

.PHONY: all bonus clean fclean re
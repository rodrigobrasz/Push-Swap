# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/02 01:08:48 by rodcaeta          #+#    #+#              #
#    Updated: 2026/02/23 00:33:27 by rodcaeta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

CC := cc
CFLAGS := -Wall -Wextra -Werror
INCLUDES := -Iincludes

SRCS := \
	main.c \
	src/stack_init.c \
	src/index.c \
	src/node_utils.c \
	error/display_error.c \
	parsing/parsing.c \
	src/node_utils.c \
	operations/push.c \
	operations/reverse.c \
	operations/rotate.c \
	operations/swap.c

OBJS := $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
		@$(RM) $(NAME)
	@echo "$(RESET)"
	@echo			⠀⠀⠀⠀⠀⠀⠀"	⢀⣠⣤⣶⣶⣶⣶⣶⣤⣄⡀"⠀⠀⠀⠀⠀⠀⠀⠀⠀
	@echo		⠀⠀⠀⠀⠀	"⣠⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣄⡀"⠀⠀⠀⠀⠀
	@echo		⠀⠀⠀"⣠⣴⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣮⣵⣄"⠀⠀⠀
	@echo		⠀⠀"⢾⣻⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⡀"⠀
	@echo		⠀"⠸⣽⣻⠃⣿⡿⠋⣉⠛⣿⣿⣿⣿⣿⣿⣿⣿⣏⡟⠉⡉⢻⣿⡌⣿⣳⡥"⠀
	@echo		⠀"⢜⣳⡟⢸⣿⣷⣄⣠⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣤⣠⣼⣿⣇⢸⢧⢣"⠀
	@echo		⠀"⠨⢳⠇⣸⣿⣿⣿⣿⣿⣿⣿⡿⠿⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⠀⡟⢆"⠀
	@echo		⠀⠀"⠈⠀⣾⣿⣿⣿⣿⣿⣿⣿⡀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣽⣿⣿⠐⠈"⠀⠀
	@echo		⠀"⢀⣀⣼⣷⣭⣛⣯⡝⠿⢿⣛⣋⣤⣤⣀⣉⣛⣻⡿⢟⣵⣟⣯⣶⣿⣄⡀"⠀
	@echo		"⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣶⣶⣾⣶⣶⣴⣾⣿⣿⣿⣿⣿⣿⢿⣿⣿⣧"
	@echo		"⣿⣿⣿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⣿⡿"

re: fclean all
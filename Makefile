# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/02 01:08:48 by rodcaeta          #+#    #+#              #
#    Updated: 2026/02/26 22:26:33 by rodcaeta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

CC := cc -g
CFLAGS := -Wall -Wextra -Werror
INCLUDES := -Iincludes

# simulator rules -- make sim MIN="num" MAX="num" COUNT="num" | make sim ARGS="your arguments" 
MIN = 0
MAX = 500
COUNT = 10
ARGS = $(shell shuf --input-range $(MIN)-$(MAX) --head-count $(COUNT))

SRCS := \
	main.c \
	src/stack_init.c \
	src/index.c \
	src/node_utils.c \
	error/display_error.c \
	parsing/parsing.c \
	operations/push.c \
	operations/reverse.c \
	operations/rotate.c \
	operations/swap.c \
	operations/short_moves.c

OBJS := $(SRCS:.c=.o)
#COLLORS ANSI =

GREEN = \033[0;32m # 
RED = \033[0;31m #
BLUE = \033[0;34m #
YELLOW = \033[0;33m #
RESET = \033[0m #

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	@echo "$(YELLOW)Compiling:$(RESET) $(BLUE)$<$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

sim:
	./push_swap_simulator $(ARGS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@$(RM) $(NAME)
	@echo "$(RESET)"
	@echo			"	⢀⣠⣤⣶⣶⣶⣶⣶⣤⣄⡀"⠀⠀⠀⠀⠀⠀⠀⠀⠀
	@echo		"    ⣠⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣄⡀"⠀⠀⠀⠀⠀
	@echo	" ⣠⣴⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣮⣵⣄"⠀⠀⠀
	@echo	" ⢾⣻⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⡀"⠀
	@echo	"⠸⣽⣻⠃⣿⡿⠋⣉⠛⣿⣿⣿⣿⣿⣿⣿⣿⣏⡟⠉⡉⢻⣿⡌⣿⣳⡥"⠀
	@echo	"⢜⣳⡟⢸⣿⣷⣄⣠⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣤⣠⣼⣿⣇⢸⢧⢣"⠀
	@echo	"⠨⢳⠇⣸⣿⣿⣿⣿⣿⣿⣿⡿⠿⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⠀⡟⢆"⠀
	@echo	"⠈⠀⣾⣿⣿⣿⣿⣿⣿⣿⡀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣽⣿⣿⠐⠈"⠀⠀
	@echo	"⢀⣀⣼⣷⣭⣛⣯⡝⠿⢿⣛⣋⣤⣤⣀⣉⣛⣻⡿⢟⣵⣟⣯⣶⣿⣄⡀"⠀
	@echo "⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣶⣶⣾⣶⣶⣴⣾⣿⣿⣿⣿⣿⣿⢿⣿⣿⣧"
	@echo "⣿⣿⣿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⣿⡿"

re: fclean all

.PHONY: all clean fclean re 	
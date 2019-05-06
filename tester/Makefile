# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 11:00:31 by fmaury            #+#    #+#              #
#    Updated: 2019/05/03 13:02:25 by cbarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

LIB			= libtester.a

SRC			= ft_signal.c \
			  ft_tests.c \
			  minilib_part1.c \
			  minilib_part2.c

OBJ			= $(SRC:.c=.o)

INC			= inc

SRC_DIR		= src
OBJ_DIR		= obj

SRCS		= $(addprefix $(SRC_DIR)/, $(SRC))
OBJS		= $(addprefix $(OBJ_DIR)/, $(OBJ))

all : $(LIB)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@  -I $(INC)

$(LIB): $(OBJS)
	ar -rc $(LIB) $(OBJS)
	ranlib $(LIB)
	@echo "$@ built\t\t\033[0;32m✓\033[0m"

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(LIB)

re: fclean all

.PHONY: all clean fclean re

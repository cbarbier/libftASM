# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/30 17:01:06 by cbarbier          #+#    #+#              #
#    Updated: 2019/04/30 17:06:31 by cbarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE			= tester

SRC			= main.c

OBJ			= $(SRC:.s=.o)

INC			= inc/tester.h

SRC_DIR		= src
OBJ_DIR		= obj

SRCS		= $(addprefix $(SRC_DIR)/, $(SRC))
OBJS		= $(addprefix $(OBJ_DIR)/, $(OBJ))

all: $(EXE)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	gcc -c $< -o $@

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(EXE)

re: fclean all

.PHONY: all clean fclean re
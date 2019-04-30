# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 11:00:31 by fmaury            #+#    #+#              #
#    Updated: 2019/04/30 15:53:08 by cbarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NASM		= /Users/cbarbier/.brew/Cellar/nasm/2.14.02/bin/nasm
NASM		= nasm

FLAGS		= -f macho64

LOADER		= ld -macosx_version_min 10.8 -lSystem

LIB			= libfts.a


SRC			= ft_bzero.s

OBJ			= $(SRC:.s=.o)

SRC_DIR		= src
OBJ_DIR		= obj

SRCS		= $(addprefix $(SRC_DIR)/, $(SRC))
OBJS		= $(addprefix $(OBJ_DIR)/, $(OBJ))

all : $(LIB)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	@mkdir -p $(OBJ_DIR)
	$(NASM) $(FLAGS) $< -o $@ 

$(LIB): $(OBJS)
	ar -rc $(LIB) $(OBJS)
	@echo "$@ LibftASM built\t\t\033[0;32m✓\033[0m"

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(LIB)

re: fclean all

.PHONY: all clean fclean re

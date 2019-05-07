# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 11:00:31 by fmaury            #+#    #+#              #
#    Updated: 2019/05/07 14:31:18 by cbarbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NASM		= /Users/cbarbier/.brew/Cellar/nasm/2.14.02/bin/nasm
NASM		= nasm

FLAGS		= -f macho64

LOADER		= ld -macosx_version_min 10.8 -lSystem

NAME		= libfts.a

TEST_SRC	= tests/main.c \
			  tests/test_bzero.c \
			  tests/test_strcat.c \
			  tests/test_isalpha.c \
			  tests/test_isdigit.c \
			  tests/test_isalnum.c \
			  tests/test_isascii.c \
			  tests/test_isprint.c \
			  tests/test_isupper.c \
			  tests/test_islower.c \
			  tests/test_tolower.c \
			  tests/test_toupper.c \
			  tests/test_puts.c \
			  tests/test_strlen.c \
			  tests/test_memset.c \
			  tests/test_memcpy.c \
			  tests/test_strdup.c \
			  tests/test_strchr.c \
			  tests/test_cat.c \
			  tests/test_putchar.c \
			  tests/test_swapbits.c \
			  tests/test_putnbr.c

TEST_EXE	= tester.out

SRC			= ft_bzero.s \
			  ft_strcat.s \
			  ft_isalpha.s \
			  ft_isdigit.s \
			  ft_isalnum.s \
			  ft_isascii.s \
			  ft_isprint.s \
			  ft_isupper.s \
			  ft_islower.s \
			  ft_tolower.s \
			  ft_toupper.s \
			  ft_puts.s \
			  ft_strlen.s \
			  ft_memset.s \
			  ft_memcpy.s \
			  ft_strdup.s \
			  ft_strchr.s \
			  ft_cat.s \
			  ft_putchar.s \
			  ft_swapbits.s \
			  ft_putnbr.s

OBJ			= $(SRC:.s=.o)

INC			= inc/libfts.h

SRC_DIR		= src
OBJ_DIR		= obj

SRCS		= $(addprefix $(SRC_DIR)/, $(SRC))
OBJS		= $(addprefix $(OBJ_DIR)/, $(OBJ))

all : $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	@mkdir -p $(OBJ_DIR)
	$(NASM) $(FLAGS) $< -o $@ 

$(NAME): $(OBJS) $(INC)
	ar -rc $(NAME) $(OBJS)
	@echo "$@ LibftASM built\t\t\033[0;32m✓\033[0m"

tests: $(NAME)
	Make -C tester
	$(CC) $(TEST_SRC) -o $(TEST_EXE) -L. -lfts -L tester -ltester -I inc -I tester/inc -I tests
	./$(TEST_EXE)

clean:
	Make -C tester clean
	rm -rf $(OBJS)
	rm -rf $(OBJ_DIR)

fclean: clean
	Make -C tester fclean
	rm -rf $(TEST_EXE)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re tests

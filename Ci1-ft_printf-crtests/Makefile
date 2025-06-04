# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/22 21:15:03 by reciak            #+#    #+#              #
#    Updated: 2025/06/04 09:54:36 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNIT_TESTS_FILE := ft_printf-tests.c
OUT := $(basename $(UNIT_TESTS_FILE))

CC := cc
CFLAGS =  -Wall -Wextra -Werror -I$(INC_DIR1) -I$(INC_DIR2)
LFLAGS = -lcriterion $(LIBFT_AR)
RM    := rm -f

BASE_DIR  := ../../
INC_DIR1  := $(BASE_DIR)inc/
INC_DIR2  := $(BASE_DIR)libft/
LIBFT_DIR := $(BASE_DIR)libft/
LIBFT_AR  := $(LIBFT_DIR)libft.a

SRCS := \
src/ft_printf.c

SRCS := $(addprefix $(BASE_DIR),$(SRCS))
SRCS := $(SRCS) $(UNIT_TESTS_FILE)

.PHONY: dummy_test
dummy_test:
	@echo 'A test when developing the Makefile (and makefile) for ft_printf'
	@echo '1. Compiling tests'
	@echo '   -->  $(OUT)'
	@$(CC) $(CFLAGS) $(SRCS) $(LFLAGS) -o $(OUT)
	@echo '2. Executing tests'
	@echo '      ./$(OUT)'
	@./$(OUT)
	

.PHONY: alltests
alltests:
	@echo 'Not implemented yet beyond this dummy version...'

.PHONY: fclean
fclean:
	$(RM) $(OUT)

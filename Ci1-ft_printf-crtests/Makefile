# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/22 21:15:03 by reciak            #+#    #+#              #
#    Updated: 2025/06/04 18:17:34 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNIT_TESTS_FILE := ft_printf-tests.c
OUT := $(basename $(UNIT_TESTS_FILE))

CC := cc
CFLAGS = -Wall -Wextra -Werror -Wno-format-security -I$(INC_DIR1) -I$(INC_DIR2)
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

.PHONY: unit-tests
unit-tests: provide-libft
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

.PHONY: provide-libft
provide-libft:
	@echo "Checking if $(LIBFT_AR) is present ..."
	@if [ ! -e $(LIBFT_AR) ]; then \
	  echo '   ... Not found --> trying to create it'; \
	  sleep 2; \
	  make -C $(LIBFT_DIR) all; \
	  -make -C $(LIBFT_DIR) bonus; \
	  make -C $(LIBFT_DIR) clean; \
	else \
	  echo '   ... Found!'; \
	fi


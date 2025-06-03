# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/22 21:15:03 by reciak            #+#    #+#              #
#    Updated: 2025/06/03 19:54:13 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC_DIR1 := ../../inc/
INC_DIR2 := ../../libft/


CC := cc
CFLAGS =  -Wall -Wextra -Werror 
CFLAGS += -I$(INC_DIR1) -I$(INC_DIR2)
CFLGAS += -lcriterion -lftprintf -lft


BASE_DIR := ../../

SRCS := \
src/ft_printf.c

SRCS := $(addprefix $(BASE_DIR),$(SRCS))

.PHONY:
dummy_test:
	@echo 'A test when developing the Makefile (and makefile) for ft_printf'
	
	$(CC) $(CFLAGS) ft_printf_test.c $(SRCS)

.PHONY: alltests
alltests:
	@echo 'Not implemented yet beyond this dummy version...'

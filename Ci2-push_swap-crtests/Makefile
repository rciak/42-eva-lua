# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/22 21:15:03 by reciak            #+#    #+#              #
#    Updated: 2025/07/28 15:48:17 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#This Makefile should be calles from the Makefile in the base dir ../..
BASE_DIR        := ../../

# DO NOT CHANGE UNLESS YOU KNOW WHAT YOU ARE DOING
PROJECT_TITLE    := push_swap
UNIT_TESTS_FILE  := criterion-tests.c
SRC_MANUAL_TEST := manual-test.c manual-test-tools.c \

SRCS_FROM_BASE   = $(addprefix $(BASE_DIR), $(SRCS))
SRC_MANUAL_TEST += $(SRCS_FROM_BASE)

# ADOPT:
#   BASE_DIR:      Location of Makefile (the one that builts the project target)
#   INC_DIRS:      Locations where header files are, e.g.
#                     libftprintf.h   and  libft.h  
#   LIB_FILE_NAME:    libftprintf.a  (probably no need to change)
LIBFTDIR        := libft/
INC_DIRS        := inc/  $(LIBFTDIR)
LIB_FILE_NAME   := libft.a

INC_DIRS      := $(addprefix -I$(BASE_DIR),$(INC_DIRS))
OUT_UNIT_TEST := $(basename $(UNIT_TESTS_FILE))
LIB_FILE      := $(BASE_DIR)/$(LIBFTDIR)/$(LIB_FILE_NAME)

CC     := cc
CFLAGS := -Wall -Wextra -Werror
CFLAGS += -Wno-format-security#To prevent warning issues (printf -security)
CFLAGS += $(INC_DIRS)
LDFLAGS = -lcriterion $(LIB_FILE)
ifeq ($(DEBUG_LAUB_SAN), 1)
  CFLAGS  += -g3 -fsanitize=address,undefined,leak
  LDFLAGS += -g3 -fsanitize=address,undefined,leak
endif
ifeq ($(DEBUG_M_SAN), 1)
  CFLAGS  += -g3 -fsanitize=memory -fsanitize-memory-track-origins=2
  LDFLAGS += -g3 -fsanitize=memory -fsanitize-memory-track-origins=2
endif
ifeq ($(DEBUG_VALGRIND), 1)
  CFLAGS  += -g3
  LDFLAGS += -g3
endif
RM    := rm -f

.PHONY: unit-tests
unit-tests:
	@echo
	@echo '************ This is 42-eva-lua for $(PROJECT_TITLE) ************'
	@echo
	@echo '1. Calling make in $(BASE_DIR) which should provide $(LIB_FILE_NAME)'
	@echo '-------'
	@make -C $(BASE_DIR)
	@echo '-------'
	@echo 'Looking in $(BASE_DIR) for $(LIB_FILE_NAME) ...'
	@if [ ! -e $(LIB_FILE) ]; then \
	  echo '   ... Not found. Stop.' && exit 1; \
	else \
	  echo '   ... Found! Continuing.'; \
	fi
	@echo '2. Compiling tests'
	@echo '   -->  $(OUT_UNIT_TEST)'
	@$(CC) $(CFLAGS) $(UNIT_TESTS_FILE) $(LDFLAGS) -o $(OUT_UNIT_TEST)
	@echo '3. Executing tests'
	@echo '      ./$(OUT_UNIT_TEST)'
	@echo
	@./$(OUT_UNIT_TEST)

OUT_MAN_TEST := manual_test_$(NAME) # NAME is being exported from ../../Makefile
.PHONY: manual-test
manual-test: show_vars
	$(CC) $(CFLAGS) $(SRC_MANUAL_TEST) $(LIB_FILE) -o $(OUT_MAN_TEST)
	@echo 'Sample use of manual test:'

.PHONY: fclean
fclean:
	$(RM) $(OUT_UNIT_TEST)
	$(RM) $(OUT_MAN_TEST)

.PHONY: re
re: fclean unit-tests

.PHONY: show_vars
show_vars:
	@echo "CFLAGS:          |$(CFLAGS)|"
	@echo "OBJ_DIR:         |$(OBJ_DIR)|"
	@echo "SRCS:            |$(SRCS)|"
	@echo "SRCS_FROM_BASE:  |$(SRCS_FROM_BASE)|"
	@echo "SRC_MANUAL_TEST: | $$(echo $(SRC_MANUAL_TEST) | tr ' ' '\n')|"

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/28 10:20:36 by reciak            #+#    #+#              #
#    Updated: 2025/06/28 13:52:53 by reciak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# External users: DO NOT CHANGE
PROJECT_TITLE    := get_next_line
UNIT_TESTS_FILE  := get_next_line-tests.c
SRC_MANUAL_TEST := manual_test_get_next_line.c

# External users: Please ADOPT:
#   BASE_DIR:      Location of Makefile (the one that builts the project target)
#   INC_DIRS:      Locations where header files are, e.g.
#                     libftprintf.h   and  libft.h  
BASE_DIR        := ../../
INC_DIRS        := ../../
INC_DIRS      := $(addprefix -I,$(INC_DIRS))
OUT_UNIT_TEST := $(basename $(UNIT_TESTS_FILE))

CC     := cc
CFLAGS := -Wall -Wextra -Werror
CFLAGS += $(INC_DIRS)
ifeq ($(DEBUG), 1)
	CFLAGS += -g3 -fsanitize=address,undefined,leak
endif
SRCS := $(BASE_DIR)/get_next_line.c \
		$(BASE_DIR)/get_next_line_utils.c
LFLAGS = -lcriterion
RM    := rm -f

.PHONY: unit-tests
unit-tests:
	@echo
	@echo '************ This is 42-eva-lua for $(PROJECT_TITLE) ************'
	@echo
	@echo '1. Calling make in $(BASE_DIR) which should provide $(LIB_FILE_NAME)'
	@echo '  --> Step not needed for get_next_line <--'
	@echo '2. Compiling tests'
	@echo '   -->  $(OUT_UNIT_TEST)'
	$(CC) $(CFLAGS) $(UNIT_TESTS_FILE) $(SRCS) $(LFLAGS) -o $(OUT_UNIT_TEST)
	@echo '3. Executing tests'
	@echo '      ./$(OUT_UNIT_TEST)'
	@echo
	@./$(OUT_UNIT_TEST)

OUT_MAN_TEST = $(patsubst %.c,%,$(SRC_MANUAL_TEST))
.PHONY: manual-test
manual-test:
	$(CC) -o $(OUT_MAN_TEST) $(CFLAGS) $(SRC_MANUAL_TEST) $(SRCS) $(LIB_FILE)
	@echo 'Sample use of manual test:'
	@echo "  ./$(OUT_MAN_TEST)"

.PHONY: fclean
fclean:
	$(RM) $(OUT_UNIT_TEST)
	$(RM) $(OUT_MAN_TEST)

.PHONY: re
re: fclean unit-tests


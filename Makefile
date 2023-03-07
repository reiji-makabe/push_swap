# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 17:23:21 by rmakabe           #+#    #+#              #
#    Updated: 2023/03/05 18:01:06 by rmakabe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
CC := cc

ifdef WITH_DEBUG
	DEBUG := -O0 -g3
endif

CFLAGS := -Wall -Wextra -Werror $(DEBUG) -I
RM := rm -rf
AR := ar -rcs

INCLUDE := include/
SRC_DIR := src/
OBJ_DIR := obj/
ARCHIVE := archive/libftprintf.a
ARCHIVE_DIR := 42_chores/ft_printf

SRC := $(wildcard $(SRC_DIR)*.c)
OBJ := $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))


# command
all: $(NAME) $(ARCHIVE)

$(NAME):$(OBJ)
	@mkdir -p $(OBJ_DIR)
ifeq ("$(wildcard $(ARCHIVE))", "")
	make $(ARCHIVE)
endif
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $(NAME) $(ARCHIVE)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(ARCHIVE):
ifdef WITH_DEBUG
	make debug -C $(ARCHIVE_DIR)
endif

clean:
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(ARCHIVE_DIR)
	$(RM) $(NAME) $(ARCHIVE)

re: fclean all

debug:
	make WITH_DEBUG=1

norm:
	norminette $(SRC_DIR) $(INCLUDE) | grep Error || true

.PHONY: all clean fclean re debug norm

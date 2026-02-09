# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:   #
#                                                     +:+ +:+         +:+     #
#    By: fdinis-d <fdinis-d@student.42lisboa.com>   +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+           #
#    Created: 2026/02/01                               #+#    #+#             #
#    Updated: 2026/02/09                              ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# Colors
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
RED			= \033[1;31m
RESET		= \033[0m

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= includes
LIBFT_DIR	= libft

SRC_FILES	= main.c \
			  stack/stack_init.c \
			  stack/stack_utils.c \
			  operations/swap.c \
			  operations/push.c \
			  operations/rotate.c \
			  operations/reverse_rotate.c \
			  parsing/parse_args.c \
			  parsing/validation.c \
			  sorting/sort_small.c \
			  sorting/sort_utils.c \
			  sorting/chunk_sort.c \
			  sorting/chunk_utils.c \
			  utils/free.c

SRC			= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
LIBFT		= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@printf "$(BLUE)[push_swap]$(RESET) Linking $(GREEN)$(NAME)$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)
	@printf "$(GREEN)[push_swap]$(RESET) Build complete!\n"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@printf "$(BLUE)[push_swap]$(RESET) Compiling $(GREEN)$<$(RESET)\n"
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	@printf "$(YELLOW)[push_swap]$(RESET) Cleaning object files...\n"
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@printf "$(RED)[push_swap]$(RESET) Removing $(NAME)\n"
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

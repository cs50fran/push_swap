NAME        = libft.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# Colors
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
RED         = \033[1;31m
RESET       = \033[0m

SRC_DIR     = .
OBJ_DIR     = obj

SRC_FILES   = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
		ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
		ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS_SRC_FILES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		    ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		    ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

SRC        = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
BONUS_SRC  = $(addprefix $(SRC_DIR)/, $(BONUS_SRC_FILES))
OBJ        = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
BONUS_OBJ  = $(addprefix $(OBJ_DIR)/, $(BONUS_SRC_FILES:.c=.o))

all: $(NAME)


$(NAME): $(OBJ)
	@printf "$(BLUE)[libft]$(RESET) Linking $(GREEN)$(NAME)$(RESET)\n"
	@ar rcs $(NAME) $(OBJ)
	@printf "$(GREEN)[libft]$(RESET) Build complete!\n"


bonus: $(OBJ) $(BONUS_OBJ)
	@printf "$(BLUE)[libft]$(RESET) Linking bonus $(GREEN)$(NAME)$(RESET)\n"
	@ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)
	@printf "$(GREEN)[libft]$(RESET) Bonus build complete!\n"


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@printf "$(BLUE)[libft]$(RESET) Compiling $(GREEN)$<$(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@


$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@printf "$(BLUE)[libft]$(RESET) Compiling $(GREEN)$<$(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@


clean:
	@printf "$(YELLOW)[libft]$(RESET) Cleaning object files...\n"
	@rm -rf $(OBJ_DIR)


fclean: clean
	@printf "$(RED)[libft]$(RESET) Removing $(NAME)\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
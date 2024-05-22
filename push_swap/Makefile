##########################################################
## Makefile

####################
## Variables

NAME		=	push_swap

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

LIBFT_DIR	=	./Libft
LIBFT		=	$(LIBFT_DIR)/libft.a

PRINTF_DIR	=	./ft_printf
PRINTF		=	$(PRINTF_DIR)/libftprintf.a


SRC_DIR		=	./src
OBJ_DIR		=	./obj


SRC			=	$(SRC_DIR)/push_swap.c \
				$(SRC_DIR)/list_utils.c \
				$(SRC_DIR)/stack_utils.c \
				$(SRC_DIR)/checkinput.c \
				$(SRC_DIR)/algorithme.c \
				$(SRC_DIR)/instruct.c


OBJ			=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)



####################
## Rules

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(LIBFT) $(PRINTF) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) -I $(PRINTF_DIR) -c $< -o $@



clean:
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean



fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean



re: fclean all

.PHONY: all clean fclean re

##########################################################
## Makefile

####################
## Variables

NAME1		=	server
NAME2		=	client

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g

PRINTF_DIR	=	./ft_printf
PRINTF		=	$(PRINTF_DIR)/libftprintf.a


SRC_DIR		=	./src
OBJ_DIR		=	./obj


SRC_SERVEUR	=	$(SRC_DIR)/server.c \
				$(SRC_DIR)/minitalk_utils.c \
				$(OBJ_DIR)/utils.c

SRC_CLIENT	=	$(SRC_DIR)/client.c \
				$(SRC_DIR)/minitalk_utils.c \
				$(SRC_DIR)/utils.c



OBJ_SERVEUR = $(OBJ_DIR)/server.o \
			  $(OBJ_DIR)/minitalk_utils.o \
			  $(OBJ_DIR)/utils.o

OBJ_CLIENT = $(OBJ_DIR)/client.o \
			 $(OBJ_DIR)/minitalk_utils.o \
			 $(OBJ_DIR)/utils.o


####################
## Rules

all: $(NAME1) $(NAME2)


$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)


$(NAME1): $(PRINTF) $(OBJ_SERVEUR)
	@$(CC) $(CFLAGS) $(OBJ_SERVEUR) $(PRINTF) -o $@

$(NAME2): $(PRINTF) $(OBJ_CLIENT)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) $(PRINTF) -o $@



$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(PRINTF_DIR)



clean:
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C $(PRINTF_DIR) clean



fclean: clean
	@$(RM) $(NAME1) $(NAME2)
	@$(MAKE) -C $(PRINTF_DIR) fclean



re: fclean all

.PHONY: all clean fclean re

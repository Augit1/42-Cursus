##########################################################
## Makefile

####################
## Variables

NAME		=	philo_bonus

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
LDFLAGS		=	-lpthread

SRC_DIR		=	./src
OBJ_DIR		=	./obj


SRC			=	$(SRC_DIR)/philo.c \
				$(SRC_DIR)/ft_atoi.c \
				$(SRC_DIR)/initialisation.c \
				$(SRC_DIR)/check.c \
				$(SRC_DIR)/utils.c \

OBJ			=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)



####################
## Rules

all: $(NAME)


$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<


clean:
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re

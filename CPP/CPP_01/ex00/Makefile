##########################################################
## Makefile

####################
## Variables

NAME		=	BraiiiiiiinnnzzzZ

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98


SRC_DIR		=	./src
OBJ_DIR		=	./obj


SRC			=	$(SRC_DIR)/main.cpp \
				$(SRC_DIR)/newZombie.cpp \
				$(SRC_DIR)/randomChump.cpp \
				$(SRC_DIR)/Zombie.cpp \

OBJ			=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


####################
## Rules

all: $(NAME)


$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<


clean:
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re

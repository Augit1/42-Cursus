##########################################################
## Makefile

####################
## Variables

NAME		=	Polymorphism

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98


SRC_DIR		=	./src
OBJ_DIR		=	./obj


SRC			=	$(SRC_DIR)/main.cpp \
				$(SRC_DIR)/Animal.cpp  \
				$(SRC_DIR)/Dog.cpp  \
				$(SRC_DIR)/Cat.cpp  \
				$(SRC_DIR)/WrongAnimal.cpp  \
				$(SRC_DIR)/WrongCat.cpp  \

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

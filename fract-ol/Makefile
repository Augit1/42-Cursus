##########################################################
## Makefile

####################
## Variables

OS := $(shell uname)

ifeq ($(OS), Darwin)
	MLX_DIR		=	./mlx-mac
	MLX_FLAGS	=	-L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -g -O3
else
	MLX_DIR		=	./mlx-linux
	MLX_FLAGS	=	-L$(MLX_DIR) -lmlx -lXext -lX11 -lm -g
endif


NAME		=	fractol

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

INCLUDES	=	-I$(MLX_DIR)


SRC_DIR		=	./src
OBJ_DIR		=	./obj


SRC			=	$(SRC_DIR)/fractol.c \
				$(SRC_DIR)/ft_atoi_double.c \
				$(SRC_DIR)/ft_itoi_double.c \
				$(SRC_DIR)/julia.c	\
				$(SRC_DIR)/mandelbrot.c	\
				$(SRC_DIR)/burningship.c	\
				$(SRC_DIR)/keys_hook.c \
				$(SRC_DIR)/window.c \
				$(SRC_DIR)/initialisation.c \
				$(SRC_DIR)/utils.c \
				$(SRC_DIR)/color.c \
				$(SRC_DIR)/animate.c

OBJ			=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)



####################
## Rules

all: $(NAME)


$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^ $(MLX_FLAGS) $(INCLUDES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)


clean:
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re

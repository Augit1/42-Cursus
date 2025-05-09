##########################################################
## Makefile

####################
## Variables

OS := $(shell uname)

ifeq ($(OS), Darwin)
	MLX_DIR		=	./libs/minilibx-mac
	MLX_FLAGS	=	-L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -g -O3
	MLX			=	$(MLX_DIR)/libmlx.a
else
	MLX_DIR		=	./libs/minilibx-linux
	MLX_FLAGS	=	-L$(MLX_DIR) -lmlx -lXext -lX11 -lm -g
	MLX			=	$(MLX_DIR)/libmlx.a
endif


NAME		=	cub3D

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

LIBFT_DIR	=	./libs/Libft
LIBFT		=	$(LIBFT_DIR)/libft.a

INCLUDES	=	-I$(MLX_DIR) -I$(INC_DIR) -I$(LIBFT_DIR)/inc

SRC_DIR		=	./src
OBJ_DIR		=	./obj
INC_DIR		=	./inc


SRC			=	$(SRC_DIR)/main.c \
				$(SRC_DIR)/parser/parser_utils.c \
				$(SRC_DIR)/parser/parser_config.c \
				$(SRC_DIR)/parser/parser_config_utils.c \
				$(SRC_DIR)/parser/parser_file.c \
				$(SRC_DIR)/parser/parser_map.c \
				$(SRC_DIR)/initialisation/init_display.c \
				$(SRC_DIR)/initialisation/init_game.c \
				$(SRC_DIR)/initialisation/init_texture.c \
				$(SRC_DIR)/initialisation/init_utils.c \
				$(SRC_DIR)/controls/controls_keys.c \
				$(SRC_DIR)/controls/controls_move.c \
				$(SRC_DIR)/controls/controls_rotate.c \
				$(SRC_DIR)/raycasting/raycasting.c \
				$(SRC_DIR)/raycasting/raycasting_maths.c \
				$(SRC_DIR)/raycasting/raycasting_utils.c \

OBJ			=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)



####################
## Rules

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)


$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) $(MLX_FLAGS) $(INCLUDES)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)


mlx:
	@$(MAKE) -C $(MLX_DIR)

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean


fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean


re: fclean all


.PHONY: all clean fclean re mlx

##########################################################
## Makefile

####################
## Variables

NAME		=	libft.a

#BONUS		=	.libftbonus

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
INCLUDE		=	-I$(INC_DIR)


SRC_DIR		=	./src
OBJ_DIR		=	./obj
INC_DIR		=	./inc


####################
## Files

SRC = $(SRC_DIR)/ft_atoi.c \
	  $(SRC_DIR)/ft_bzero.c \
	  $(SRC_DIR)/ft_calloc.c \
	  $(SRC_DIR)/ft_isalnum.c \
	  $(SRC_DIR)/ft_isalpha.c \
	  $(SRC_DIR)/ft_isascii.c \
	  $(SRC_DIR)/ft_isdigit.c \
	  $(SRC_DIR)/ft_isprint.c \
	  $(SRC_DIR)/ft_itoa.c \
	  $(SRC_DIR)/ft_memchr.c \
	  $(SRC_DIR)/ft_memcmp.c \
	  $(SRC_DIR)/ft_memcpy.c \
	  $(SRC_DIR)/ft_memmove.c \
	  $(SRC_DIR)/ft_memset.c \
	  $(SRC_DIR)/ft_putchar_fd.c \
	  $(SRC_DIR)/ft_putendl_fd.c \
	  $(SRC_DIR)/ft_putnbr_fd.c \
	  $(SRC_DIR)/ft_putstr_fd.c \
	  $(SRC_DIR)/ft_split.c \
	  $(SRC_DIR)/ft_strchr.c \
	  $(SRC_DIR)/ft_strdup.c \
	  $(SRC_DIR)/ft_striteri.c \
	  $(SRC_DIR)/ft_strjoin.c \
	  $(SRC_DIR)/ft_strlcat.c \
	  $(SRC_DIR)/ft_strlcpy.c \
	  $(SRC_DIR)/ft_strlen.c \
	  $(SRC_DIR)/ft_strmapi.c \
	  $(SRC_DIR)/ft_strncmp.c \
	  $(SRC_DIR)/ft_strnstr.c \
	  $(SRC_DIR)/ft_strrchr.c \
	  $(SRC_DIR)/ft_strtrim.c \
	  $(SRC_DIR)/ft_substr.c \
	  $(SRC_DIR)/ft_tolower.c \
	  $(SRC_DIR)/ft_toupper.c \
	  $(SRC_DIR)/ft_secured_realloc.c \
	  $(SRC_DIR)/ft_atoi_double.c \
	  $(SRC_DIR)/ft_itoa_double.c \
	  $(SRC_DIR)/ft_secure_free.c \
	  $(SRC_DIR)/ft_free_array.c \


OBJ			=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


####################
## Bonus files

BONUS_SRC	=	$(SRC_DIR)/ft_lstadd_back_bonus.c \
				$(SRC_DIR)/ft_lstadd_front_bonus.c \
				$(SRC_DIR)/ft_lstclear_bonus.c \
				$(SRC_DIR)/ft_lstdelone_bonus.c \
				$(SRC_DIR)/ft_lstiter_bonus.c \
				$(SRC_DIR)/ft_lstlast_bonus.c \
				$(SRC_DIR)/ft_lstmap_bonus.c \
				$(SRC_DIR)/ft_lstnew_bonus.c \
				$(SRC_DIR)/ft_lstsize_bonus.c


BONUS_OBJ = $(BONUS_SRC:.c=.o)



####################
## Rules

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME) $(BONUS)

re: fclean all


####################
## Bonus rules

bonus: 
	@make SRC='$(SRC) $(BONUS_SRC)'
	
#$(BONUS): $(BONUS_OBJ)
#	@ar rcs $(BONUS) $^
#	@ar rcs $(NAME) $^



.PHONY: all clean fclean re bonus

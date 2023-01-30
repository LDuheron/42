NAME = So_long

# compiler
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

# minilibx
MLX_PATH = minilibx-linux/
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)
# include
INC = -I./includes/\ -I./minilibx-linux/

# sources
SRC = test.c
OBJ = $(SRC:.c=.o)

all : $(MLX) $(NAME)

clean :
	rm -rf $(NAME) $(OBJ)

re : clean all

$(MLX) :
	@make -sC $(MLX_PATH)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) $(INC) -lXext -lX11 -lm

%.o : %.c
	$(CC) -o $@ -c $^

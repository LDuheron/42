NAME = So_long

# compiler
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

# minilibx
MLX_PATH = ./utils/minilibx-linux/
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)
# include
INC = -I./includes/\ -I./minilibx-linux/ 
# GNL = -I./includes/\ -I./get_next_line/

# sources
SRC = main.c
SRC += ./utils/gnl/get_next_line.c
SRC += ./utils/gnl/get_next_line_utils.c
SRC += ./utils/PrintF/ft_printf.c
SRC += ./utils/PrintF/print_i_d.c
SRC += ./utils/PrintF/print_u.c
SRC += ./utils/PrintF/printf_utils.c
SRC += ./utils.c
SRC += ./map_verif_format.c
SRC += ./close_game.c
SRC += ./backtracking.c
SRC += ./split.c
SRC += ./ft_itoa.c
SRC += ./map_error.c
SRC += ./game_end.c
SRC += ./place_image.c

OBJ = $(SRC:.c=.o)

all : $(MLX) $(NAME)

$(MLX) :
	@make -sC $(MLX_PATH)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) $(INC) -lXext -lX11 -lm 
	@echo "$$GAME_INIT"

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $^

clean :
	rm -rf $(NAME) $(OBJ)

re : clean all

.PHONY: clean fclean re

.SILENT: 

info : game_init

define GAME_INIT


⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣤⣴⣶⣶⣶⣶⣶⣦⣤⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣶⣿⡿⠿⠛⠛⠋⠉⠉⠉⠉⠉⠙⠛⠻⠿⣿⣷⣦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⠿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⢿⣿⣦⣄⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣠⣾⡿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣄⣀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣷⡄⠀⠀⠀⠀⠀
⠀⠀⠀⢀⣾⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣴⣾⣿⣿⣿⡿⣶⣦⡀⠀⠀⠀⠀⠀⠈⠻⣿⣦⡀⠀⠀⠀
⠀⠀⢠⣿⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⢤⣤⣿⣿⣿⣿⣿⣿⣿⣆⠘⣿⠟⣷⣦⣄⡀⠀⠀⠀⠘⣿⣷⡀⠀⠀
⠀⢠⣿⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⢶⣤⣽⣿⣿⣿⣿⣿⣿⣿⡋⢠⣿⡧⠈⠙⣿⣿⣿⣶⣦⡄⠘⣿⣷⡀⠀
⠀⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⣦⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣴⣯⣩⣿⣿⣿⣿⣦⠘⣿⣧⠀
⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣏⠉⠉⠉⠛⢻⣿⢿⡿⡿⡿⢿⡟⠀⢻⣿⡄
⣾⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢲⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣳⠀⠀⠀⠹⠋⠛⠽⠟⠋⠋⠀⠀⢸⣿⡇
⣿⣿⠀⠀⠀⠀⠀⠀⠀⢀⡀⣦⣪⣿⣿⣿⣿⣿⡿⠹⠹⣿⣿⣿⣿⣷⣓⣴⢀⡀⡀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇
⣿⣿⠀⠀⠀⠀⠀⣤⣳⣶⣿⣿⣿⣿⣿⣿⡏⡿⠃⢀⡀⠈⠉⠛⠻⠿⣿⣷⣽⣟⠷⠶⡄⠀⠀⠀⠀⠀⢸⣿⡇
⢸⣿⡆⣤⣄⣻⣷⣿⣿⣿⣿⣿⣿⡿⣿⡁⠇⠁⠀⢻⡞⠉⠀⠀⠀⠀⠀⠙⠻⠿⠟⠛⠀⠀⠀⠀⠀⠀⣸⣿⠇
⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣾⣄⣠⣠⡴⠿⣣⣿⡵⠧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⡿⠀
⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⣿⠿⣿⣿⣿⣿⣴⡞⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⠃⠀
⠀⠀⠹⣿⣿⣿⣿⣿⣿⢻⠿⣆⠘⠢⡘⠘⠛⠛⠋⠀⠀JURASSIC SWIM ⢀⣼⣿⠃
⠀⠀⠀⠙⣿⣿⣿⡏⠙⢦⣣⠈⠖⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣄⣀⢀⣦⣀⠀⢀⣠⣾⡿⠃⠀⠀⠀
⠀⠀⠀⠀⠈⠻⣿⣧⡀⠀⠉⠣⡀⠀⠀⣠⣤⣀⣠⣤⣐⣴⣷⣅⣤⣦⣟⣿⢿⣸⣿⣿⣾⣿⣿⠟⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠉⠻⣿⣷⣄⣀⣴⣦⣤⣽⣟⣙⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠻⠿⠿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠛⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀

endef
export GAME_INIT

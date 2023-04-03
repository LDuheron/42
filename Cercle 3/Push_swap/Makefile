NAME = push_swap

# SRCS +=	push_swap.c
SRCS += actions_utils.c
SRCS += error_management.c
SRCS += ft_atoi.c
SRCS += list_utils.c
SRCS += main.c
SRCS += position.c
SRCS += push.c
SRCS += push_swap_utils.c
SRCS += rank.c
SRCS += reverse_rotate.c
SRCS += rotate.c
SRCS += sort_five.c
SRCS += swap.c

CFLAGS = -Wall -Werror -Wextra -g3
CC = cc
RM = rm -rf

OBJS = $(SRCS:.c=.o)

### RULES

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT:

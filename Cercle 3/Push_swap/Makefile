NAME = push_swap

# SRCS +=	push_swap.c
SRCS += actions.c
SRCS += list_utils.c
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
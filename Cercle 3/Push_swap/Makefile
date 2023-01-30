NAME = push_swap.a

SRCS +=	push_swap.c

CFLAGS = -Wall -Werror -Wextra
AR = ar -rcs
CC = cc
RM = rm -rf

OBJS = $(SRCS:.c=.o)

### RULES

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
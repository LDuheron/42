NAME = libftprintf.a

SRCS +=	ft_printf.c
SRCS += print_hexa.c
SRCS += print_i_d.c
SRCS += print_p.c
SRCS += print_s.c
SRCS += print_u.c

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

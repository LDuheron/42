NAME = libft.a

SRCS +=	ft_atoi.c
SRCS +=	ft_bzero.c
SRCS +=	ft_calloc.c
SRCS +=	ft_isalnum.c
SRCS +=	ft_isalpha.c
SRCS +=	ft_isascii.c
SRCS +=	ft_isdigit.c
SRCS +=	ft_isprint.c
SRCS +=	ft_memchr.c
SRCS +=	ft_memcmp.c
SRCS +=	ft_memcpy.c
SRCS +=	ft_memmove.c
SRCS +=	ft_memset.c
SRCS +=	ft_putchar_fd.c
SRCS +=	ft_putendl_fd.c
SRCS +=	ft_putnbr_fd.c
SRCS +=	ft_strmapi.c
SRCS +=	ft_strchr.c
SRCS +=	ft_putstr_fd.c
SRCS +=	ft_strdup.c
SRCS +=	ft_striteri.c
SRCS +=	ft_strjoin.c
SRCS +=	ft_strlcat.c
SRCS +=	ft_strlcpy.c
SRCS +=	ft_strlen.c
SRCS +=	ft_strrchr.c
SRCS +=	ft_strncmp.c
SRCS +=	ft_strnstr.c
SRCS +=	ft_strtrim.c
SRCS +=	ft_tolower.c
SRCS +=	ft_toupper.c
SRCS +=	ft_itoa.c
SRCS +=	ft_split.c
SRCS += ft_substr.c

BONUS += ft_lstnew.c
BONUS += ft_lstadd_front.c
BONUS += ft_lstsize.c
BONUS += ft_lstlast.c
BONUS += ft_lstadd_back.c
BONUS += ft_lstiter.c
BONUS += ft_lstdelone.c
BONUS += ft_lstclear.c
BONUS += ft_lstmap.c

CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
CC = cc

ifeq (bonus, $(findstring bonus, $(MAKECMDGOALS)))
  SRCS += $(BONUS)
endif

OBJS = $(SRCS:.c=.o)

### RULES

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c libft.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

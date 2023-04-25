
####### BEGINNING #######

NAME := pipex

####### INGREDIENTS - BUILD VARIABLES #######

SRCS += error_management.c
SRCS += ft_exec.c
SRCS += ft_split.c
SRCS += main.c
SRCS += pipex_utils.c

OBJS	:= $(SRCS:.c=.o)  # object files .o

CC := clang # compiler
CFLAGS := -Wall -Wextra -Werror -g3 # compiler flags

####### USTENSILS - SHELL COMMANDS #######

RM := rm -f # force remove
MAKEFLAGS += --no-print-directory # make flags

####### RECIPES - BUILD EXTRA RULES #######

all: $(NAME) # default goal

$(NAME): $(OBJS) # linking.o -> binary = .a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean: # remove .o
	$(RM) $(OBJS)

fclean : clean #remove.o + binary .a
	$(RM) $(NAME)

re: # remake default goal
	$(MAKE) fclean
	$(MAKE) all

####### SPEC - SPECIAL TARGETS  #######

.PHONY: all clean fclean re

.SILENT:
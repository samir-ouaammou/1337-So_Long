FILES = so_long.c so_long_utils1.c so_long_utils2.c so_long_utils3.c so_long_utils4.c \
        so_long_utils5.c so_long_utils6.c get_next_line.c get_next_line_utils.c

BFILES = so_long_bonus.c so_long_utils1_bonus.c so_long_utils2_bonus.c so_long_utils3_bonus.c \
         so_long_utils4_bonus.c so_long_utils5_bonus.c so_long_utils6_bonus.c so_long_utils7_bonus.c \
         so_long_utils8_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS = $(FILES:.c=.o)
BOBJS = $(BFILES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = -lmlx -lXext -lX11 -lm -lbsd

NAME = so_long
BNAME = so_long_bonus
RM = rm -rf

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	echo "Compiled $(NAME)"

bonus: $(BNAME)

$(BNAME): $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) $(LIBS) -o $(BNAME)
	echo "Compiled $(BNAME)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BOBJS)
	echo "Cleaned object files"

fclean: clean
	$(RM) $(NAME) $(BNAME)
	echo "Cleaned all"

re: fclean all

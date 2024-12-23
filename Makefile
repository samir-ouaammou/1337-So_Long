FILES = so_long.c so_long_utils1.c so_long_utils2.c so_long_utils3.c so_long_utils4.c \
        so_long_utils6.c	get_next_line.c get_next_line_utils.c

OBJS = $(FILES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror 
#-g3 -fsanitize=address

LIBS =  -lmlx -lXext -lX11 -lm -lbsd

NAME = so_long

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
